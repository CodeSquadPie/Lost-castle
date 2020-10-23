component = {}

component.position = function(arg)
  if arg == nil then
    x_loc = 0
    y_loc = 0
  else
    x_loc = arg[1]
    y_loc = arg[2]
  end
  return {
    x = x_loc,
    y = y_loc
  }
end

component.velocity = function(arg)
  if arg == nil then
    delta_x = 0
    delta_y = 0
  else
    delta_x = arg[1]
    delta_y = arg[2]
  end
  return {
    dx = delta_x,
    dy = delta_y
  }
end

component.camera = function(arg)
  if arg == nil then
    width_loc = 800
    height_loc = 600
    scale_loc = 0.5
  else
    width_loc = arg[1]
    height_loc = arg[2]
    if arg[3] == nil then scale_loc = 0.5
    else
      scale_loc = arg[3]
    end
  end
  print("camera is created")
  return {
    width = width_loc,
    height = height_loc,
    scale = scale_loc
  }
end

component.controller = function(arg)
  return {
  up = false,
  left = false,
  right = false,
  down = false,
  action = false
  }
end

return component