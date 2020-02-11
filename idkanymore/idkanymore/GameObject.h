#pragma once
#include "Game.h"

class GameObject {


public:
	enum ID {
		Player,
		Enemy
	};
	GameObject(const char* texture, ID);
	~GameObject();
	void Update();
	void Render();
	void Movement();
	int xpos;
	int ypos;
	ID ID;

private:

	SDL_Rect srcR, destR;
	SDL_Texture* objtexture;
	
};