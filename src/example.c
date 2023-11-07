#include "include/Victor.h"
#include <math.h>
#include <stdio.h>

#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 500
const Vector2 CENTRE = VECTOR2(WINDOW_WIDTH/2.0, WINDOW_HEIGHT/2.0);
Victor_Circle c;

void gameLoop(void) {
    Vector2 pos = Victor_GetMousePos();

    f32 dist = sqrtf((CENTRE.x - pos.x) * (CENTRE.x - pos.x) + (CENTRE.y - pos.y) * (CENTRE.y - pos.y));

    c.radius = dist;

    Victor_DrawCircleCircle(c);

    Vector2 thirdPoint = VECTOR2(CENTRE.x, pos.y);
    Victor_DrawTriangle(CENTRE.x, CENTRE.y, pos.x, pos.y, thirdPoint.x, thirdPoint.y, VIOLET);

    Victor_DrawLineVec(CENTRE, pos, RED);
    Victor_DrawLine(CENTRE.x, CENTRE.y, pos.x, CENTRE.y, GREEN);
    Victor_DrawLine(pos.x, CENTRE.y, pos.x, pos.y, BLUE);
}

i32 main(void) {
    c = CIRCLE_VEC(CENTRE, 1, GHOSTWHITE);

    Victor_Init(WINDOW_WIDTH, WINDOW_HEIGHT, "Circles and Triangles!");

    Victor_GameLoop(gameLoop);
}
