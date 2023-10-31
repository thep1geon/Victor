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

typedef struct {
    f32 x, y; 
} vec2;

typedef struct {
    i32 x, y; 
} vec2i;

typedef struct {
    f32 x, y, z; 
} vec3;

typedef struct {
    i32 x, y, z; 
} vec3i;

typedef vec2 Point;
#define PointParam(vec2) vec2.x, vec2.y

// Vector Functions
vec2 Vec2(f32 x, f32 y);
bool vec2_equals(vec2 a, vec2 b);
vec2 vec2_dot(vec2 a, vec2 b);
vec2 vec2_sum(vec2 a, vec2 b);
vec2 vec2_sub(vec2 a, vec2 b);
vec2 vec2_scalar_mult(vec2 v, f32 scalar);
f32 vec2_norm(vec2 v);
vec2 vec3_to_vec2(vec3 v);

vec3 Vec3(f32 x, f32 y, f32 z);
vec3 vec3_dot(vec3 a, vec3 b);
vec3 vec3_sum(vec3 a, vec3 b);
vec3 vec3_sub(vec3 a, vec3 b);
vec3 vec3_scalar_mult(vec3 v, f32 scalar);
f32 vec3_norm(vec3 v);
vec3 vec2_to_vec3(vec2 v);

#endif //__TYPES_H
