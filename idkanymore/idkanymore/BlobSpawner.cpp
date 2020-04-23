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
	if (SDL_GetTicks() - start > 5000) {
		for (Blob* a : BlobSpawner::blob_vector)
			a->Move();
		start = SDL_GetTicks();
		std::cout << start << "\n";
	}
}

