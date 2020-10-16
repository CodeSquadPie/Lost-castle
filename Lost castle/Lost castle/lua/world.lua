local entities_path = "lua/entities"
local systems_path = "lua/systems"

world = {}
	world.entities = require(entities_path)
  world.systems = require(systems_path)
return world