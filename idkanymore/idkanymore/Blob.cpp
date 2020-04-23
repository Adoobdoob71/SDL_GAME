#include "pch.h"
#include "Blob.h"
#include "TManager.h"
#include "Game.h"
#include <iostream>

Blob::Blob(const char* texture) {
	this->texture = TManager::LoadTexture(texture);
}

Blob::~Blob() {
	texture = NULL;
	delete texture;
}

void Blob::Move() {
	ypos += 50;
	destR.h = 50;
	destR.w = 50;
	destR.x = xpos;
	destR.y = ypos;
}

void Blob::Render() {
	SDL_RenderCopy(Game::renderer, texture, NULL, &destR);
}