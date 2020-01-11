#include "pch.h"
#include "Game.h"
#include "TManager.h"
#include "GameObject.h"


GameObject* player;


Game::Game() {
						
}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);
		width = DM.w;
		height = DM.h;
		flags = SDL_WINDOW_FULLSCREEN;

	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		printf("System Initialized!");
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			printf("Window Created!");
		r = SDL_CreateRenderer(window, -1, 0);
		if (r) {
			SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	
	player = new GameObject("C:/heftyskipper.jpg", r);

	
}

void Game::handleEvents() {

	SDL_Event ev;
	SDL_PollEvent(&ev);
	switch (ev.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;

	}


}

void Game::update() {

	player->Update();

}

void Game::render() {

	SDL_RenderClear(r);
	player->Render();
	SDL_RenderPresent(r);

}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(r);
	SDL_Quit();
	printf("Game cleaned");

}




