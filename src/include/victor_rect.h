#ifndef __SHAPES_H
#define __SHAPES_H

#include <SDL2/SDL.h>

#include "./color.h"
#include "./types.h"
#include "./vec.h"


typedef struct rect_t {
    Vec2  pos;
    i32   width, height;
    Color color;
} Victor_Rectangle;

#define Rect_Param(r) r.pos.x, r.pos.y, r.width, r.height, r.color

Victor_Rectangle newVictorRectangle(Vec2 pos, i32 width, i32 height, Color color);
void drawFillVictorRectangle(SDL_Renderer* renderer, Victor_Rectangle rect);

#endif  //__SHAPES_H
