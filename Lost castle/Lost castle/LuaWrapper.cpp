#include "LuaWrapper.h"

LuaWrapper::LuaWrapper()
{
	//create lua state and open libs
	this->L = luaL_newstate();
	luaL_openlibs(this->L);

	//create and push into lua state global variable
	//called "_host" that contains pointer to this
	//wrapper object
	lua_pushlightuserdata(L,this);
	lua_setglobal(L,"_host");

	//register static methods to be callable from lua
	lua_register(this->L,"_LoadMap",this->lua_load_map);
	lua_register(this->L,"_LoadConfig",this->lua_load_config);
}

LuaWrapper::~LuaWrapper()
{
	lua_close(this->L);
}

void LuaWrapper::init()
{

	luaL_dofile(this->L,"lua/main.lua");
	lua_getglobal(this->L,"init");
	lua_pcall(this->L,0,0,0);
}

void LuaWrapper::update(float time)
{
	lua_getglobal(this->L,"update");
	lua_Number delta_time = time;
	lua_pushnumber(this->L,delta_time);
	lua_pcall(this->L,1,0,0);
}

void LuaWrapper::draw()
{
	lua_getglobal(this->L,"draw");
	lua_pcall(this->L,0,0,0);
}

int LuaWrapper::lua_load_map(lua_State* L)
{
	LuaWrapper *current_wrapper = static_cast<LuaWrapper*>(lua_touserdata(L,1));
	lua_remove(L,1);

	std::string image = lua_tostring(L, 1);
	lua_remove(L,1);

	int map_width = (int)lua_tonumber(L,1);
	lua_remove(L,1);

	int map_height = (int)lua_tonumber(L,1);
	lua_remove(L,1);

	int tile_size_x = (int)lua_tonumber(L, 1);
	lua_remove(L, 1);

	int tile_size_y = (int)lua_tonumber(L, 1);
	lua_remove(L, 1);

	int columns = (int)lua_tonumber(L, 1);
	lua_remove(L, 1);

	int* map_table = new int[map_width * map_height];

	if(lua_istable(L,1))
	{
		printf("it is a table\n");
		
		for (int i = 0; i <= map_width * map_height; i++)
		{
			lua_pushinteger(L,i+1);
			lua_gettable(L,1);
			map_table[i] = (int)lua_tonumber(L, -1);
			lua_remove(L,-1);
		}
	}
	else
	{
		printf("stuff left on stack is not table.\n");
	}

	current_wrapper->reference_to_map->load_map(image,
												map_width,
												map_height,
												tile_size_x,
												tile_size_y,
												columns,
												map_table);
	return 0;
}

int LuaWrapper::lua_load_config(lua_State* L)
{
	//read and remove froom stack pointer to this object
	LuaWrapper* current_wrapper = static_cast<LuaWrapper*>(lua_touserdata(L, 1));
	lua_remove(L, 1);

	//push table key to needed field, call it from table on stack, read and
	//delete from stack value that was returned
	lua_pushfstring(L,"res_width");
	lua_gettable(L,1);
	current_wrapper->resolution_width = (unsigned int)lua_tonumber(L,-1);
	lua_remove(L,-1);

	lua_pushfstring(L, "res_height");
	lua_gettable(L, 1);
	current_wrapper->resolution_height = (unsigned int)lua_tonumber(L, -1);
	lua_remove(L, -1);

	lua_pushfstring(L, "framerate_limit");
	lua_gettable(L, 1);
	current_wrapper->framerate_limit = (unsigned int)lua_tonumber(L, -1);
	lua_remove(L, -1);
	return 0;
}

void LuaWrapper::reference_map(map* current_map)
{
	this->reference_to_map = current_map;
}
