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
}

void GameObject::Movement(SDL_Event ev, int width, int height) {

	switch (ev.key.keysym.sym)
	{
	case SDLK_d:
		left = false;
		right = true;
		break;
	case SDLK_a:
		left = true;
		right = false;
		break;
	default:
		break;
	}
	if (right)
		xpos += velocity;
	if (left)
		xpos -= velocity;
	if (xpos < 0)
		xpos += velocity;
	if (xpos > width - 150)
		xpos -= velocity;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objtexture, NULL, &destR);
}



