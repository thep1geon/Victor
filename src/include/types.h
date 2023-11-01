#ifndef __TYPES_H
#define __TYPES_H 

#include <math.h>
#include <stdint.h>

// integer types
typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;

typedef int8_t    i8;
typedef int16_t   i16;
typedef int32_t   i32;
typedef int64_t   i64;

// Float types
typedef float     f32;
typedef double    f64;

// Boolean stuff
#ifndef __cplusplus
typedef int       bool;
#define true      1
#define false     0
#endif

// Vector types

#define Vec2Param(vec) vec.x, vec.y

// 2D vector of floats
typedef struct {
    f32 x, y; 
} Vec2;

#endif //__TYPES_H
