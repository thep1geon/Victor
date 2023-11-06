#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

#include "include/Victor.h"
#include "include/Victor_Color.h"
#include "include/Victor_Shapes.h"
#include "include/Victor_Types.h"

// Windowing stuff
static SDL_Window*   window;
static SDL_Renderer* renderer;
static i32 windowWidth, windowHeight;

// Game loop stuff
static bool quit;
static SDL_Event e;

static u32 FPS;
static u32 frameStart;
static u32 frameTime;
static u32 frameDelay;

// Colors and other misc stuff
static Color currentColor;
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
        exit(2);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(3);
    }

    FPS = 60;

    frameDelay = 1000/FPS;

    currentColor = GHOSTWHITE;
    backgroundColor = BLACK;

    windowHeight = windowHeight_;
    windowWidth = windowWidth_;
}

void Victor_GameLoop(void(*display)(void)) {
    Victor_Event tempEvent = e;

    if (window == NULL || renderer == NULL) {
        printf("Victor not initialized. You must initialize Victor before running the game loop\n");
        exit(5);
    }

    while (!quit) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT: {
                    quit = true;
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

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

bool Victor_IsPosInWindow(Vector2 pos) {
    return (pos.x >= 0 && pos.x < windowWidth && pos.y >= 0 && pos.y < windowHeight);
}

// Getters and setters
Victor_Event Victor_GetEvent(void) { return e;}
Vector2 Victor_GetMousePos(void) { return VECTOR2(e.motion.x, e.motion.y);}
Vector2 Victor_GetWindowDimensions(void) { return VECTOR2(windowWidth, windowHeight);}

void Victor_SetBackgroundColor(Color c) { backgroundColor = c;}
void Victor_SetFPS(i32 fps) { if (fps > 0 ) { FPS = fps; } else {FPS = 1;} frameDelay = 1000/FPS; }

/*
    * The Shapes module, responsible for drawing primitive shapes
    * to the screen
    *
    * Better ways to draw something on the screen, in the form of a texture, sprite, or image,
    * are coming later, for now you can draw basics stuff
*/

// Basic drawing functions

void Victor_PlacePixel(i32 x, i32 y, Color c) {
    SDL_SetRenderDrawColor(renderer, ColorParam(c));
    SDL_RenderDrawPoint(renderer, x, y);
}

void Victor_PlacePixelVec(Vector2i pos, Color c) {
    SDL_SetRenderDrawColor(renderer, ColorParam(c));
    SDL_RenderDrawPoint(renderer, pos.x, pos.y);
}

void Victor_DrawLine(i32 x1, i32 y1, i32 x2, i32 y2, Color c) {
    if (!Victor_IsPosInWindow(VECTOR2(x1, y1))) {return;}
    if (!Victor_IsPosInWindow(VECTOR2(x2, y2))) {return;}

    SDL_SetRenderDrawColor(renderer, ColorParam(c));
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Victor_DrawLineVec(Vector2 pos1, Vector2 pos2, Color c) {
    if (!Victor_IsPosInWindow(pos1)) {return;}
    if (!Victor_IsPosInWindow(pos2)) {return;}

    SDL_SetRenderDrawColor(renderer, ColorParam(c));
    SDL_RenderDrawLine(renderer, pos1.x, pos1.y, pos2.x, pos2.y);
}

// Reactangle related functions

void Victor_DrawRectangle(i32 x, i32 y, i32 width, i32 height, Color color) {
    SDL_SetRenderDrawColor(renderer, ColorParam(color));

    for (i32 _y = y; _y < y + height; ++_y) {
        for (i32 _x = x; _x < x + width; ++_x) {
            SDL_RenderDrawPoint(renderer, _x, _y);
        }
    }
}

void Victor_DrawRectangleVec(Vector2 pos, Vector2 dim, Color color) {
    SDL_SetRenderDrawColor(renderer, ColorParam(color));

    for (i32 _y = pos.y; _y < pos.y + dim.y; ++_y) {
        for (i32 _x = pos.x; _x < pos.x + dim.x; ++_x) {
            SDL_RenderDrawPoint(renderer, _x, _y);
        }
    }
}

void Victor_DrawRectangleRec(Victor_Rectangle rec) {
    SDL_SetRenderDrawColor(renderer, ColorParam(rec.color));

    for (i32 y = rec.pos.y; y < rec.pos.y + rec.height; ++y) {
        for (i32 x = rec.pos.x; x < rec.pos.x + rec.width; ++x) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

}

// Yay! Circles
void Victor_DrawCircle(i32 x, i32 y, f32 radius, Color c) {
    if (radius / 2 > windowHeight || radius / 2 > windowWidth) {return;}
    SDL_SetRenderDrawColor(renderer, ColorParam(c));

    for (i32 y_ = -radius; y_ <= radius; ++y_) {
        for (i32 x_ = -radius; x_ <= radius; ++x_) {
            if (x_ * x_ + y_ * y_ <= radius * radius) {
                SDL_RenderDrawPoint(renderer, x_ + x, y_ + y);
            }
        }
    }
}

void Victor_DrawCircleVec(Vector2 pos, f32 radius, Color c) {
    if (radius / 2 > windowHeight || radius / 2 > windowWidth) {return;}
    SDL_SetRenderDrawColor(renderer, ColorParam(c));

    for (i32 y_ = -radius; y_ <= radius; ++y_) {
        for (i32 x_ = -radius; x_ <= radius; ++x_) {
            if (x_ * x_ + y_ * y_ <= radius * radius) {
                SDL_RenderDrawPoint(renderer, x_ + pos.x, y_ + pos.y);
            }
        }
    }
}

void Victor_DrawCircleCircle(Victor_Circle c) {
    if (c.radius / 2 > windowHeight || c.radius / 2 > windowWidth) {return;}
    SDL_SetRenderDrawColor(renderer, ColorParam(c.color));

    for (i32 y_ = -c.radius; y_ <= c.radius; ++y_) {
        for (i32 x_ = -c.radius; x_ <= c.radius; ++x_) {
            if (x_ * x_ + y_ * y_ <= c.radius * c.radius) {
                SDL_RenderDrawPoint(renderer, x_ + c.centre.x, y_ + c.centre.y);
            }
        }
    }

}
