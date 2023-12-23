#pragma once

static void logic(void);
static void draw(void);
static int  highscoreComparator(const void *a, const void *b);
static void drawHighscores(void);
static void doNameInput(void);
static void drawNameInput(void);
void initHighscoreTable(void);
void initHighscores(void);
void addHighscore(int score);
void saveHighscores(void);
void loadHighscores(void);