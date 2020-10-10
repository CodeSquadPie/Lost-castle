#include "map.h"

map::map()
{

}

void map::load_map(std::string image, int map_width, int map_height, int tile_size_x, int tile_size_y, int columns,int *map_table)
{
    this->map_size_x = map_width;
    this->map_size_y = map_height;
    this->tileset_image.loadFromFile(image);
    this->tile_size_x = tile_size_x;
    this->tile_size_y = tile_size_y;
    this->columns = columns;
    this->current_tile_map = map_table;
}

int map::querry_tile_on_map(int x, int y)
{
    return this->current_tile_map[y * map_size_x + x];
}

Vector2i map::tile_index_to_texture_coordinate(int type)
{
    int index = type - 1;
    Vector2i coord_temp;
    coord_temp.x = index % columns * tile_size_x;
    coord_temp.y = index / columns * tile_size_y;
    //std::cout << "temp_x: " << coord_temp.x << " temp_y: " << coord_temp.y << " index: " << index << std::endl;
    return coord_temp;
}

void map::render_tile_brute_force(int x, int y, int type)
{
    Vector2i temp = tile_index_to_texture_coordinate(type);
    //std::cout<<"temp_x: " << temp.x <<" temp_y: "<<temp.y<<std::endl;
    map_brush.setTexture(tileset_image);
    map_brush.setTextureRect(IntRect(temp.x, temp.y, tile_size_x, tile_size_y));
    map_brush.setPosition(x * tile_size_x, y * tile_size_y);
    render_target->draw(map_brush);
}

void map::reference_render_target(RenderWindow *window)
{
    this->render_target = window;
}

void map::reference_view(View *view)
{
    this->view_reference = view;
}

void map::render()
{
    Vector2f size = view_reference->getSize();
    Vector2f center = view_reference->getCenter();
    Vector2f up_left_corner(center.x - size.x/2, center.y - size.y/2);
    Vector2f down_right_corner(center.x + size.x/2, center.y + size.y/2);

    int x1 = (int)up_left_corner.x / tile_size_x;
    if (x1 < 0) { x1 = 0; }
    int y1 = (int)up_left_corner.y / tile_size_y;
    if (y1 < 0) { y1 = 0; }
    int x2 = (int)down_right_corner.x / tile_size_x+ADDITIONAL_DRAW_AREA;
    if (x2 > map_size_x) { x2 = map_size_x; }
    int y2 = (int)down_right_corner.y / tile_size_y+ADDITIONAL_DRAW_AREA;
    if (y2 > map_size_y) { y2 = map_size_y; }

    //std::cout << "X1: " << x1 << " Y2: " << y1 << " X2: " << x2 << " Y2: " << y2 << " center_x: " << center.x << " center_y: " << center.y << std::endl;
    for (int i = y1; i < y2; i++)
    {
        for (int j = x1; j < x2; j++)
        {
            render_tile_brute_force(j, i, querry_tile_on_map(j, i));
        }
    }
}

void map::print_map_index(int index)
{
    std::cout << this->current_tile_map[index] << std::endl;
}
