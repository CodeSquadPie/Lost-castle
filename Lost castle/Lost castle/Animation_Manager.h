#pragma once
#include "game_header.h"
#include "Animation.h"

class Animation_Manager
{
public:
	std::string current_anim;
	std::map<std::string, Animation> anim_list;

	Animation_Manager()
	{
	
	}

	~Animation_Manager()
	{
		anim_list.clear();
	}
	void loadFromXML(std::string fileName, Texture& t);
	
	void set(std::string name);
	

	void draw(RenderWindow& window, int x, int y);
	

	void flip(bool b);

	void update(float time);

	void pause();

	void play();

	void play(std::string name);

	bool isPlaying();

	float getH();

	float getW();

	
};

