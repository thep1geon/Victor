#ifndef __VICTOR_H
#define __VICTOR_H

#include "types.h"
#include "color.h"
#include <SDL2/SDL.h>

typedef SDL_Event VictorEvent;

// Game stuff
void Victor_Init(i32 windowWidth, i32 windowHeight, const char* windowTitle);
void Victor_GameLoop(void(*display)(void));

// Getting and setting global variables
VictorEvent Victor_GetEvent(void);

void Victor_SetFPS(i32 fps);
void Victor_SetBackgroundColor(Color c);

// Drawing Stuff!
void Victor_DrawRectangle(i32 x, i32 y, i32 width, i32 height, Color color);

#endif  //__VICTOR_H
