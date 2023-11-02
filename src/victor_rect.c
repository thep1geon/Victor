#include "include/victor_rect.h"
#include "include/color.h"
#include "include/types.h"
#include <SDL2/SDL_render.h>

//  Rectangle Stuff
Victor_Rectangle newVictorRectangle(Vec2 pos, i32 width, i32 height, Color color) {
    return (Victor_Rectangle) {.pos = pos, .width = width, .height = height, .color = color}; 
}

void drawFillVictorRectangle(SDL_Renderer *renderer, Victor_Rectangle rect) {
    SDL_SetRenderDrawColor(renderer, ColorParam(rect.color));

    for (i32 y = rect.pos.y; y < rect.pos.y + rect.height; ++y) {
        for (i32 x = rect.pos.x; x < rect.pos.x + rect.width; ++x) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

