#pragma once
#include "SDL.h"

class Blob {

public:
	Blob(const char* texture);
	~Blob();
	void Move();
	void Render();
	SDL_Texture* texture;
	SDL_Rect srcR, destR;
	const int HEIGHT = 50, WIDTH = 50;
	int xpos = 50;
	int ypos = 100;
	
};