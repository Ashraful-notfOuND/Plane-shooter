#pragma once

#include"init.hpp"

struct Entity{
	float x;
	float y;
	int w;
	int h;
	float dx;
	float dy;
	int health;
	int reload;
	int side;
	SDL_Texture *texture;
	Entity *next;
} player,bullet,enemy;

struct Delegate{
    void (*logic)(void);
	void (*draw)(void);
} delegate;

struct Stage{
    Entity fighterHead, *fighterTail;
	Entity bulletHead, *bulletTail;
} stage;
struct App{
	SDL_Renderer *renderer;
	SDL_Window *window;
	Delegate delegate;
	int keyboard[MAX_KEYBOARD_KEYS];
}app;

int enemySpawnTimer;
