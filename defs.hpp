#ifndef _DEFS_H_
#define _DEFS_H_

#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

struct App{
	SDL_Renderer *renderer;
	SDL_Window *window;
	int up;
	int down;
	int left;
	int right;
	int fire;
}app;

struct Entity{
	int x;
	int y;
	int dx;
	int dy;
	int health;
	SDL_Texture *texture;
} player,bullet;

#endif
