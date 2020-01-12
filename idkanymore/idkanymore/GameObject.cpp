#include "pch.h"
#include "GameObject.h"
#include "TManager.h"
#include "Game.h"

GameObject::GameObject(const char* texture) {
	objtexture = TManager::LoadTexture(texture);
}

void GameObject::Update() {

	
	destR.x = xpos;
	destR.y = ypos;
	destR.w = 128;
	destR.h = 72;
	
}

void GameObject::Movement() {

	SDL_Event ev;
	SDL_PollEvent(&ev);
	switch (ev.key.keysym.sym)
	{
	case SDLK_w:
		ypos -= 5;
		printf("HELLO");
		break;
	case SDLK_s:
		ypos += 5;
		break;
	case SDLK_d:
		xpos += 5;
		break;
	case SDLK_a:
		xpos -= 5;
		break;
	default:
		break;
	}
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objtexture, NULL, &destR);
}

