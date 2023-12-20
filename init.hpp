#pragma once 

#include"defs.hpp"
#include"structs.hpp"
#include"init.cpp"
#include"draw.cpp"
#include"input.cpp"
#include"stage.cpp"
#include"util.cpp"

void initSDL(void);
void doInput(void);
void prepareScene(void);
void presentScene(void);
void doKeyDown(void);
void doKeyUp(void);
