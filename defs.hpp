#pragma once

#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define MAX_KEYBOARD_KEYS 350

#define PLAYER_SPEED 4
#define PLAYER_BULLET_SPEED 16

#define ENEMY_SPEED -(2 + (rand() % 4))
#define ENEMY_BULLET_SPEED 9
#define ENEMY_HEALTH 4

#define SIDE_PLAYER 0
#define SIDE_ENEMY 1