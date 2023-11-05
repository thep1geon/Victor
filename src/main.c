#include "include/Victor.h"
#include "include/Victor_Color.h"
#include "include/Victor_Types.h"

#include <math.h>
#include <stdio.h>

#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 500
#define CENTRE        VECTOR2(WINDOW_WIDTH/2.0, WINDOW_HEIGHT/2.0)

void gameLoop(void) {
    Vector2 pos = Victor_GetMousePos();

    Victor_DrawLineVec(CENTRE, pos, RED);
    Victor_DrawLine(CENTRE.x, CENTRE.y, pos.x, CENTRE.y, GREEN);
    Victor_DrawLine(pos.x, CENTRE.y, pos.x, pos.y, BLUE);
}

i32 main(void) {
    Victor_Init(WINDOW_WIDTH, WINDOW_HEIGHT, "Game!");

    Victor_GameLoop(gameLoop);
}
