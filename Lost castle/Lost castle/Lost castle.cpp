#include <iostream>
#include <SFML/Graphics.hpp>
#include "tinyxml2.h"

using namespace  sf;
using namespace tinyxml2;


const int RESOLUTION_X = 800;
const int RESOLUTION_Y = 600;
const float ACCELERATION_QUOTIENT = 0.1f;
const float SLOWDOWN_QUOTIENT = 1.006f;
const float FALL_ACCELERATION_QUOTIENT = 0.2f;

Clock timer;
Vector2f view_center(0.f,0.f);
Vector2f view_size((float)RESOLUTION_X/2.f,(float)RESOLUTION_Y/2.f);
unsigned int current_map[];

int tile_size_x;
int tile_size_y;

float hero_dx = 0;
float hero_dy = 0;
float hero_dtx = 0;
float hero_dty = 0;
float hero_max_walking_speed = 200.f;
float hero_max_speed = 800.f;

char map_file[] = "../assets/maps/debug/debug_map.tmx";

void viewed_tiles(Vector2f *view_center, Vector2f *view_size, int tile_size_x, int tile_size_y)
{
    float tile_size_x_f = (float)tile_size_x;
    float half_size_x = view_size->x/2;
    float half_size_y = view_size->y/2;
    Vector2f up_left_corner(view_center->x - half_size_x,view_center->y - half_size_y);
    Vector2f down_right_corner(view_center->x + half_size_x, view_center->y + half_size_y);
    int x1 = (int)up_left_corner.x/tile_size_x;
    int y1 = (int)up_left_corner.y/tile_size_y;
    int x2 = (int)down_right_corner.x / tile_size_x;;
    int y2 = (int)down_right_corner.y / tile_size_y;;

}

void load_map_tileset(char *file_location)
{
    int tilewidth;
    int tileheight;
    int tilecount;
    int columns;

    XMLDocument tileset_file;
    tileset_file.LoadFile(file_location);
    
    XMLElement *tileset_info = tileset_file.FirstChildElement();
    tileset_info->QueryIntAttribute("tilewidth", &tilewidth);
    tileset_info->QueryIntAttribute("tileheight", &tileheight);
    tileset_info->QueryIntAttribute("tilecount", &tilecount);
    tileset_info->QueryIntAttribute("columns", &columns);

    XMLElement *image_info = tileset_info->FirstChildElement();
    const char *tileset_image_location = image_info->Attribute("source");

}

int load_map(char *file_location)
{
    int map_width_tiles;
    int map_height_tiles;
    int tilewidth;
    int tileheight;

    XMLDocument map_file;
    map_file.LoadFile(file_location);
    
    XMLElement *map_info = map_file.FirstChildElement();
    map_info->QueryIntAttribute("width",&map_width_tiles);
    map_info->QueryIntAttribute("height",&map_height_tiles);
    map_info->QueryIntAttribute("tilewidth", &tilewidth);
    map_info->QueryIntAttribute("tileheight", &tileheight);

    XMLElement *tileset = map_info->FirstChildElement();

    std::cout << map_width_tiles << std::endl;
    std::cout << map_height_tiles << std::endl;
    return map_file.ErrorID();
}

int main()
{
    int err = load_map(map_file);
    if (err != NULL){std::cout<<"Error loading xml"<<std::endl;}

    View view;
    view.setCenter(Vector2f(0.f,0.f));
    view.setSize(Vector2f((float)RESOLUTION_X/2.f, (float)RESOLUTION_Y/2.f));

    RenderWindow window(sf::VideoMode(RESOLUTION_X, RESOLUTION_Y), "SFML works!");
    window.setView(view);
    Texture map;
    Texture hero_texture;
    hero_texture.loadFromFile("../assets/characters/hero/adventurer-v1.5-Sheet.png");
    Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(IntRect(0, 0, 50, 37));

    timer.restart();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {hero_dx -= ACCELERATION_QUOTIENT;} // controlls to delta x
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {hero_dx += ACCELERATION_QUOTIENT;}
        else {hero_dx /= SLOWDOWN_QUOTIENT;}
        
        if (Keyboard::isKeyPressed(Keyboard::Up)) {hero_dy -= FALL_ACCELERATION_QUOTIENT;} // controlls to delta y
        else if (Keyboard::isKeyPressed(Keyboard::Down)) {hero_dy += FALL_ACCELERATION_QUOTIENT;}
        else {hero_dy /= SLOWDOWN_QUOTIENT;}

        if (hero_dx > hero_max_walking_speed) {hero_dx = hero_max_walking_speed;} // trimm to max speed x
        else if(hero_dx < hero_max_walking_speed * -1){hero_dx = hero_max_walking_speed * -1;}

        if (hero_dy > hero_max_speed) {hero_dy = hero_max_speed;} // trimm to max speed y
        else if (hero_dy < hero_max_speed * -1) {hero_dy = hero_max_speed * -1;}

        Time time_elapsed = timer.restart();
        hero_dtx = time_elapsed.asSeconds() * hero_dx;
        hero_dty = time_elapsed.asSeconds() * hero_dy;

        //TODO: correction of dtx and dty by collision

        hero_sprite.move(hero_dtx,hero_dty);
        window.clear();
        window.draw(hero_sprite);
        window.display();
    }

    return 0;
}