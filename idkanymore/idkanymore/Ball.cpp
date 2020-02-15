#include "pch.h"
#include "Ball.h"
#include "TManager.h"
#include "Game.h"
#include "ObjectVector.h"

Ball::Ball(const char* texture, ObjectVector *ov) {
	this->texture = TManager::LoadTexture(texture);
	this->ov = ov;
}

Ball::~Ball() {
	texture = NULL;
	delete texture;
}

void Ball::Update(int WIDTH, int HEIGHT) {
	xpos += Xvelocity;
	ypos += Yvelocity;
	destR.h = 50;
	destR.w = 50;
	destR.x = xpos;
	destR.y = ypos;
	Lock(WIDTH, HEIGHT);
}

void Ball::Lock(int WIDTH, int HEIGHT) {
	if (xpos == 0 || xpos + 50 == WIDTH)
		Xvelocity *= -1;
	if (ypos == 0 || ypos + 50 == HEIGHT)
		Yvelocity *= -1;

	for (GameObject *player : ov->_objectV) {
		if (ypos >= player->ypos - 50 && ypos <= player->ypos + player->destR.h && (xpos + 50 == player->xpos || xpos == player->xpos + player->destR.w)) {
			Xvelocity *= -1;
			continue;
		}
		if (xpos >= player->xpos - 50 && xpos <= player->xpos + player->destR.w && (ypos + 50 == player->ypos || ypos == player->ypos + player->destR.h))		
			Yvelocity *= -1;
	
	}
}

void Ball::Render() {
	SDL_RenderCopy(Game::renderer, texture, NULL, &destR);
}