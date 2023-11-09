#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "include/Victor.h"
#include "include/Victor_Image.h"

// Windowing stuff
static SDL_Window*   window;
static SDL_Renderer* renderer;
static i32 WINDOW_WIDTH, WINDOW_HEIGHT;

// Game loop stuff
static bool quit;
static SDL_Event e;

static u32 FPS;
static u32 frameStart;
static u32 frameTime;
static u32 frameDelay;

static Vector2 lastMousePos = VECTOR2(0, 0);
static Vector2 lastMousePosInWindow = VECTOR2(0, 0);
static Victor_Key lastKey;

// Colors and other misc stuff
static Color backgroundColor;

void Victor_Init(i32 windowWidth_, i32 windowHeight_, const char* windowTitle) {
    if (window != NULL || renderer != NULL) {
        printf("Window already initialized!\n");
        exit(4);
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(windowTitle == NULL ? "Victor Example" : windowTitle, 
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                              windowWidth_, windowHeight_, 
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(2);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(3);
    }

    FPS = 60;

    frameDelay = 1000 /FPS;

    backgroundColor = BLACK;

    WINDOW_HEIGHT = windowHeight_;
    WINDOW_WIDTH = windowWidth_;

    e.motion.x = lastMousePos.x;
    e.motion.y = lastMousePos.y;
}

void Victor_GameLoop(void(*display)(void)) {
    Victor_Event tempEvent = e;

    if (window == NULL || renderer == NULL) {
        printf("Victor not initialized. You must initialize Victor before running the game loop\n");
        exit(5);
    }

    while (!quit) {
        frameStart = SDL_GetTicks();

        lastMousePos.x = e.motion.x;
        lastMousePos.y = e.motion.y;

        while (SDL_PollEvent(&e)) {
            Vector2 newMousePos;
            newMousePos.x = e.motion.x;
            newMousePos.y = e.motion.y;

            switch (e.type) {
                case SDL_QUIT: {
                    quit = true;
                    break;
                }
                case SDL_KEYDOWN: {
                    lastKey.key = e.key.keysym.sym;
                    break;
                }
                case SDL_KEYUP: {
                    lastKey.key = 0;
                    break;
                }
                case SDL_MOUSEMOTION: {
                    if (Victor_IsPosInWindow(newMousePos)) {
                        lastMousePosInWindow = newMousePos;
                    } 
                    break;
                }
            }

            // Store the last value of e
            tempEvent = e;
        }

        // Set the global event varible to the last value of e
        e = tempEvent;

        SDL_SetRenderDrawColor(renderer, ColorParam(backgroundColor));
        SDL_RenderClear(renderer);

        // Call the display function
        display();

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Victor_Quit(i32 exitCode) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(exitCode);
}

bool Victor_IsPosInWindow(Vector2 pos) {
    return (pos.x >= 0 && pos.x < WINDOW_WIDTH && pos.y >= 0 && pos.y < WINDOW_HEIGHT);
}

void Victor_ClampPointToWindow(Vector2* v) {
    Victor_Clampf(&v->x, -1, WINDOW_WIDTH + 1);
    Victor_Clampf(&v->y, -1, WINDOW_HEIGHT + 1);
}

void Victor_ClampXYToWindow(i32* x, i32* y) {
    Victor_Clamp(x, -1, WINDOW_WIDTH + 1);
    Victor_Clamp(y, -1, WINDOW_HEIGHT + 1);
}

// Getters and setters
Victor_Event Victor_GetEvent(void) { return e;}

Vector2 Victor_GetMousePos(void) { 
    if (!Victor_IsPosInWindow(VECTOR2(e.motion.x, e.motion.y))) {
        return lastMousePosInWindow;
    }

    return VECTOR2(e.motion.x, e.motion.y);
}

Vector2 Victor_GetWindowDimensions(void) { return VECTOR2(WINDOW_WIDTH, WINDOW_HEIGHT);}

void Victor_SetBackgroundColor(Color c) { backgroundColor = c;}
void Victor_SetFPS(i32 fps) { if (fps > 0 ) { FPS = fps; } else {FPS = 1;} frameDelay = 1000/FPS; }

/*
    * The Shapes module, responsible for drawing primitive shapes
    * to the screen
    *
    * Better ways to draw something on the screen, in the form of a texture, sprite, or image,
    * are coming later, for now you can draw basics stuff
*/

/* Basic Drawing Functions
 *
 * - Placing individual pixels
 * - Drawing Lines
 */

void Victor_PlacePixel(i32 x, i32 y, Color c) {
    SDL_SetRenderDrawColor(renderer, ColorParam(c));
    Victor_ClampXYToWindow(&x, &y);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Victor_PlacePixelVec(Vector2 pos, Color c) {
    Victor_PlacePixel(pos.x, pos.y, c);
}

void Victor_DrawLine(i32 x1, i32 y1, i32 x2, i32 y2, Color c) {
    Victor_ClampXYToWindow(&x1, &y1);
    Victor_ClampXYToWindow(&x2, &y2);

    SDL_SetRenderDrawColor(renderer, ColorParam(c));
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Victor_DrawLineVec(Vector2 pos1, Vector2 pos2, Color c) {
    Victor_DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, c);
}

/* Rectangles
 *
 * - Scaling Reactangles (I dont know)
 * - Drawing filled Reactangles
 * - Drawing the outline of the rectangle
 */

void Victor_RectangleScale(Victor_Rectangle* rec, f32 scale) {
    rec->height *= scale;
    rec->width *= scale;
}

void Victor_DrawRectangle(i32 x, i32 y, i32 width, i32 height, Color color) {
    SDL_SetRenderDrawColor(renderer, ColorParam(color));

    for (i32 _y = y; _y < y + height; ++_y) {
        for (i32 _x = x; _x < x + width; ++_x) {
            SDL_RenderDrawPoint(renderer, _x, _y);
        }
    }
}

void Victor_DrawRectangleVec(Vector2 pos, Vector2 dim, Color color) {
    Victor_DrawRectangle(pos.x, pos.y, dim.x, dim.y, color);
}

void Victor_DrawRectangleRec(Victor_Rectangle rec) {
    Victor_DrawRectangle(rec.pos.x, rec.pos.y, rec.width, rec.height, rec.color);
}

void Victor_DrawRectangleOutline(i32 x, i32 y, i32 width, i32 height, Color color) {
    Victor_DrawLine(x, y, x+width, y, color);
    Victor_DrawLine(x+width, y, x+width, y+height, color);
    Victor_DrawLine(x+width, y+height, x, y+height, color);
    Victor_DrawLine(x, y+height, x, y, color);
}
void Victor_DrawRectangleOutlineVec(Vector2 pos, Vector2 dim, Color color) {
    Victor_DrawRectangleOutline(pos.x, pos.y, dim.x, dim.y, color);
}
void Victor_DrawRectangleOutlineRec(Victor_Rectangle rec) {
    Victor_DrawRectangleOutline(rec.pos.x, rec.pos.y, rec.width, rec.height, rec.color);
}

/* Circles!
 *
 * - Drawing filled circles
 * - Drawing circles
 */

void Victor_DrawCircle(i32 x, i32 y, f32 radius, Color c) {
    Victor_Clampf(&radius, -1, sqrt((WINDOW_WIDTH/2.0)*(WINDOW_WIDTH/2.0) + (WINDOW_HEIGHT/2.0)*(WINDOW_HEIGHT/2.0)) + 1);

    for (i32 dy =  -radius; dy <= radius; ++dy) {
        i32 dx = sqrt((radius * radius) - (dy * dy));
        Victor_DrawLine(x - dx, y + dy, x + dx, y + dy, c);
    }
}

void Victor_DrawCircleVec(Vector2 pos, f32 radius, Color c) {
    Victor_DrawCircle(pos.x, pos.y, radius, c);
}

void Victor_DrawCircleCircle(Victor_Circle c) {
    Victor_DrawCircle(c.centre.x, c.centre.y, c.radius, c.color);
}

void Victor_DrawCircleOutline(i32 x, i32 y, f32 radius, Color c) {
    Victor_Clampf(&radius, -1, sqrt((WINDOW_WIDTH/2.0)*(WINDOW_WIDTH/2.0) + (WINDOW_HEIGHT/2.0)*(WINDOW_HEIGHT/2.0)) + 1);

    for (i32 dy =  -radius; dy <= radius; ++dy) {
        i32 dx = sqrt((radius * radius) - (dy * dy));
        Victor_PlacePixel(x - dx, y + dy, c);
        Victor_PlacePixel(x + dx, y + dy, c);
    }

    for (i32 dx =  -radius; dx <= radius; ++dx) {
        i32 dy = sqrt((radius * radius) - (dx * dx));
        Victor_PlacePixel(x + dx, y - dy, c);
        Victor_PlacePixel(x + dx, y + dy, c);
    }
}

void Victor_DrawCircleOutlineVec(Vector2 pos, f32 radius, Color c) {
    Victor_DrawCircleOutline(pos.x, pos.y, radius, c);
}

void Victor_DrawCircleOutlineCircle(Victor_Circle c) {
    Victor_DrawCircleOutline(c.centre.x, c.centre.y, c.radius, c.color);
}
/* Triangles
 *
 * sort_points_by_y() is only meant to be used by one function
 * Drawing filled Triangles
 * Drawing the outline of Triangles
 */

void Victor_Shapes_SortPointsByY(i32* x1, i32* y1, i32* x2, i32* y2, i32* x3, i32* y3) {
    if (*y1 > *y2) {
        i32 t = *y1;
        *y1 = *y2;
        *y2 = t;
        t = *x1;
        *x1 = *x2;
        *x2 = t;
    } 
    if (*y2 > *y3) {
        i32 t = *y2;
        *y2 = *y3;
        *y3 = t;
        t = *x2;
        *x2 = *x3;
        *x3 = t;
    } 
    if (*y1 > *y2) {
        i32 t = *y1;
        *y1 = *y2;
        *y2 = t;
        t = *x1;
        *x1 = *x2;
        *x2 = t;
    } 
}

void Victor_DrawTriangle(i32 x1, i32 y1, i32 x2, i32 y2, i32 x3, i32 y3, Color c) {
    // Definitely stole this algorithm from Tsoding :)
    Victor_Shapes_SortPointsByY(&x1, &y1, &x2, &y2, &x3, &y3);
    Victor_ClampXYToWindow(&x1, &y1);
    Victor_ClampXYToWindow(&x2, &y2);
    Victor_ClampXYToWindow(&x3, &y3);

    i32 dx12 = x2 - x1;
    i32 dy12 = y2 - y1;
    i32 dx13 = x3 - x1;
    i32 dy13 = y3 - y1;

    for (i32 y = y1; y <= y2; ++y) {

        i32 s1 = dy12 != 0 ? (y - y1) * dx12/dy12 + x1 : x1;
        i32 s2 = dy13 != 0 ? (y - y1) * dx13/dy13 + x1: x1;
        if (s1 > s2) { i32 t = s1; s1 = s2; s2 = t; }

        for (i32 x = s1; x <= s2; ++x) {
            Victor_PlacePixel(x, y, c);
        }
    }

    i32 dx32 = x2 - x3;
    i32 dy32 = y2 - y3;
    i32 dx31 = x1 - x3;
    i32 dy31 = y1 - y3;

    for (i32 y = y2; y <= y3; ++y) {
        i32 s1 = dy32 != 0 ? (y - y3) * dx32/dy32 + x3 : x3;
        i32 s2 = dy31 != 0 ? (y - y3) * dx31/dy31 + x3: x3;
        if (s1 > s2) { i32 t = s1; s1 = s2; s2 = t; }

        for (i32 x = s1; x <= s2; ++x) {
            Victor_PlacePixel(x, y, c);
        }
    }
}

void Victor_DrawTriangleVec(Vector2 v1, Vector2 v2, Vector2 v3, Color c) {
    Victor_DrawTriangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, c);
}
void Victor_DrawTriangleTri(Victor_Triangle tri) {
    Victor_DrawTriangle(tri.v1.x, tri.v1.y, tri.v2.x, tri.v2.y, tri.v3.x, tri.v3.y, tri.c);
}

void Victor_DrawTriangleOutline(i32 x1, i32 y1, i32 x2, i32 y2, i32 x3, i32 y3, Color c) {
    Victor_DrawLine(x1, y1, x2, y2, c);
    Victor_DrawLine(x2, y2, x3, y3, c);
    Victor_DrawLine(x3, y3, x1, y1, c);
}

void Victor_DrawTriangleOutlineVec(Vector2 v1, Vector2 v2, Vector2 v3, Color c) {
    Victor_DrawLineVec(v1, v2, c);
    Victor_DrawLineVec(v2, v3, c);
    Victor_DrawLineVec(v3, v1, c);
}
void Victor_DrawTriangleOutlineTri(Victor_Triangle tri) {
    Victor_DrawLineVec(tri.v1, tri.v2, tri.c);
    Victor_DrawLineVec(tri.v2, tri.v3, tri.c);
    Victor_DrawLineVec(tri.v3, tri.v1, tri.c);
}

/* Math Module
*  
*  A handful of math related functions that could be used in conjunction
*  with the rest of the library
*/

// Clamp an integer value between a high and a low
void Victor_Clamp(i32* num, i32 low, i32 high) {
    if (*num < low) {*num = low;}
    if (*num >= high) {*num = high;}
}

// Clamp a floating-point number between a high and a low
void Victor_Clampf(f32* num, f32 low, f32 high) {
    if (*num < low) {*num = low;}
    if (*num >= high) {*num = high;}
}

/* Keyboard Module
*  
*  Interacting with the keyboard during the game loop
*
*  Mostly just copying from SDL and renaming to fit my needs
*
*  Many features will be missing from SDL simply because I don't care enough
*  to implement the printscreen key
*/

// Returns the last key pressed
Victor_Key Victor_GetKey() {
    return lastKey;
}

// Returns if the last key pressed is equal to the parameter
bool Victor_IsKeyPressed(Key key) {
    return lastKey.key == key;
}

/* Image Module
*
*  The backbone of everything else relating to images, this 
*  includes sprites and textures
*/

void Victor_Image_ParseLine(char *line, i32 *row, i32 *col, Color *color) {
    char* token = strtok(line, " ");
    i32 i = 0;

    while (i < 5 && token != NULL) {
        switch (i) {
            case 0:
                *row = atoi(token);
                break;
            case 1:
                *col = atoi(token);
                break;
            case 2:
                color->r = atoi(token);
                break;
            case 3:
                color->g = atoi(token);
                break;
            case 4:
                token[strlen(token)-1] = 0; 
                color->b = atoi(token);
                break;
        }

        token = strtok(NULL, " ");
        i++;
    }

}

Victor_Image* Victor_LoadImage(const char* path) {
    Victor_Image* image = (Victor_Image*)malloc(sizeof(Victor_Image));
    if (!image) return NULL;

    image->width = 64;
    image->height = 64;

    image->data = (Color*)malloc((image->width * image->height) * sizeof(Color));
    if (!image->data) {
        free(image);
        fprintf(stderr, "LoadImage: Malloc fail\n");
        return NULL;
    }


    FILE* f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "LoadImage: Failed to open file: %s\n", path);
        free(image->data);
        free(image);
        return NULL;
    }

    char* line = NULL;
    u64 len = 0;
    i64 read;

    i32 row = 0;
    i32 col = 0;
    Color color = COLOR(0,0,0,255);
    while ((read = getline(&line, &len, f)) > 0) {
        Victor_Image_ParseLine(line, &row, &col, &color);
        image->data[row * image->width + col] = color;
    }

    fclose(f);

    return image;
}

void Victor_DrawImage(Victor_Image* image, i32 x, i32 y) {
    for (u32 y_ = 0; y_ < image->height; ++y_) {
        for (u32 x_ = 0; x_ < image->width; ++x_) {
            Color pixelColor = image->data[y_ * image->width + x_];
            Victor_PlacePixel(x_ + x, y_ + y, pixelColor);
        }
    }
}

// Gotta free that memory bro
void Victor_DestroyImage(Victor_Image* image) {
    if (!image) return;

    if (image->data) free(image->data);
    if (image) free(image);
}
