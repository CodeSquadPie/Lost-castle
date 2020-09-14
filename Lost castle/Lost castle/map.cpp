#include "map.h"

map::map()
{
    std::cout << "Created map object." << std::endl;
}

map::~map()
{
    std::cout << "Destroyed map object." << std::endl;
}

std::string map::file_location_concatination(char* file_dirrectory, const char *file_name_char)
{
    std::string file_location_string = file_dirrectory;
    std::string file_name = file_name_char;
    std::string concatenated_string = file_location_string + file_name;
    return concatenated_string;

}

void map::load_map(char* file_location)
{
    std::string file_location_string = file_location_concatination(file_location, "map.tmx");
    const char *file_location_char = file_location_string.c_str();

    XMLDocument map_file;
    map_file.LoadFile(file_location_char);
    XMLElement* map_info = map_file.FirstChildElement();
    map_info->QueryIntAttribute("width", &map_size_x);
    map_info->QueryIntAttribute("height", &map_size_y);
    map_info->QueryIntAttribute("tilewidth", &tile_size_x);
    map_info->QueryIntAttribute("tileheight", &tile_size_y);
    XMLElement* tileset_info = map_info->FirstChildElement();
    XMLElement* layer_info = tileset_info->NextSiblingElement();
    XMLElement* data_info = layer_info->FirstChildElement();

    char* map_string = (char*)data_info->GetText();
    char* str_context = NULL;
    int* map_array_temp = new int[map_size_x * map_size_y];
    char* char_current;
    int number;
    char_current = strtok_s(map_string, ",", &str_context);
    int i = 0;
    while (char_current != NULL)
    {
        sscanf_s(char_current, "%d", &number);
        char_current = strtok_s(NULL, ",", &str_context);
        map_array_temp[i] = number;
        i++;
    }
    this->current_tile_map = map_array_temp;
    
}

void map::change_map(char* file_location)
{
    
}

int map::querry_tile_on_map(int x, int y)
{
    return this->current_tile_map[y * map_size_x + x];
}

void map::load_map_tileset(char *file_location)
{

    std::string file_location_string = file_location_concatination(file_location,"tileset.tsx");
    const char* file_location_char = file_location_string.c_str();
    XMLDocument tileset_file;
    tileset_file.LoadFile(file_location_char);

    XMLElement* tileset_info = tileset_file.FirstChildElement();
    tileset_info->QueryIntAttribute("tilecount", &tilecount);
    tileset_info->QueryIntAttribute("columns", &columns);

    XMLElement* image_info = tileset_info->FirstChildElement();
    const char* tileset_image_filename = image_info->Attribute("source");


    std::string image_location_string = file_location_concatination(file_location,"tileset.jpg");
    const char* image_location_char = image_location_string.c_str();
    this->tileset_image.loadFromFile(image_location_char);
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
    int x2 = (int)down_right_corner.x / tile_size_x + ADDITIONAL_DRAW_AREA;
    if (x2 > map_size_x) { x2 = map_size_x; }
    int y2 = (int)down_right_corner.y / tile_size_y + ADDITIONAL_DRAW_AREA;
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