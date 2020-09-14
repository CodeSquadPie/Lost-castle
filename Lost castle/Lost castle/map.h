#pragma once
#include "game_header.h"
class map
{
	private:
		int map_size_x;
		int map_size_y;
		int tile_size_x;
		int tile_size_y;
		int tilecount;
		int columns;
		int* current_tile_map;
		int* current_collision_map;
		char *map_file_location;
		char *map_tileset_info_location;
		RenderWindow *render_target;
		View *view_reference;
		Texture tileset_image;
		Sprite map_brush;
		Vector2i tile_index_to_texture_coordinate(int type);
		void render_tile_brute_force(int x, int y, int type);
		int querry_tile_on_map(int x, int y);
		std::string file_location_concatination(char *file_dirrectory,const char *file_name_char);
	public:
		map();
		~map();
		void load_map(char* file_location);
		void change_map(char *file_location);
        void load_map_tileset(char *file_location);
		void reference_render_target(RenderWindow *window);
		void reference_view(View* view);
		void render();
};

