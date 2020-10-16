local map_location = "../assets/maps/debug/"
local config_location = "../config/config.lua"

map = dofile(map_location.."map.lua")
config = dofile(config_location)
_LoadConfig(_host,config)

world = require("lua/world")
ent = world.entities:create()
print("entity exists =")
print(world.entities:exists(ent))
world.systems.components:add("position",ent,5,5)
world.systems.components:add("velocity",ent,20,2)
world.systems.components:add("camera",ent,config.width,config.height,0.5)


map.tilesets[1].image = map_location..map.tilesets[1].image
--[[
TODO: functions in C++

_LoadSprite(
	_host,
	texture_location,
	start_x,
	start_y,
	end_x,
	end_y
) --should have return of sprite index or userdata(pointer)

_ChangeSprite(
	_host,
	index(or pointer),
	start_x,
	start_y,
	end_x,
	end_y
)

_LoadHUD(
	_host,

)

_LoadMenu(
	_host,
)

--]]



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

update = function(dt)
	world.systems:update(dt)
end

draw = function()
	--world:draw()
end