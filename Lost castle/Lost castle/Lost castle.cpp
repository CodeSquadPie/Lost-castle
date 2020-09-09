#include <iostream>
#include <SFML/Graphics.hpp>
#include "tinyxml2.h"

using namespace  sf;
using namespace tinyxml2;

char map_file[] = "../assets/maps/debug/debug_map.tmx";
char map_tileset_xml[] = "../assets/maps/debug/debug_room_tileset.tsx";
char map_tileset_img[] = "../assets/maps/debug/debug_room_tileset.jpg";

int example_1(char *file_location)
{
    XMLDocument doc;
    doc.LoadFile(file_location);

    return doc.ErrorID();
}

void change(Sprite &sprite)
{
    while (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::Up))
    {
        sprite.setTextureRect(IntRect(64, 0, 32, 32));
        sprite.setTextureRect(IntRect(0, 0, 32, 32));
        sprite.setTextureRect(IntRect(32, 0, 32, 32));
    }
}

int main()
{
//PROTOTYPE AREA BEGIN =======================
    int err = example_1(map_tileset_xml);
    if (err != NULL){std::cout<<"Error loading xml"<<std::endl;}
//PROTOTYPE AREA END =========================
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Texture hero_texture;
    Sprite hero_sprite;
    hero_texture.loadFromFile("../assets/maps/debug/debug_room_tileset.jpg");
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(IntRect(64, 0, 32, 32));



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { hero_sprite.move(-0.1, 0); change(hero_sprite); }
        if (Keyboard::isKeyPressed(Keyboard::Right)) { hero_sprite.move(0.1, 0); change(hero_sprite); }
        if (Keyboard::isKeyPressed(Keyboard::Up)) { hero_sprite.move(0, -0.1);change(hero_sprite); }
        if (Keyboard::isKeyPressed(Keyboard::Down)) { hero_sprite.move(0, 0.1);change(hero_sprite);} 

        window.clear();
        window.draw(hero_sprite);
        window.display();
    }

    return 0;
}