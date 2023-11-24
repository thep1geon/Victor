#include "include/Victor.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH  1000 
#define WINDOW_HEIGHT 700 
const Vector2 CENTRE = VECTOR2(WINDOW_WIDTH/2.0, WINDOW_HEIGHT/2.0);
Victor_Circle c;

Victor_Image* image;

Color color_from_xy(f32 x, f32 y) {
    u16   r = (x / WINDOW_WIDTH)  * 255; 
    u16   g = (y / WINDOW_HEIGHT) * 255; 
    u16   b = 255 - 256 * (r - g);
    return COLOR(r,g,b, 255);
}

void clean(void) {
    Victor_DestroyImage(&image);
    Victor_DestroyImage(&image);
}

void gameLoop(void) {
    if (Victor_IsKeyPressed('q')) {
        Victor_Quit(0);
    }

    for (i32 y = 0; y < WINDOW_HEIGHT; ++y) {
        for (i32 x = 0; x < WINDOW_WIDTH; ++x) {
            Vector2 pos = VECTOR2(x,y);

            Victor_PlacePixelVec(pos, color_from_xy(pos.x, pos.y));
        }
    }

    Vector2 pos = Victor_GetMousePos();

    f32 dist = sqrtf((CENTRE.x - pos.x) * (CENTRE.x - pos.x) + 
                     (CENTRE.y - pos.y) * (CENTRE.y - pos.y));

    c.radius = dist;
    c.color = color_from_xy(pos.x, pos.y);

    Victor_DrawCircleCircle(c);

    Vector2 thirdPoint = VECTOR2(CENTRE.x, pos.y);
    Victor_DrawTriangle(CENTRE.x, CENTRE.y, pos.x, pos.y, thirdPoint.x, thirdPoint.y, VIOLET);

    Victor_DrawLineVec(CENTRE, pos, RED);
    Victor_DrawLine(CENTRE.x, CENTRE.y, pos.x, CENTRE.y, GREEN);
    Victor_DrawLine(pos.x, CENTRE.y, pos.x, pos.y, BLUE);

    Victor_DrawImage(image, CENTRE.x - image->width/2.0, CENTRE.y - image->height/2.0, 3);

    for (i32 i = 0; i < 5; ++i) {
        Victor_DrawImage(image, rand()%WINDOW_WIDTH, rand()%WINDOW_HEIGHT, rand()%5);
    }
}

i32 main(void) {
    srand(time(NULL));
    image = Victor_LoadImage("./fire.iif");
    if (!image) Victor_Quit(-1);

    c = CIRCLE_VEC(CENTRE, 1, GHOSTWHITE);

    Victor_Init(WINDOW_WIDTH, WINDOW_HEIGHT, "Grand Victor Example!");
    Victor_SetCleanFunc(clean);

    Victor_GameLoop(gameLoop);

    Victor_Quit(0);
}
