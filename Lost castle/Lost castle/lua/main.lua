map_location = "../assets/maps/debug/"
config_location = "../config/config.lua"

--============== eclipse rebinds ===============
--[[
require "lua/outside"
_host = outside._host
config = outside.config
map = outside.map
_LoadConfig = outside._LoadConfig
_LoadMap = outside._LoadMap
_CameraChangePositon = outside._CameraChangePositon
--]]
--============== eclipse rebinds ===============

map = dofile(map_location.."map.lua")
config = dofile(config_location)
_LoadConfig(_host,config)

world = require("lua/world")
ent  = world.entity_assemble("main_hero",5,5,0,0)
--ent2 = world.entity_assemble("test_char",50,50,0,0)
--ent3 = world.entity_assemble("test_char",60,100,0,0)

map.tilesets[1].image = map_location..map.tilesets[1].image

init = function()
	print("Lua called init function within script.")
	world.systems:load_systems()
	_LoadMap(_host,
		map.tilesets[1].image,
		map.width,
		map.height,
		map.tilewidth,
		map.tileheight,
		map.tilesets[1].columns,
		map.layers[1].data
	)
end

update = function(dt,controlls)
	world.systems:update(dt,controlls)
end

draw = function()
	--world:draw()
end

--[[
init()
update(1,{up = true, right = true, left = false, down = false, action = false})
update(1,{up = true, right = true, left = false, down = false, action = false})
update(1,{up = true, right = true, left = false, down = false, action = false})
update(1,{up = true, right = true, left = false, down = false, action = false})
update(1,{up = true, right = true, left = false, down = false, action = false})
--]]