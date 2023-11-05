#ifndef __TYPES_H
#define __TYPES_H 

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

// Structs and that sort

// Vectors
typedef struct vec2_t {
    f32 x, y;
} Vector2;
#define VECTOR2(x, y) (Vector2){x, y}

typedef struct vec2i_t {
    i32 x, y;
} Vector2i;
#define VECTOR2i(x, y) (Vector2i){x, y}

typedef struct vec3_t {
    f32 x, y, z;
} Vector3;
#define VECTOR3(x, y, z) (Vector3){x, y, z}

typedef struct vec3i_t {
    i32 x, y, z;
} Vector3i;
#define VECTOR3i(x, y, z) (Vector3i){x, y, z}

typedef struct vec4_t {
    f32 x, y, z, w;
} Vector4;
#define VECTOR4(x, y, z, w) (Vector4){x, y, z, w}

typedef struct vec4i_t {
    i32 x, y, z, w;
} Vector4i;
#define VECTOR4i(x, y, z, w) (Vector4i){x, y, z, w}

#endif //__TYPES_H
