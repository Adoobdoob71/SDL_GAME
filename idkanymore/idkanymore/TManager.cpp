#include "pch.h"
#include "TManager.h"
#include "Game.h"

SDL_Texture* TManager::LoadTexture(const char* filename) {

	SDL_Surface* tempsurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return texture;
}