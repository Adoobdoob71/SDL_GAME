#pragma once
#include "SDL.h"
#include "ObjectVector.h"


class Ball {

public:
	Ball(const char* texture, ObjectVector *ov);
	~Ball();
	void Update(int WIDTH, int HEIGHT);
	void Render();
	void Lock(int WIDTH, int HEIGHT);
	SDL_Texture* texture;
	SDL_Rect srcR, destR;
	int xpos;
	int ypos;
	int Xvelocity = 5, Yvelocity = 5;
	ObjectVector *ov;


};