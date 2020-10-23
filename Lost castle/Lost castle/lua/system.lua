system = {}

system.movement = function()
  mov = {}
  mov.update = function(dt)
    correlations = components:correlation_2("position","velocity")
    for k,v in pairs(correlations)do
      if world.entities:exists(v) then
        components.pool["position"][v].x = components.pool["position"][v].x + components.pool["velocity"][v].dx * dt
        components.pool["position"][v].y = components.pool["position"][v].y + components.pool["velocity"][v].dy * dt
        --print("x = "..components.pool["position"][v].x.." y = "..components.pool["position"][v].y)
      end
    end
  end
  return mov
end

system.camera_movement = function()
  cam = {}
  cam.update = function()
    --print("cam update was called")
    index = components:correlation_2_first_instance("position","camera")
    --print("index is "..index)
    if world.entities:exists(index) then
      center_x = components.pool["position"][index].x + 32 / 2
      center_y = components.pool["position"][index].y + 32 / 2
      scale = components.pool["camera"][index].scale
      _CameraChangePositon(_host, center_x, center_y, scale)
      --print("camera: center_x = "..center_x.." center_y = "..center_y)
    end
  end
  return cam
end

system.controller = function()
  contr = {}
  
    contr.update = function(controlls)
      index = components:first_instance("controller")
      if index ~= nil then
        if world.entities:exists(index) then
          components.pool["controller"][index].up = controlls.up
          components.pool["controller"][index].down = controlls.down
          components.pool["controller"][index].left = controlls.left
          components.pool["controller"][index].right = controlls.right
          components.pool["controller"][index].action = controlls.action 
        end
      end
    end
    
    contr.apply = function(dt)
      index = components:correlation_2_first_instance("velocity","controller")
      controller = components.pool["controller"][index]
      if world.entities:exists(index) then
        delta_x_velocity = 0
        delta_y_velocity = 0
        if controller ~= nil then
          if     controller.up then
            delta_y_velocity = delta_y_velocity - 1
          elseif controller.down then
            delta_y_velocity = delta_y_velocity + 1
          end
          if     controller.left then
            delta_x_velocity = delta_x_velocity - 1
          elseif controller.right then
            delta_x_velocity = delta_x_velocity + 1
          end
          if math.abs(delta_x_velocity) == 1 and math.abs(delta_y_velocity) == 1 then
            delta_x_velocity = delta_x_velocity * 0.85 * dt
            delta_y_velocity = delta_y_velocity * 0.85 * dt
          else
            delta_x_velocity = delta_x_velocity * dt
            delta_y_velocity = delta_y_velocity * dt
          end
          components.pool["velocity"][index].dx = components.pool["velocity"][index].dx + delta_x_velocity
          components.pool["velocity"][index].dy = components.pool["velocity"][index].dy + delta_y_velocity
        end 
      end
    end
  return contr
end

return system