component = {}

component.test = function(...)
  local arg = {...}
  print("test_component_called")
  return {"test_component_tab"}
end

component.position = function(...)
  local arg = {...}
  local x_loc = arg[1]
  local y_loc = arg[2]
  if arg[1] == nil then x_loc = 0 end
  if arg[2] == nil then y_loc = 0 end
  return {
    x = x_loc,
    y = y_loc
  }
end

component.velocity = function(...)
  local arg = {...}
  local delta_x = arg[1]
  local delta_y = arg[2]
  if arg[1] == nil then delta_x = 0 end
  if arg[2] == nil then delta_y = 0 end 
  return {
    dx = delta_x,
    dy = delta_y
  }
end

component.camera = function(...)
  local arg = {...}
  local width_loc = arg[1]
  local height_loc = arg[2]
  local scale_loc = arg[3]
  if arg[1] == nil then width_loc = 800 end
  if arg[2] == nil then height_loc = 600 end
  if arg[3] == nil then scale_loc = 0.5 end 
  return {
    width = width_loc,
    height = height_loc,
    scale = scale_loc
  }
end

return component