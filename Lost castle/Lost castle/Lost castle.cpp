#include <iostream>
#include <SFML/Graphics.hpp>
#include "tinyxml2.h"

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

int main()
{
//PROTOTYPE AREA BEGIN =======================
    int err = example_1(map_tileset_xml);
    if (err != NULL){std::cout<<"Error loading xml"<<std::endl;}
//PROTOTYPE AREA END =========================
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}