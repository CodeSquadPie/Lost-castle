#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once
class controller
{
	public:
		bool up;
		bool down;
		bool left;
		bool right;
		bool action;
		controller();
		void update();
};

