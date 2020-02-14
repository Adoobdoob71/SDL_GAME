#include "pch.h"
#include "Game.h"
#include "TManager.h"
#include "GameObject.h"
#include "ObjectVector.h"
#include "Ball.h"

ObjectVector *ov = new ObjectVector();
SDL_Renderer *Game::renderer = nullptr;
int WIDTH = 0, HEIGHT = 0;
Ball *ball = nullptr;

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
		WIDTH = width;
		HEIGHT = height;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			printf("Window Created!");
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		}
		isRunning = true;
	}
	GameObject *player = new GameObject("C:/heftyskipper.jpg", GameObject::ID::Player);
	player->xpos = 420;
	player->ypos = 500;
	ov->_objectV.push_back(player);
	ball = new Ball("C:/heftyskipper.jpg", ov);
}

void Game::handleEvents() {
	SDL_Event ev;
	SDL_PollEvent(&ev);
	switch (ev.type)
	{
	case SDL_QUIT:
		printf("Quit");
		isRunning = false;
		break;
	default:
		break;
	}
	for (GameObject *player : ov->_objectV)
		if (player->ID == GameObject::ID::Player)
			player->Movement(ev, WIDTH, HEIGHT);
	
}
void Game::update() {
	ov->update();
	ball->Update(WIDTH, HEIGHT);
}

void Game::render() {
	SDL_RenderClear(renderer);
	ov->render();
	ball->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	delete ov;
	delete ball;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game cleaned");
}




