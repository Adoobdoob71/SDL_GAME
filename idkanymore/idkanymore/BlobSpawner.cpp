#include "pch.h"
#include "BlobSpawner.h"
#include "Game.h"
#include "Blob.h"
#include "SDL.h"
#include <iostream>


BlobSpawner::BlobSpawner() {

}

BlobSpawner::~BlobSpawner() {
	for (Blob* a : BlobSpawner::blob_vector)
		delete a;
}

void BlobSpawner::render() {
	for (Blob* a : BlobSpawner::blob_vector)
		a->Render();
}

void BlobSpawner::update() {
	for (Blob* a : BlobSpawner::blob_vector)
		a->Update();
	if (SDL_GetTicks() - start > 5000) {
		for (Blob* a : BlobSpawner::blob_vector)
			a->Move();
		start = SDL_GetTicks();
		if (SDL_GetTicks() - SpawnTimer > 10000) {
			int bx = 1;
			for (int i = 0; i < 3; i++) {
				Blob* a = new Blob("C:/EM.png");
				a->xpos = bx * 45;
				a->ypos = 100;
				bx += 2;
				BlobSpawner::blob_vector.push_back(a);
			}
			SpawnTimer = SDL_GetTicks();
		}
		std::cout << start << "\n";
	}
}

