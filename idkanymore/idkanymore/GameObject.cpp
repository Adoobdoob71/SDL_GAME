#include "pch.h"
#include "GameObject.h"
#include "TManager.h"
#include "Game.h"

GameObject::GameObject(const char* texture, enum GameObject::ID ID) {
	objtexture = TManager::LoadTexture(texture);
	this->ID = ID;
}

GameObject::~GameObject() {
	objtexture = NULL;
	delete objtexture;
}

void GameObject::Update() {
	destR.x = xpos;
	destR.y = ypos;
	destR.w = 110;
	destR.h = 30;
	srcR.h = 110;
	srcR.w = 30;
}

void GameObject::Movement(SDL_Event ev, int WIDTH, int HEIGHT) {

	switch (ev.key.keysym.sym)
	{
	case SDLK_a:
		xpos -= velocity;
		break;
	case SDLK_d:
		xpos += velocity;
		break;
	case SDLK_s:
		ypos += velocity;
		break;
	case SDLK_w:
		ypos -= velocity;
		break;
	default:
		break;
	}

	if (xpos == 0)
		xpos += velocity;
	if (xpos == WIDTH - destR.w)
		xpos -= velocity;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objtexture, NULL, &destR);
}



