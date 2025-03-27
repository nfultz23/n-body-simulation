#include <SDL.h>
#include "stb_image.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <vector>

#include "./environment.h"
#include "./entity.h"
#include "./tests.h"

int testFeatures();

int main(int argc, char** argv) {
	printf("Start in test mode? (y/n) ?> ");
	std::string resp;
	std::cin >> resp;

	while (resp != "n" && resp != "y") {
		printf(" Option not recognized, please enter (y/n) ?> ");
		std::cin >> resp;
	}

	if (resp == "n") printf("Starting simulation...\n");
	else if (resp == "y") {
		testFeatures();
		return 0;
	}

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
	/*
	for (int x = 0; x < 1000; x++) {
		createParticle(
			rand() % WINDOW_W * 0.5 + WINDOW_W * 0.25,
			rand() % WINDOW_H * 0.5 + WINDOW_H * 0.25,
			rand() % 5
		);
	}//*/
	createParticle(300, 300, 0);
	createParticle(300, 320, 1);
	createParticle(320, 350, 2);
	createParticle(350, 300, 3);

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

int testFeatures() {
	std::vector<std::string> testables;
	testables.push_back("Tile Class");
	testables.push_back("Quadtree node Class");

	printf("\nPlease input the item to test from the list below:\n");
	for (int x = 0; x < testables.size(); x++)
		std::cout << x << " - " << testables[x] << std::endl;
	printf("\n");

	int item = -1;
	std::cout << "?> ";
	std::cin >> item;
	while (item < 0 || item >= testables.size()) {
		printf("Please provide a valid option\n");
		std::cout << "?> ";
		std::cin >> item;
	}

	int res = 0;
	if (item == 0) res = testTileClass();
	if (item == 1) res = testQuadNode();

	std::cout << std::endl;
	std::cout << "Test again? (y/n) ?> ";
	std::string in;
	std::cin >> in;
	while (in != "n" && in != "y") {
		std::cout << "Please enter y or n ?> ";
		std::cin >> in;
	}

	if (in == "y") {
		testFeatures();
	}

	return 0;
}