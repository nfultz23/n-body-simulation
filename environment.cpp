#include <SDL.h>
#include "stb_image.h"
#include <iostream>
#include <fstream>

#include "./environment.h"

SDL_Window* createWindow() {
	SDL_Window* window;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("environment.cpp, createWindow(): %s\n", SDL_GetError());
		exit(1);
	}

	window = SDL_CreateWindow(
		"N-Body Simulation",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_W,
		WINDOW_H,
		SDL_WINDOW_SHOWN
	);

	if (!window) {
		printf("environment.cpp, createWindow(): %s\n", SDL_GetError());
		exit(1);
	}

	return window;
}

SDL_Surface* loadImage(const char* filename) {

	int width, height, bytesPerPixel;
	void* data = stbi_load(filename, &width, &height, &bytesPerPixel, 0);

	int pitch;
	pitch = width * bytesPerPixel;
	pitch = (pitch + 3) & ~3;

	int32_t Rmask, Gmask, Bmask, Amask;
	#if SDL_BYTEORDER == SDL_LIL_ENDIAN
		Rmask = 0x000000FF;
		Gmask = 0x0000FF00;
		Bmask = 0x00FF0000;
		Amask = (bytesPerPixel == 4) ? 0xFF000000 : 0;
	#else
		Rmask = 0xFF000000 >> s;
		Gmask = 0x00FF0000 >> s;
		Bmask = 0x0000FF00 >> s;
		Amask = 0x000000FF >> s;
	#endif

	SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
		data, width, height,
		bytesPerPixel * 8,
		pitch,
		Rmask, Gmask, Bmask, Amask);

	if (!surface) {
		printf("environment.cpp, loadImage(): %s\n", SDL_GetError());
		exit(1);
	}

	return surface;
}

bool isKey(SDL_KeyboardEvent pressed, SDL_KeyCode reference) {
	return pressed.keysym.sym == reference;
}

void drawCircle(SDL_Renderer* renderer, int centX, int centY, int r) {
	const int diameter = r * 2;

	int x = r - 1;
	int y = 0;
	int tx = 1;
	int ty = 1;
	int err = tx - diameter;

	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);

	while (x >= y) {
		// Draw horizontal lines to fill the circle
		SDL_RenderDrawLine(renderer, centX - x, centY - y, centX + x, centY - y);
		SDL_RenderDrawLine(renderer, centX - x, centY + y, centX + x, centY + y);
		SDL_RenderDrawLine(renderer, centX - y, centY - x, centX + y, centY - x);
		SDL_RenderDrawLine(renderer, centX - y, centY + x, centX + y, centY + x);

		if (err <= 0) {
			y++;
			err += ty;
			ty += 2;
		}

		if (err > 0) {
			--x;
			tx += 2;
			err += (tx - diameter);
		}
	}

	return;
}