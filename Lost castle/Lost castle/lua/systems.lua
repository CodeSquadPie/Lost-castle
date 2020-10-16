local components_path = "lua/components"
local system_path = "lua/system"
local system = require(system_path)

systems = {}
systems.components = require(components_path)

systems.update_pool = {}
systems.draw_pool = {}

function systems:load_systems()
  self.update_pool.movement = system.movement()
end

function systems:update(dt)
  self.update_pool.movement.update(dt)
end

function systems:draw()
end

return systems