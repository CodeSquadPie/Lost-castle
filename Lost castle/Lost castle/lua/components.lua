local component_path = "lua/component"
local component = require(component_path)
components = {}

components.pool = {}

function components:add(component_name,index,...)
  if self.pool[component_name] == nil then
    print("it's nil")
    for k,v in pairs(component) do
      if k == component_name then
        self.pool[component_name] = {}
        print("added new cathegory of components")
      end
    end
    if self.pool[component_name] == nil then
      print("still nil")
      return false
    end
  end
  if world.entities:exists(index) and self.pool[component_name][index] == nil then
    print("adding component")
    self.pool[component_name][index] = component[component_name](...)
    return true
  else
    return false
  end
end

function components:correlation_2(name_1,name_2)
  local correlation = {}
  for k1,v1 in pairs(self.pool[name_1])do
    for k2,v2 in pairs(self.pool[name_2])do
      if k1 == k2 then table.insert(correlation,k1) end
    end
  end
  return correlation
end

function components:correlation_2_first_instance(name_1,name_2)
  for k1,v1 in pairs(self.pool[name_1])do
    for k2,v2 in pairs(self.pool[name_2])do
      if k1 == k2 then return k1 end
    end
  end
end

function components:correlation_3(name_1,name_2,name_3)
  local correlation = {}
  for k1,v1 in pairs(self.pool[name_1])do
    for k2,v2 in pairs(self.pool[name_2])do
      for k3,v3 in pairs(self.pool[name_3])do
        if k1 == k2 and k1 == k3 then table.insert(correlation,k1) end
      end
    end
  end
  return correlation
end

function components:correlation_3_first_instance(name_1,name_2,name_3)
  for k1,v1 in pairs(self.pool[name_1])do
    for k2,v2 in pairs(self.pool[name_2])do
      for k3,v3 in pairs(self.pool[name_3])do
        if k1 == k2 and k1 == k3 then return k1 end
      end
    end
  end
end

function components:remove(component_name,index)
  self.pool[component_name][index] = nil
end

function components:remove_all_components(index)
  for k,v in ipairs(self.pool)do
    self.pool[k][index] = nil
  end
end

return components