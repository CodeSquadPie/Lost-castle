#include "LuaWrapper.h"
//#include "character.h"
#include "map.h"
#include "game_header.h"

LuaWrapper Lua;
map current_map;
Clock timer;
Time time_elapsed;
View view;
Vector2f view_center(500.f,250.f);

int main()
{
    Lua.reference_map(&current_map);
    Lua.init();
    RenderWindow window(
        sf::VideoMode(Lua.resolution_width,Lua.resolution_height),
        "Lost castle project");
    current_map.reference_render_target(&window);
    current_map.reference_view(&view);
    window.setFramerateLimit(Lua.framerate_limit);
    view.setCenter(view_center);
    window.setView(view);
    Lua.update();
    /*current_map.print_map_index(3);
    current_map.print_map_index(4);
    current_map.print_map_index(5);*/
    //hero->reference_time(&time_elapsed);
    //hero->reference_view(&view);
    //hero->load_character(hero_file_location);

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
        //hero->update();
        window.clear();
        current_map.render();
        //std::cout << time << std::endl;
        view_center = Vector2f(view_center.x + 1.f,view_center.y);
        view.setCenter(view_center);
        window.setView(view);
        window.display();
    }
    Lua.~LuaWrapper();
    return 0;
}