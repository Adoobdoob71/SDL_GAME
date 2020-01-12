#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texture);
	~GameObject();
	void Update();
	void Render();
	void Movement();
	int xpos;
	int ypos;

private:

	SDL_Rect srcR, destR;
	SDL_Texture* objtexture;
	
};