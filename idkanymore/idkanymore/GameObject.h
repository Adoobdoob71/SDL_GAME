#pragma once
#include "Game.h"

class GameObject {


public:
	enum ID {
		Player,
		Enemy
	};
	GameObject(const char* texture, ID ID);
	~GameObject();
	void Update();
	void Render();
	void Movement(SDL_Event ev, int width, int height);
	int xpos;
	int ypos;
	ID ID;
	SDL_Texture* objtexture;
	SDL_Rect srcR, destR;

};