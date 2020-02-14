#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"


class ObjectVector {
public:
	ObjectVector();
	~ObjectVector();
	std::vector<GameObject*> _objectV;
	void render();
	void update();
	
};
