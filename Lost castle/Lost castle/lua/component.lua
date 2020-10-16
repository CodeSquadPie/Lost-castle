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


return component