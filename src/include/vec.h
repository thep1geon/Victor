#ifndef __VEC_H
#define __VEC_H

#include "types.h"

// Vector types

#define Vec2Param(vec) vec.x, vec.y

// 2D vector of floats
typedef struct {
    f32 x, y; 
} Vec2;

#define VEC2(x, y) (Vec2){(x), (y)}

#endif //__VEC_H
