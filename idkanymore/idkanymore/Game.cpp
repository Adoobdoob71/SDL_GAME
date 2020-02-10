#include "pch.h"
#include "Game.h"
#include "TManager.h"
#include "GameObject.h"

ObjectVector *ov = new ObjectVector();
SDL_Renderer* Game::renderer = nullptr;

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
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	GameObject *player = new GameObject("C:/heftyskipper.jpg");
	ov->_objectV.push_back(player);

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
	for (GameObject *player : ov->_objectV) {

		switch (ev.key.keysym.sym)
		{
		case SDLK_w:
			player->ypos -= 5;
			printf("HELLO");
			break;
		case SDLK_s:
			player->ypos += 5;
			break;
		case SDLK_d:
			player->xpos += 5;
			break;
		case SDLK_a:
			player->xpos -= 5;
			break;
		default:
			break;
		}
	}
}

void Game::update() {
	ov->update();
}

void Game::render() {

	SDL_RenderClear(renderer);
	ov->render();
	SDL_RenderPresent(renderer);

}

void Game::clean() {
	ov->clean();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game cleaned");

}




