#include "character.h"

character::character(float x, float y)
{
	this->character_x = x;
	this->character_y = y;
}

void character::load_character(char* file_location)
{
    std::string file_location_string = file_location_concatination(file_location, "character.tsx");
    const char* file_location_char = file_location_string.c_str();

	XMLDocument character_file;
	character_file.LoadFile(file_location_char);
    XMLElement* tileset_info;
    tileset_info = character_file.FirstChildElement();
    tileset_info->QueryIntAttribute("tilewidth", &tile_size_x);
    tileset_info->QueryIntAttribute("tileheight", &tile_size_y);
    tileset_info->QueryIntAttribute("tilecount", &tilecount);
    tileset_info->QueryIntAttribute("columns", &columns);
    
    std::string image_location_string = file_location_concatination(file_location, "sprite_sheet.png");
    const char* image_location_char = file_location_string.c_str();
    character_spritesheet.loadFromFile(image_location_char);

}

void character::reference_render_target(RenderWindow* window)
{
    this->render_target = window;
}

void character::reference_view(View* view)
{
    this->view_reference = view;
}

void character::reference_time(Time* time)
{
    this->time_reference = time;
}

void character::update()
{
    control_update();
    //std::cout <<"char_x: "<< character_x <<" char_y: "<< character_y << std::endl;
    view_reference->setCenter(character_x,character_y);
}

void character::render()
{
}

Vector2i character::tile_index_to_texture_coordinate(int index)
{
	Vector2i coord_temp;
	coord_temp.x = ((index % columns) - 1) * tile_size_x;
	coord_temp.y = (index - 1) * tile_size_y;
	return coord_temp;
}

std::string character::file_location_concatination(char* file_dirrectory, const char* file_name_char)
{
    std::string file_location_string = file_dirrectory;
    std::string file_name = file_name_char;
    std::string concatenated_string = file_location_string + file_name;
    return concatenated_string;
}

void character::control_update()
{
    if (Keyboard::isKeyPressed(Keyboard::Left)) { character_dx -= ACCELERATION_QUOTIENT; } // controlls to delta x
    else if (Keyboard::isKeyPressed(Keyboard::Right)) { character_dx += ACCELERATION_QUOTIENT; }
    else { character_dx /= SLOWDOWN_QUOTIENT; }

    if (Keyboard::isKeyPressed(Keyboard::Up)) { character_dy -= FALL_ACCELERATION_QUOTIENT; } // controlls to delta y
    else if (Keyboard::isKeyPressed(Keyboard::Down)) { character_dy += FALL_ACCELERATION_QUOTIENT; }
    else { character_dy /= SLOWDOWN_QUOTIENT; }

    if (character_dx > HERO_MAX_WALKING_SPEED){ character_dx = HERO_MAX_WALKING_SPEED; } // trimm to max speed x
    else if (character_dx < HERO_MAX_WALKING_SPEED * -1) { character_dx = HERO_MAX_WALKING_SPEED * -1; }

    if (character_dy > HERO_MAX_SPEED) { character_dy = HERO_MAX_SPEED; } // trimm to max speed y
    else if (character_dy < HERO_MAX_SPEED * -1){ character_dy = HERO_MAX_SPEED * -1;}
    
    character_dtx = time_reference->asSeconds() * character_dx;
    character_dty = time_reference->asSeconds() * character_dy;

    character_x += character_dtx;
    character_y += character_dty;
}
