#pragma once
#include "Blob.h"
#include <vector>

class BlobSpawner {
public:
	BlobSpawner();
	~BlobSpawner();
	std::vector <Blob*> blob_vector;
	void render();
	void update();
	Uint32 start = 0;
	Uint32 SpawnTimer = 0;
};