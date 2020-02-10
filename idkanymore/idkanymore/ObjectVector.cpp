#include "pch.h"
#include "ObjectVector.h"
#include "SDL.h"


ObjectVector::ObjectVector() {

}
ObjectVector::~ObjectVector() {

}

void ObjectVector::update() {
	for (GameObject *a : _objectV) {
		a->Update();
		a->Movement();
	}
}

void ObjectVector::render() {
	for (GameObject *a : _objectV)
		a->Render();
}

void ObjectVector::clean() {
	for (GameObject *a : _objectV)
		delete a;
}