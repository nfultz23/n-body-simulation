#ifndef ENV_H
#define ENV_H

#include <SDL.h>
#include <iostream>
#include <fstream>

const int WINDOW_W = 1080;
const int WINDOW_H = 720;

SDL_Window* createWindow();

SDL_Surface* loadImage(const char* filename);

bool isKey(SDL_KeyboardEvent, SDL_KeyCode);

void drawCircle(SDL_Renderer*, int, int, int);


#endif