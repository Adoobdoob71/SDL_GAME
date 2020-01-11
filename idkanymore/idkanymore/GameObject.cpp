#include "pch.h"
#include "GameObject.h"
#include "TManager.h"

GameObject::GameObject(const char* texture, SDL_Renderer* ren) {

	renderer = ren;
	objtexture = TManager::LoadTexture(texture, renderer);
	
}

void GameObject::Update() {

	xpos = 0;
	ypos = 0;
	srcR.h = 600;
	srcR.w = 800;
	srcR.x = 0;
	srcR.y = 0;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = 800;
	destR.h = 600;

}

void GameObject::Render() {

	SDL_RenderCopy(renderer, objtexture, &srcR, &destR);


}