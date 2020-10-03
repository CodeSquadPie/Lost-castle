#pragma once
#include "game_header.h"
class character
{
	private:
		enum animation_state {IDLE,RUNNING,JUMPING,FALLING,LANDING,ATTACKING};
		enum facing{LEFT,RIGHT};
		struct animation_data{animation_state state;facing side;int animation_frame;};
		int tile_size_x;
		int tile_size_y;
		int tilecount;
		int columns;
		Texture character_spritesheet;
		Sprite character_sprite;
		RenderWindow* render_target;
		View* view_reference;
		Time* time_reference;
		float character_x;
		float character_y;
		float character_dx;
		float character_dy;
		float character_dtx;
		float character_dty;
		Vector2i origin_to_draw_start_position();
		Vector2i tile_index_to_texture_coordinate(int index);
		std::string file_location_concatination(char* file_dirrectory, const char* file_name_char);
		void set_frame(int index);
		void control_update();
	public:
		character(float x, float y);
		void load_character(char* file_location);
		void reference_render_target(RenderWindow* window);
		void reference_view(View* view);
		void reference_time(Time* time);
		void update();
		void render();



};

