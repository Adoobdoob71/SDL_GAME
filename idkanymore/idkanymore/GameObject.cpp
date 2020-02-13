#include "pch.h"
#include "GameObject.h"
#include "TManager.h"
#include "Game.h"

GameObject::GameObject(const char* texture, enum GameObject::ID ID) {
	objtexture = TManager::LoadTexture(texture);
	this->ID = ID;
	xpos = 20;
}

GameObject::~GameObject() {
	objtexture = NULL;
	delete objtexture;
}

void GameObject::Update() {
	destR.x = xpos;
	destR.y = ypos;
	destR.w = 30;
	destR.h = 75;
	srcR.h = 75;
	srcR.w = 30;
	srcR.x = xpos;
	srcR.y = ypos;
}

void GameObject::Movement(SDL_Event ev, int WIDTH, int HEIGHT) {

	switch (ev.key.keysym.sym)
	{
	case SDLK_w:
		ypos -= 5;
		break;
	case SDLK_s:
		ypos += 5;
		break;
	default:
		break;
	}

	if (ypos == 0)
		ypos += 5;
	if (ypos == HEIGHT - 75)
		ypos -= 5;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objtexture, &srcR, &destR);
}



