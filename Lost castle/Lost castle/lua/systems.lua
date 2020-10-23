local components_path = "lua/components"
local system_path = "lua/system"
local system = require(system_path)

systems = {}
systems.components = require(components_path)

systems.update_pool = {}
systems.draw_pool = {}

function systems:load_systems()
  self.update_pool.controlls = system.controller()
  self.update_pool.movement = system.movement()
  self.update_pool.camera_movement = system.camera_movement()
end

function systems:update(dt,controlls)
  self.update_pool.controlls.update(controlls)
  self.update_pool.controlls.apply(dt)
  self.update_pool.movement.update(dt)
  self.update_pool.camera_movement.update()
end

function systems:draw()
end

return systems