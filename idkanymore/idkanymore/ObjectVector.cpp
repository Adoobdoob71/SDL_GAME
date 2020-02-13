#include "pch.h"
#include "ObjectVector.h"
#include "SDL.h"

ObjectVector::ObjectVector() {

}
ObjectVector::~ObjectVector() {
	for (GameObject *a : _objectV)
		delete a;
}

void ObjectVector::update() {
	for (GameObject *a : _objectV) 
		a->Update();	
}

void ObjectVector::render() {
	for (GameObject *a : _objectV)
		a->Render();
}
