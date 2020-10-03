#include "Animation_Manager.h"

void Animation_Manager::loadFromXML(std::string fileName, Texture& t)
{
	XMLDocument animFile;

	animFile.LoadFile(fileName.c_str());

	XMLElement* head;
	head = animFile.FirstChildElement("sprites");

	XMLElement* anim_element;
	anim_element = head->FirstChildElement("animation");
	while (anim_element)
	{
		Animation anim;
		current_anim = anim_element->Attribute("title");
		int delay;
		anim_element->QueryIntAttribute("delay", &delay);
		anim.speed = 1.0 / delay; anim.sprite.setTexture(t);
		XMLElement* cut;
		cut = anim_element->FirstChildElement("cut");
		while (cut)
		{
			int x;
			int y;
			int w;
			int h;
			cut->QueryIntAttribute("x", &x);
			cut->QueryIntAttribute("y", &y);
			cut->QueryIntAttribute("w", &w);
			cut->QueryIntAttribute("h", &h);

			anim.frames.push_back(IntRect(x, y, w, h));
			anim.frames_flip.push_back(IntRect(x + w, y, -w, h));
			cut = cut->NextSiblingElement("cut");
		}

		anim.sprite.setOrigin(0, anim.frames[0].height);

		anim_list[current_anim] = anim;
		anim_element = anim_element->NextSiblingElement("animation");
	}

}
void Animation_Manager::set(std::string name)
{
	current_anim = name;
	anim_list[current_anim].flip = 0;
}

void Animation_Manager::draw(RenderWindow& window, int x = 0, int y = 0)
{
	anim_list[current_anim].sprite.setPosition(x, y);
	window.draw(anim_list[current_anim].sprite);
}

void Animation_Manager::flip(bool b = 1) { anim_list[current_anim].flip = b; }

void Animation_Manager::update(float time) { anim_list[current_anim].update(time); }

void Animation_Manager::pause() { anim_list[current_anim].is_playing = false; }

void Animation_Manager::play() { anim_list[current_anim].is_playing = true; }

void Animation_Manager::play(std::string name) { anim_list[name].is_playing = true; }

bool Animation_Manager::isPlaying() { return anim_list[current_anim].is_playing; }

float Animation_Manager::getH() { return anim_list[current_anim].frames[0].height; }

float Animation_Manager::getW() { return anim_list[current_anim].frames[0].width; }