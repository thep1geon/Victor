#include "include/victor.h"

void display(void) {
    VictorEvent e = Victor_GetEvent();

    Victor_DrawRectangle(e.motion.x, e.motion.y, 50, 50, GHOSTWHITE);
}

int main(void) {
    Victor_Init(420, 420, "Game!");

    Victor_GameLoop(display);
}
