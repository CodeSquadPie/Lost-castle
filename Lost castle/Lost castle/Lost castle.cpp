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
const int ADDITIONAL_DRAW_AREA = 1;

RenderWindow window(sf::VideoMode(RESOLUTION_X, RESOLUTION_Y), "SFML works!");

int *current_map;
Clock timer;
Vector2f view_center(0.f,0.f);
Vector2f view_center_delta(0.f,0.f);
Vector2f view_size((float)RESOLUTION_X/2.f,(float)RESOLUTION_Y/2.f);
Texture tile_map_image;
Texture hero_texture;

Sprite background_brush;
int tile_size_x;
int tile_size_y;
int map_size_x = 50;
int map_size_y = 15;
float hero_dx = 0;
float hero_dy = 0;
float hero_dtx = 0;
float hero_dty = 0;
float hero_max_walking_speed = 200.f;
float hero_max_speed = 800.f;



void render_tile_brute_force(int x, int y, int type);

char map_file[] = "../assets/maps/debug/debug_map.tmx";



int querry_tile_on_map(int x,int y)
{
    return current_map[y*map_size_x+x];
}

void viewed_tiles()
{
    float tile_size_x_f = (float)tile_size_x;
    float half_size_x = view_size.x/2;
    float half_size_y = view_size.y/2;
    Vector2f up_left_corner(view_center.x - half_size_x,view_center.y - half_size_y);
    Vector2f down_right_corner(view_center.x + half_size_x, view_center.y + half_size_y);
    
    int x1 = (int)up_left_corner.x / tile_size_x;
    if (x1<0){x1=0;}
    int y1 = (int)up_left_corner.y / tile_size_y;
    if (y1<0){y1=0;}
    int x2 = (int)down_right_corner.x / tile_size_x + ADDITIONAL_DRAW_AREA;
    if (x2>map_size_x){x2=map_size_x;}
    int y2 = (int)down_right_corner.y / tile_size_y + ADDITIONAL_DRAW_AREA;
    if (y2>map_size_y){y2=map_size_y;}

    //std::cout << "X1: " << x1 << " Y2: " << y1 << " X2: " << x2 << " Y2: " << y2 << " center_x: " << view_center.x << " center_y: " << view_center.y << std::endl;
    int temp_int;
    
    for(int i=y1;i<y2;i++)
    {
        for(int j=x1;j<x2;j++)
        {
            //if(j<0){j=0;}
            //if(i<0){i=0;}

            //if(j>map_size_x){i++;j=0;}
            //if(i>map_size_y){ break;}

            temp_int = querry_tile_on_map(j,i);
            render_tile_brute_force(j,i,temp_int);
            //std::cout << "X: " << j << " Y : " << i << " Type: " << temp_int << std::endl;
        }
    }
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
    XMLDocument map_file;
    map_file.LoadFile(file_location);
    
    XMLElement *map_info = map_file.FirstChildElement();
    map_info->QueryIntAttribute("width",&map_size_x);
    map_info->QueryIntAttribute("height",&map_size_y);
    map_info->QueryIntAttribute("tilewidth", &tile_size_x);
    map_info->QueryIntAttribute("tileheight", &tile_size_y);

    XMLElement *tileset_info = map_info->FirstChildElement();

    XMLElement *layer_info = tileset_info->NextSiblingElement();
    XMLElement *data_info = layer_info->FirstChildElement();

    char *map_string = (char*)data_info->GetText();
    char *str_context = NULL;
    int *map = new int[map_size_x*map_size_y];
    char *char_current;
    int number;
    char_current = strtok_s(map_string, ",", &str_context);
    int i = 0;
    while (char_current != NULL)
    {
        sscanf_s(char_current, "%d", &number);
        char_current = strtok_s(NULL, ",", &str_context);
        map[i] = number;
        i++;
    }
    delete current_map;
    current_map = map;
    //std::cout << number << std::endl;
    //std::cout << map[54]+map[53] << std::endl;
    //std::cout << map_width_tiles << std::endl;
    //std::cout << map_height_tiles << std::endl;
    return map_file.ErrorID();
}

void render_tile_brute_force(int x, int y, int type)
{
    int type_coord_x = type*tile_size_x-tile_size_x;
    background_brush.setTexture(tile_map_image);//TODO: proper indexing system based on metadata of tileset xml
    background_brush.setTextureRect(IntRect(type_coord_x, 0, tile_size_x, tile_size_y));
    background_brush.setPosition((float)x*tile_size_x,(float)y*tile_size_y);
    window.draw(background_brush);
}



int main()
{
    int err = load_map(map_file);
    if (err != NULL){std::cout<<"Error loading xml"<<std::endl;}

    View view;
    view.setCenter(view_center);
    view.setSize(view_size);
    hero_texture.loadFromFile("../assets/characters/hero/adventurer-v1.5-Sheet.png");
    tile_map_image.loadFromFile("../assets/maps/debug/debug_room_tileset.jpg");
    
    window.setView(view);
    viewed_tiles();
    Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(IntRect(0, 0, 50, 37));

    timer.restart();

    //std::cout << querry_tile_on_map(10,7) <<std::endl; // must be 2
    
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
        view_center_delta.x = hero_dtx;
        view_center_delta.y = hero_dty;
        view.move(view_center_delta.x,view_center_delta.y);
        view_center = view.getCenter();
        hero_sprite.move(hero_dtx,hero_dty);
        window.clear();
        window.setView(view);
        viewed_tiles();
        window.draw(hero_sprite);
        window.display();
    }

    return 0;
}