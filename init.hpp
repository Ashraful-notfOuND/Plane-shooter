#ifndef _INIT_H_
#define _INIT_H_

#include"defs.hpp"
#include"structs.hpp"
#include"init.cpp"
#include"draw.cpp"
#include"input.cpp"
#include"stage.cpp"

void initSDL(void);
void doInput(void);
void prepareScene(void);
void presentScene(void);
void doKeyDown(void);
void doKeyUp(void);

#endif