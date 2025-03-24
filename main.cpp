#include <SDL.h>
#include "stb_image.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

#include "./environment.h"
#include "./entity.h"

int main(int argc, char** argv) {
	SDL_Window*  window  = NULL;
	SDL_Surface* surface = NULL;

	window = createWindow();

	SDL_Renderer* s =
		SDL_CreateRenderer(
			window,
			0,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
	if (!s) printf("main.cpp, main(): %s\n", SDL_GetError());

	srand(time(NULL));
	///*
	for (int x = 0; x < 1000; x++) {
		createParticle(
			rand() % WINDOW_W * 0.5 + WINDOW_W * 0.25,
			rand() % WINDOW_H * 0.5 + WINDOW_H * 0.25,
			rand() % 5
		);
	}

	int counter = 0;

	bool RUNNING = true;
	while (RUNNING) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN)
				if ( isKey(event.key, SDLK_q) ) RUNNING = false;
			if (event.type == SDL_QUIT) RUNNING = false;
		}

		updateParticles();
		//printf("%d\n\n", counter++);

		SDL_SetRenderDrawColor(s, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(s);

		renderParticles(s);
		SDL_RenderPresent(s);

		Sleep(100);
	}

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_DestroyRenderer(s);

	SDL_Quit();

	return 0;
}