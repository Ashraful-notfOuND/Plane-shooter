#include<iostream>
#include<SDL2/SDL.h>

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;


