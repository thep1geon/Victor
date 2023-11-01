#ifndef __SHAPES_H
#define __SHAPES_H

#include <SDL2/SDL.h>

#include "./color.h"
#include "./types.h"

typedef struct Rect_t {
    Vec2  topLeft;
    i32   width, height;
    Color color;
} VictorRect;

VictorRect newRect(Vec2 topLeft, i32 width, i32 height, Color color);
void drawFillRect(SDL_Renderer* renderer, VictorRect rect);

#endif  //__SHAPES_H
