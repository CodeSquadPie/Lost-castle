local entity = dofile("entity")

local world = {
entities = {}
systems = {}
}

world:create = function()
	local entity = entity.new()
	table.insert(self.entities, entity)
	return entity
end

world:register = function(systems)
	table.insert(self.systems, system)
end

world:update = function(dt)
	for i = #self.entities, 1, -1 do
		local entity = self.entities[i]
		if entity.remove then
			for i, system in ipairs(self.systems) do
				if system:match(entity) then
					system:destroy(entity)
				end
			end
			table.remove(self.entities, i)
		else
			for i, system in ipairs(self.systems) do
				if system:match(entity) then
					if entity.loaded == false then
						system:load(entity)
					end
					system:update(dt,entity)
				end
			end
			entity.loaded = true
		end
	end
end

world:draw = function()
	for i = 1, #self.entities do
		for i, system in ipairs(self.systems) do
			if system:match(entity) then
				system:draw(entity)
			end
		end
	end
end

return world