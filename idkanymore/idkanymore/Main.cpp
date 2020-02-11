#include "pch.h"
#include "Game.h"
#include "SDL.h"
#undef main

Game *game = nullptr;

int main(int argc, const char * argv[]) {

	const int  FPS = 60;
	const int FrameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("Bruh", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running()) {
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (FrameDelay > frameTime) 
			SDL_Delay(FrameDelay - frameTime);
	}

	game->clean();

	return 0;
}