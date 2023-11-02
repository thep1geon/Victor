# Victor

The Victor game making library is my latest solo project. Written in pure, vanilla
C like the gigachad I am, this is my most ambitious project yet. 

The main inspritation for starting this project was my laziness and not wanting to rewrite all
the SDL boilerplate code. 

```C
#include "include/victor.h"

void display(void) {
    Victor_Event e = Victor_GetEvent();
    Victor_Rectangle r = newVictorRectangle(VEC2(0, 0), 90, 90, CYAN);

    Victor_DrawRectangle(Rect_Param(r));
    Victor_DrawRectangle(e.motion.x - 25, e.motion.y - 25, 50, 50, GHOSTWHITE);
}

int main(void) {
    Victor_Init(420, 420, "Game!");

    Victor_GameLoop(display);
}
```

That is the code to create a square that follows your mouse position. Without using Victor, that
would be around 50 lines of code
