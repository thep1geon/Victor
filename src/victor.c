#include <SDL2/SDL.h>
#include <stdio.h>

#include "include/types.h"
#include "include/victor_rect.h"
#include "include/victor.h"
#include "include/color.h"

// Windowing stuff
static SDL_Window*   window;
static SDL_Renderer* renderer;

// Game loop stuff
static bool quit;
static SDL_Event e;

static u32 FPS;
static u32 frameStart;
static u32 frameTime;
static u32 frameDelay;

// Colors and other misc stuff
static Color currentColor;
static Color backgroundColor;

void Victor_Init(i32 windowWidth, i32 windowHeight, const char* windowTitle) {
    if (window != NULL || renderer != NULL) {
        printf("Window already initialized!\n");
        exit(4);
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(windowTitle == NULL ? "Victor Example" : windowTitle, 
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                              windowWidth, windowHeight, 
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(2);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(3);
    }

    FPS = 60;

    frameDelay = 1000/FPS;

    currentColor = GHOSTWHITE;
    backgroundColor = BLACK;
}

void Victor_GameLoop(void(*display)(void)) {
    Victor_Event tempEvent = e;

    if (window == NULL || renderer == NULL) {
        printf("Victor not initialized. You must initialize Victor before running the game loop\n");
        exit(5);
    }

    while (!quit) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT: {
                    quit = true;
                    break;
                }
            }

            // Store the last value of e
            tempEvent = e;
        }

        // Set the global event varible to the last value of e
        e = tempEvent;

        SDL_SetRenderDrawColor(renderer, ColorParam(backgroundColor));
        SDL_RenderClear(renderer);
        // Start Drawing

        display();

        // End Drawing
        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

// Getters and setters
Victor_Event Victor_GetEvent(void) { return e;}
void Victor_SetBackgroundColor(Color c) { backgroundColor = c;}
void Victor_SetFPS(i32 fps) { FPS = fps; frameDelay = 1000/FPS;}

// Drawing stuff!
void Victor_DrawRectangle(i32 x, i32 y, i32 width, i32 height, Color color) {
    Victor_Rectangle r = newVictorRectangle((Vec2){x,y}, width, height, color);
    drawFillVictorRectangle(renderer, r);
}
