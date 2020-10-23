#include "controller.h"

controller::controller()
{
	this->up = false;
	this->down = false;
	this->left = false;
	this->right = false;
	this->action = false;
}

void controller::update()
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		this->up = true;
	}
	else {
		this->up = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		this->left = true;
	}
	else {
		this->left = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		this->right = true;
	}
	else {
		this->right = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		this->down = true;
	}
	else {
		this->down = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		this->action = true;
	}
	else {
		this->action = false;
	}
}
