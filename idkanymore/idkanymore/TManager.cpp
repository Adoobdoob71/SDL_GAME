#include "pch.h"
#include "TManager.h"

SDL_Texture* TManager::LoadTexture(const char* filename, SDL_Renderer* renderer) {

	SDL_Surface* tempsurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return texture;
}