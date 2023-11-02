#include "include/victor.h"

void display(void) {
    Victor_Event e = Victor_GetEvent();
    Victor_Rectangle r = newVictorRectangle(VEC2(0, 0), 90, 90, CYAN);

    Victor_DrawRectangle(Rect_Param(r));
    Victor_DrawRectangle(e.motion.x - 25, e.motion.y - 25, 50, 50, GHOSTWHITE);
}

i32 main(void) {
    Victor_Init(420, 420, "Game!");

    Victor_GameLoop(display);
}
