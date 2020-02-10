#pragma once
#include <vector>
#include <iostream>
#include "GameObject.h"

class ObjectVector {
public:
	ObjectVector();
	~ObjectVector();
	std::vector<GameObject*> _objectV;
	void clean();
	void render();
	void update();
	
};
