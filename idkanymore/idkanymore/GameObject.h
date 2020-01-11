#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texture, SDL_Renderer* ren);
	~GameObject();
	void Update();
	void Render();


private:

	int xpos;
	int ypos;

	SDL_Texture* objtexture;
	SDL_Rect srcR, destR;
	SDL_Renderer* renderer;


};