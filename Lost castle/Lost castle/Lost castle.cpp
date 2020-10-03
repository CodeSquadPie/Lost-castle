#include "game_header.h"
#include "character.h"
#include "map.h"
#include <list>
#include "Animation_Manager.h"




RenderWindow window(sf::VideoMode(RESOLUTION_X, RESOLUTION_Y), "SFML works!");
char map_file_location[] = "../assets/maps/debug/";
char hero_file_location[]= "../assets/characters/hero/adventurer-v1.5-Sheet.tsx";
map *current_map = new map();
character *hero = new character(0.f,0.f);
Clock timer;
Time time_elapsed;
View view;
Vector2f view_center(0.f,0.f);
Vector2f view_size((float)RESOLUTION_X/2.f,(float)RESOLUTION_Y/2.f);





int main()
{
    view.setCenter(view_center);
    view.setSize(view_size);
    window.setView(view);
    current_map->reference_render_target(&window);
    current_map->reference_view(&view);
    current_map->load_map(map_file_location);
    current_map->load_map_tileset(map_file_location);
    hero->reference_time(&time_elapsed);
    hero->reference_view(&view);
    //hero->load_character(hero_file_location);

    Texture texture;
    texture.loadFromFile("../assets/characters/hero/sprite_sheet.png");
    Animation_Manager anim;
    anim.loadFromXML("../assets/characters/hero/hero_animation.xml", texture);




    timer.restart();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float time = timer.getElapsedTime().asMicroseconds();
        time = time / 1000;
        time_elapsed = timer.restart();
        Vector2u screen_size = window.getSize();
        Vector2f screen_size_half;
        screen_size_half.x = (float)screen_size.x/2.f;
        screen_size_half.y = (float)screen_size.y/2.f;
        view.setSize(screen_size_half);
        hero->update();
        window.clear();
        current_map->render();
        //hero->render();
        anim.update(time);
        std::cout << time << std::endl;
       anim.set("character_running");
       anim.draw(window, 100 , 100);
        
        window.setView(view);
        window.display();
    }

    return 0;
}