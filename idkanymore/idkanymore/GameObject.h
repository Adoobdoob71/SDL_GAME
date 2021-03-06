#pragma once
#include "Game.h"

class GameObject {


public:
	enum ID {
		Player,
		Enemy
	};
	GameObject(const char* texture, enum ID ID);
	~GameObject();
	void Update();
	void Render();
	void Movement(SDL_Event ev, int width, int height);
	int xpos;
	int ypos;
	bool left, right;
	int velocity = 5;
	ID ID;
	SDL_Texture* objtexture;
	SDL_Rect srcR, destR;

};