#include "pch.h"
#include "Ball.h"
#include "TManager.h"
#include "Game.h"
#include "ObjectVector.h"
#include "BlobSpawner.h"
#include <iostream>

Ball::Ball(const char* texture, ObjectVector *ov, BlobSpawner *bs) {
	this->texture = TManager::LoadTexture(texture);
	this->ov = ov;
	this->bs = bs;
}

Ball::~Ball() {
	texture = NULL;
	delete texture;
}

void Ball::Update(int WIDTH, int HEIGHT) {
	xpos += Xvelocity;
	ypos += Yvelocity;
	destR.h = 30;
	destR.w = 30;
	destR.x = xpos;
	destR.y = ypos;
	Lock(WIDTH, HEIGHT);
}

void Ball::Lock(int WIDTH, int HEIGHT) {
	if (xpos == 0 || xpos + 30 == WIDTH)
		Xvelocity *= -1;
	if (ypos == 0 || ypos + 30 == HEIGHT)
		Yvelocity *= -1;

	for (GameObject *player : ov->_objectV) {
		if (xpos >= player->xpos - 30 && xpos <= player->xpos + player->destR.w && (ypos + 30 == player->ypos || ypos == player->ypos + player->destR.h))
			Yvelocity *= -1;
		if (ypos >= player->ypos - 30 && ypos <= player->ypos + player->destR.h && (xpos + 30 == player->xpos || xpos == player->xpos + player->destR.w))
			Xvelocity *= -1;
	}	
	int count = 0;
	for (Blob* a : bs->blob_vector) {
		if (xpos >= a->xpos - 30 && xpos <= a->xpos + a->destR.w && (ypos + 30 == a->ypos || ypos == a->ypos + a->destR.h)) {
			Yvelocity *= -1;
			try {
				bs->blob_vector.erase(bs->blob_vector.begin() + count);
				score += 10;
				std::cout << "Score: " << score << "\n";
			}
			catch (int e) {
				std::cout << "Error at blob number: " << count << "\n";
				std::cout << "Error: " << e << "\n";
			}
		}
		if (ypos >= a->ypos - 20 && ypos <= a->ypos + a->destR.h && (xpos + 20 == a->xpos || xpos == a->xpos + a->destR.w)) {
			Xvelocity *= -1;
			try {
				bs->blob_vector.erase(bs->blob_vector.begin() + count);
				score += 10;
				std::cout << "Score: " << score << "\n";
			}
			catch (int e) {
				std::cout << "Error at blob number: " << count << "\n";
				std::cout << "Error: " << e << "\n";
			}
		}
		count++;
	}
	count = 0;
}

void Ball::Render() {
	SDL_RenderCopy(Game::renderer, texture, NULL, &destR);
}