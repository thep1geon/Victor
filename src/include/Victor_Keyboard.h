#ifndef __VICTOR_KEYBOARD_H
#define __VICTOR_KEYBOARD_H

#include "Victor_Types.h"

typedef enum {
    VictorKey_Unknown = 0,

    VictorKey_Return = '\r',
    VictorKey_Escape = '\x1B',
    VictorKey_Backspace = '\b',
    VictorKey_Tab = '\t',
    VictorKey_Space = ' ',
    VictorKey_Exclaim = '!',
    VictorKey_Quotedbl = '"',
    VictorKey_Hash = '#',
    VictorKey_Percent = '%',
    VictorKey_Dollar = '$',
    VictorKey_Ampersand = '&',
    VictorKey_Quote = '\'',
    VictorKey_Leftparen = '(',
    VictorKey_Rightparen = ')',
    VictorKey_Asterisk = '*',
    VictorKey_Plus = '+',
    VictorKey_Comma = ',',
    VictorKey_Minus = '-',
    VictorKey_Period = '.',
    VictorKey_Slash = '/',
    VictorKey_0 = '0',
    VictorKey_1 = '1',
    VictorKey_2 = '2',
    VictorKey_3 = '3',
    VictorKey_4 = '4',
    VictorKey_5 = '5',
    VictorKey_6 = '6',
    VictorKey_7 = '7',
    VictorKey_8 = '8',
    VictorKey_9 = '9',
    VictorKey_Colon = ':',
    VictorKey_Semicolon = ';',
    VictorKey_Less = '<',
    VictorKey_Equals = '=',
    VictorKey_Greater = '>',
    VictorKey_Question = '?',
    VictorKey_At = '@',

    VictorKey_Leftbracket = '[',
    VictorKey_Backslash = '\\',
    VictorKey_Rightbracket = ']',
    VictorKey_Caret = '^',
    VictorKey_Underscore = '_',
    VictorKey_Backquote = '`',
    VictorKey_a = 'a',
    VictorKey_b = 'b',
    VictorKey_c = 'c',
    VictorKey_d = 'd',
    VictorKey_e = 'e',
    VictorKey_f = 'f',
    VictorKey_g = 'g',
    VictorKey_h = 'h',
    VictorKey_i = 'i',
    VictorKey_j = 'j',
    VictorKey_k = 'k',
    VictorKey_l = 'l',
    VictorKey_m = 'm',
    VictorKey_n = 'n',
    VictorKey_o = 'o',
    VictorKey_p = 'p',
    VictorKey_q = 'q',
    VictorKey_r = 'r',
    VictorKey_s = 's',
    VictorKey_t = 't',
    VictorKey_u = 'u',
    VictorKey_v = 'v',
    VictorKey_w = 'w',
    VictorKey_x = 'x',
    VictorKey_y = 'y',
    VictorKey_z = 'z',
} Key;

typedef struct key_t {
    Key key;    
} Victor_Key;
#define KEY(key) (Victor_Key){key}

Victor_Key Victor_GetKey(void);
bool Victor_IsKeyPressed(Key key);

#endif  //__VICTOR_KEYBOARD_H
