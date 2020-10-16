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

return system