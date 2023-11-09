#ifndef __COLOR_H
#define __COLOR_H

#include "Victor_Types.h"
typedef struct color_t {
    u8 r, g, b, a;
} Color;
#define COLOR(r, g, b, a) (Color){r, g, b, a}

typedef struct color_rbg_t {
    u8 r, g, b;
} Color_RGB;
#define COLOR_RGB(r, g, b) (Color_RGB){r, g, b}

#define ALICEBLUE            (Color){240, 248, 255, 255}
#define ANTIQUEWHITE         (Color){250, 235, 215, 255}
#define AQUA                 (Color){0,   255, 255, 255}
#define AQUAMARINE           (Color){127, 255, 212, 255}
#define AZURE                (Color){240, 255, 255, 255}
#define BEIGE                (Color){245, 245, 220, 255}
#define BISQUE               (Color){255, 228, 196, 255}
#define BLACK                (Color){0,   0,   0,   255}
#define BLUE                 (Color){0,   0,   255, 255}
#define BLUEVIOLET           (Color){138, 43,  226, 255}
#define BROWN                (Color){139, 69,  19,  255}
#define BURLYWOOD            (Color){222, 184, 135, 255}
#define CADETBLUE            (Color){95,  158, 160, 255}
#define CHARTREUSE           (Color){127, 255, 0,   255}
#define CHOCOLATE            (Color){210, 105, 30,  255}
#define CORAL                (Color){255, 127, 80,  255}
#define CORNFLOWERBLUE       (Color){100, 149, 237, 255}
#define CORNSILK             (Color){255, 248, 220, 255}
#define CRIMSON              (Color){220, 20,  60,  255}
#define CYAN                 (Color){0,   255, 255, 255}
#define DARKGOLDENROD        (Color){184, 134, 11,  255}
#define DARKGRAY             (Color){169, 169, 169, 255}
#define DARKGREEN            (Color){0,   100, 0,   255}
#define DARKKHAKI            (Color){189, 183, 107, 255}
#define DARKOLIVEGREEN       (Color){85,  107, 47,  255}
#define DARKORANGE           (Color){255, 140, 0,   255}
#define DARKORCHID           (Color){153, 50,  204, 255}
#define DARKRED              (Color){139, 0,   0,   255}
#define DARKSALMON           (Color){233, 150, 122, 255}
#define DARKSEAGREEN         (Color){143, 188, 143, 255}
#define DARKSLATEBLUE        (Color){72,  61,  139, 255}
#define DARKSLATEGRAY        (Color){47,  79,  79,  255}
#define DARKTURQUOISE        (Color){0,   206, 209, 255}
#define DARKVIOLET           (Color){148, 0,   211, 255}
#define DEEPPINK             (Color){255, 20,  147, 255}
#define DEEPSKYBLUE          (Color){0,   191, 255, 255}
#define DIMGRAY              (Color){105, 105, 105, 255}
#define DODGERBLUE           (Color){30,  144, 255, 255}
#define FIREBRICK            (Color){178, 34,  34,  255}
#define FLORALWHITE          (Color){255, 250, 240, 255}
#define FORESTGREEN          (Color){34,  139, 34,  255}
#define GAINSBORO            (Color){220, 220, 220, 255}
#define GHOSTWHITE           (Color){248, 248, 255, 255}
#define GOLD                 (Color){255, 215, 0,   255}
#define GOLDENROD            (Color){218, 165, 32,  255}
#define GRAY                 (Color){128, 128, 128, 255}
#define GREEN                (Color){0,   255, 0,   255}
#define GREENYELLOW          (Color){173, 255, 47,  255}
#define HONEYDEW             (Color){240, 255, 240, 255}
#define HOTPINK              (Color){255, 105, 180, 255}
#define INDIANRED            (Color){205, 92,  92,  255}
#define INDIGO               (Color){75,  0,   130, 255}
#define IVORY                (Color){255, 255, 240, 255}
#define KHAKI                (Color){240, 230, 140, 255}
#define LAVENDER             (Color){230, 230, 250, 255}
#define LAWNGREEN            (Color){124, 252, 0,   255}
#define LEMONCHIFFON         (Color){255, 250, 205, 255}
#define LIGHTBLUE            (Color){173, 216, 230, 255}
#define LIGHTCORAL           (Color){240, 128, 128, 255}
#define LIGHTCYAN            (Color){224, 255, 255, 255}
#define LIGHTGOLDENRODYELLOW (Color){250, 250, 210, 255}
#define LIGHTGRAY            (Color){211, 211, 211, 255}
#define LIGHTGREEN           (Color){144, 238, 144, 255}
#define LIGHTPINK            (Color){255, 182, 193, 255}
#define LIGHTSALMON          (Color){255, 160, 122, 255}
#define LIGHTSEAGREEN        (Color){32,  178, 170, 255}
#define LIGHTSKYBLUE         (Color){135, 206, 250, 255}
#define LIGHTSLATEGRAY       (Color){119, 136, 153, 255}
#define LIGHTSTEELBLUE       (Color){176, 196, 222, 255}
#define LIGHTYELLOW          (Color){255, 255, 224, 255}
#define LIME                 (Color){50,  205, 50,  255}
#define LINEN                (Color){250, 240, 230, 255}
#define MAGENTA              (Color){255, 0,   255, 255}
#define MAROON               (Color){128, 0,   0,   255}
#define MEDIUMAQUAMARINE     (Color){102, 205, 170, 255}
#define MEDIUMBLUE           (Color){0,   0,   205, 255}
#define MEDIUMORCHID         (Color){186, 85,  211, 255}
#define MEDIUMPURPLE         (Color){147, 112, 219, 255}
#define MEDIUMSEAGREEN       (Color){60,  179, 113, 255}
#define MEDIUMSLATEBLUE      (Color){123, 104, 238, 255}
#define MEDIUMSPRINGGREEN    (Color){0,   250, 154, 255}
#define MEDIUMTURQUOISE      (Color){72,  209, 204, 255}
#define MEDIUMVIOLETRED      (Color){199, 21,  133, 255}
#define MIDNIGHTBLUE         (Color){25,  25,  112, 255}
#define MINTCREAM            (Color){245, 255, 250, 255}
#define MINT                 (Color){189, 252, 201, 255}
#define MISTYROSE            (Color){255, 228, 225, 255}
#define MOCCASIN             (Color){255, 228, 181, 255}
#define NAVAJOWHITE          (Color){255, 222, 173, 255}
#define NAVY                 (Color){0,   0,   128, 255}
#define OLIVE                (Color){128, 128, 0,   255}
#define OLIVEDRAB            (Color){107, 142, 35,  255}
#define ORANGE               (Color){255, 165, 0,   255}
#define ORANGERED            (Color){255, 69,  0,   255}
#define ORCHID               (Color){218, 112, 214, 255}
#define PALEGOLDENROD        (Color){238, 232, 170, 255}
#define PALEGREEN            (Color){152, 251, 152, 255}
#define PALETURQUOISE        (Color){175, 238, 238, 255}
#define PALEVIOLETRED        (Color){219, 112, 147, 255}
#define PAPAYAWHIP           (Color){255, 239, 213, 255}
#define PEACHPUFF            (Color){255, 218, 185, 255}
#define PERU                 (Color){205, 133, 63,  255}
#define PINK                 (Color){255, 192, 203, 255}
#define PLUM                 (Color){221, 160, 221, 255}
#define POWDERBLUE           (Color){176, 224, 230, 255}
#define PURPLE               (Color){255, 0,   255, 255}
#define RED                  (Color){255, 0,   0,   255}
#define ROSYBROWN            (Color){188, 143, 143, 255}
#define ROYALBLUE            (Color){65,  105, 225, 255}
#define SADDLEBROWN          (Color){139, 69,  19,  255}
#define SALMON               (Color){250, 128, 114, 255}
#define SANDYBROWN           (Color){244, 164, 96,  255}
#define SEAGREEN             (Color){46,  139, 87,  255}
#define SEASHELL             (Color){255, 245, 238, 255}
#define SIENNA               (Color){160, 82,  45,  255}
#define SILVER               (Color){192, 192, 192, 255}
#define SKYBLUE              (Color){135, 206, 235, 255}
#define SLATEBLUE            (Color){106, 90,  205, 255}
#define SLATEGRAY            (Color){112, 128, 144, 255}
#define SNOW                 (Color){255, 250, 250, 255}
#define SPRINGGREEN          (Color){0,   255, 127, 255}
#define STEELBLUE            (Color){70,  130, 180, 255}
#define TAN                  (Color){210, 180, 140, 255}
#define THISTLE              (Color){216, 191, 216, 255}
#define TOMATO               (Color){255, 99,  71,  255}
#define TURQUOISE            (Color){64,  224, 208, 255}
#define VIOLET               (Color){238, 130, 238, 255}
#define WHEAT                (Color){245, 222, 179, 255}
#define WHITESMOKE           (Color){245, 245, 245, 255}
#define YELLOW               (Color){255, 255, 0,   255}
#define YELLOWGREEN          (Color){154, 205, 50,  255}

#define ColorParam(Color) Color.r, Color.g, Color.b, Color.a

#endif  //__COLOR_H
