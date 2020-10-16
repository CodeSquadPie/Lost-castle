system = {}

system.movement = function()
  mov = {}
  mov.update = function(dt)
    correlations = components:correlation_2("position","velocity")
    for k,v in pairs(correlations)do
      if world.entities:exists(v) then
        components.pool["position"][v].x = components.pool["position"][v].x + components.pool["velocity"][v].dx * dt
        components.pool["position"][v].y = components.pool["position"][v].y + components.pool["velocity"][v].dy * dt
        print("x = "..components.pool["position"][v].x.." y = "..components.pool["position"][v].y)
      end
    end
  end
  return mov
end


return system