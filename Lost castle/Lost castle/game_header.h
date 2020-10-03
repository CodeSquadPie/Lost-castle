#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tinyxml2.h"


using namespace  sf;
using namespace tinyxml2;

const int RESOLUTION_X = 800;
const int RESOLUTION_Y = 600;
const float ACCELERATION_QUOTIENT = 0.1f;
const float SLOWDOWN_QUOTIENT = 1.006f;
const float HERO_MAX_SPEED = 800.f;
const float HERO_MAX_WALKING_SPEED = 200.f;
const float FALL_ACCELERATION_QUOTIENT = 0.2f;
const int ADDITIONAL_DRAW_AREA = 1;