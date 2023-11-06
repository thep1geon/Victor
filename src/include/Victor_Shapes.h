#ifndef __VICTOR_SHAPES_H
#define __VICTOR_SHAPES_H

/* 
* The shapes module, responsible for drawing primitive shapes to the screen.
* Better ways to draw stuff to the screen are coming soon
*/


#include "Victor_Types.h"
#include "Victor_Color.h"

// Basic drawing functions
void Victor_PlacePixel(i32 x, i32 y, Color c);
void Victor_PlacePixelVec(Vector2 pos, Color c);

void Victor_DrawLine(i32 x1, i32 y1, i32 x2, i32 y2, Color c);
void Victor_DrawLineVec(Vector2 pos1, Vector2 pos2, Color c);

// Rectanles and associated functions

typedef struct rect_t {
    Vector2  pos;
    i32   width, height;
    Color color;
} Victor_Rectangle;
#define RECTANGLE(x, y, w, h, c) (Victor_Rectangle){VECTOR2((x), (y)), (w), (h), (c)};
#define RECTANGLE_VEC(pos, w, h, c) (Victor_Rectangle){pos, (w), (h), (c)};

#define Rect_Param(r) r.pos.x, r.pos.y, r.width, r.height, r.color

void Victor_DrawRectangle(i32 x, i32 y, i32 width, i32 height, Color color);
void Victor_DrawRectangleVec(Vector2 pos, Vector2 dim, Color color);
void Victor_DrawRectangleRec(Victor_Rectangle rec);

void Victor_DrawRectangleOutline(i32 x, i32 y, i32 width, i32 height, Color color);
void Victor_DrawRectangleOutlineVec(Vector2 pos, Vector2 dim, Color color);
void Victor_DrawRectangleOutlineRec(Victor_Rectangle rec);

// Circles and associated functions
typedef struct circle_t {
    Vector2 centre;
    f32 radius;
    Color color;
} Victor_Circle;
#define CIRCLE(x, y, r, c) (Victor_Circle){VECTOR2((x),(y)), (r), (c)};
#define CIRCLE_VEC(pos, r, c) (Victor_Circle){pos, (r), (c)};

void Victor_DrawCircle(i32 x, i32 y, f32 radius, Color c);
void Victor_DrawCircleVec(Vector2 pos, f32 radius, Color c);
void Victor_DrawCircleCircle(Victor_Circle c);

#endif  //__VICTOR_SHAPES_H
