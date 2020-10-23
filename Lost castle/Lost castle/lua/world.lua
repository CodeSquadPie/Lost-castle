local entities_path = "lua/entities"
local systems_path = "lua/systems"
local tags_path = "lua/tags"
local game_characters = "../game/characters"
local characters = require(game_characters)

world = {}
	world.entities = require(entities_path)
  world.systems = require(systems_path)
  world.tags = require(tags_path)
  
  world.entity_assemble = function(object,...)
    local arg = {...}
    local entity = entities:create()
    local char = characters[object](arg)
    for k1,v1 in pairs(char)do
      local component_name = v1[1]
      local component_arguments = v1[2]
      systems.components:add(entity,component_name,component_arguments)
    end
  end
  world.entity_destroy = function(index)
    systems.components:remove_all_components(index)
    entities:destroy(index)
  end
  world.create_tag = function(tag)
  end
  world.link_entity = function(index,tag)
  end
  world.unlink_entity = function(index,tag)
  end
  world.destroy_all_linked_entities = function(tag)
  end
return world