# Victor

The Victor game making library is my latest solo project. Written in pure, vanilla
C like the gigachad I am, this is my most ambitious project yet. 

The main inspritation for starting this project was my laziness and not wanting to rewrite all
the SDL boilerplate code. 

```c
#include "include/Victor.h"

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
```

That is the code to create a triangle stuck at the centre of the window
where each side is a different color
