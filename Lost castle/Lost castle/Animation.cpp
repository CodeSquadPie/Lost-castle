#include "Animation.h"

void Animation::update(float time)
{
    if (!is_playing) return;
    current_frame += speed * time;

    if (current_frame > frames.size())
    {
        current_frame -= frames.size();
    }

    int i = current_frame;
    sprite.setTextureRect(frames[i]);
    if (flip) sprite.setTextureRect(frames_flip[i]);


}
