#pragma once
#include "game_header.h"

class Animation
{
public:
    std::vector<IntRect> frames, frames_flip;
    float current_frame, speed;
    bool loop = true;
    bool flip = false;
    bool is_playing = true;
    Sprite sprite;


    void update(float time);
};

