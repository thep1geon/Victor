#ifndef __VICTOR_MATH_H
#define __VICTOR_MATH_H

#include "Victor_Types.h"

#define PI  3.1415926535897932384262433832795
#define E   2.7182818284590452353602874713527

#define RAD_TO_DEG(r) (r * 180 / PI)
#define DEG_TO_RAD(d) (d * PI / 180)

void Victor_Clamp(i32* num, i32 low, i32 high);
void Victor_Clampf(f32* num, f32 low, f32 high);

#endif  //__VICTOR_MATH_H
