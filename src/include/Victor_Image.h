#ifndef __VICTOR_IMAGE_H
#define __VICTOR_IMAGE_H

/* Image Module
*
*  The backbone of everything else relating to images, this 
*  includes sprites and textures
*
*  The funny part is, for now, the Victor_Image module only supports the .iif
*  format. The .iif format is a custom format used by my Python-Paint project for
*  easily storing your drawings. I really don't want to have to parse complex image
*  formats, at least right now, so if you want to use the Victor_Image module, you're
*  gonna have to download Python-Paint to make the images
*/

#include "Victor_Types.h"
#include "Victor_Color.h"

typedef struct image_t {
    Color* data; // Saves 1 byte of memory since we don't care about alpha
    u32 width;
    u32 height;
} Victor_Image;

void Victor_Image_ParseLine(char* line, i32* row, i32* col, Color* color);

Victor_Image* Victor_LoadImage(const char* path);
void Victor_DrawImage(Victor_Image* image, i32 x, i32 y, f32 scale);

void Victor_DestroyImage(Victor_Image** image);

#endif  //__VICTOR_IMAGE_H
