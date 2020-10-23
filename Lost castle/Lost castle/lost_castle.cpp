#include "lua_wrapper.h"
#include "controller.h"
#include "map.h"
#include "game_header.h"

lua_wrapper Lua;
controller contr;
map current_map;
Clock timer;
Time time_elapsed;
View view;
Vector2f view_center(500.f,250.f);

int main()
{
    Lua.reference_map(&current_map);
    Lua.reference_camera(&view);
    Lua.reference_control(&contr);
    Lua.init();
    
    RenderWindow window(
        sf::VideoMode(Lua.resolution_width,Lua.resolution_height),
        "Lost castle project");
    current_map.reference_render_target(&window);
    current_map.reference_view(&view);
    window.setFramerateLimit(Lua.framerate_limit);
    window.setView(view);

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
        contr.update();
        Lua.update(time_elapsed.asSeconds());
        Vector2u screen_size = window.getSize();
        Vector2f screen_size_half;
        //hero->update();
        window.clear();
        current_map.render();
        //std::cout << time << std::endl;
        window.setView(view);
        window.display();
    }
    Lua.~lua_wrapper();
    return 0;
}