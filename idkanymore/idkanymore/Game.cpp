#include "pch.h"
#include "Game.h"
#include "TManager.h"
#include "GameObject.h"
#include "ObjectVector.h"
#include "Ball.h"
#include "BlobSpawner.h"
#include "Blob.h"

BlobSpawner *bs = new BlobSpawner();
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
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		WIDTH = width;
		HEIGHT = height;
		printf("System Initialized!");
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
	player->xpos = 300;
	player->ypos = 450;
	player->destR.h = 30;
	player->destR.w = 150;
	ov->_objectV.push_back(player);
	int bx = 1;
	for (int i = 0; i < 3; i++) {
		Blob* a = new Blob("C:/EM.png");
		a->xpos = bx * 45;
		a->ypos = 100;
		bx += 2;
		bs->blob_vector.push_back(a);
	}

	ball = new Ball("C:/heftyskipper.jpg", ov, bs);
	ball->xpos = 300;
	ball->ypos = 500;
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
			player->Movement(ev, WIDTH, HEIGHT);
	
}
void Game::update() {
	ov->update();
	ball->Update(WIDTH, HEIGHT);
	bs->update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	ov->render();
	ball->Render();
	bs->render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	delete ov;
	delete ball;
	delete bs;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game cleaned");
}




