#pragma once
#include "game_header.h"

const int ADDITIONAL_DRAW_AREA = 1;

class map
{
	private:
		int map_size_x;
		int map_size_y;
		int tile_size_x;
		int tile_size_y;
		int columns;
		int* current_tile_map;
		int* current_collision_map;
		RenderWindow *render_target;
		View *view_reference;
		Texture tileset_image;
		Sprite map_brush;
		Vector2i tile_index_to_texture_coordinate(int type);
		void render_tile_brute_force(int x, int y, int type);
		int querry_tile_on_map(int x, int y);
		
	public:
		map();
		void load_map(std::string image, int map_width, int map_height, int tile_size_x, int tile_size_y, int columns, int *map_table);
		void reference_render_target(RenderWindow *window);
		void reference_view(View* view);
		void render();
		void print_map_index(int index);
};

