local map_location = "../../assets/maps/debug/"
local config_location = "../../config/config.lua"
map = dofile(map_location.."map.lua")
map.tilesets[1].image = map_location..map.tilesets[1].image
local world = dofile("world.lua")


config = dofile(config_location)
	_LoadConfig(_host,config)

init = function()
	print("Lua called init function within script.")
	print("tilewidth should be 50, it is ".. map.width)
	_LoadMap(_host,
		map.tilesets[1].image,
		map.width,
		map.height,
		map.tilewidth,
		map.tileheight,
		map.tilesets[1].columns,
		map.layers[1].data)
end

update = function(dt)
	world:update(dt)
end

draw = function()
	world:draw()
end