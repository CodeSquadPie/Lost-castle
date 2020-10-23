#include "lua540/include/lua.hpp"
extern "C" {
#pragma comment(lib, "lua540/liblua54.a")
}
#include "game_header.h"

class lua_wrapper
{
	private:
		lua_State* L;
		map *reference_to_map;
		View *camera_reference;
		controller *control_reference;
	public:
		unsigned int resolution_width;
		unsigned int resolution_height;
		unsigned int framerate_limit;
		lua_wrapper();
		~lua_wrapper();
		void init();
		void update(float time);
		void draw();
		static int lua_load_map(lua_State *L);
		static int lua_load_config(lua_State *L);
		static int lua_load_sprite(lua_State *L);
		static int lua_change_camera_position(lua_State *L);
		void reference_control(controller *control);
		void reference_map(map *current_map);
		void reference_camera(View *view);
};

