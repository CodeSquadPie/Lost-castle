return{
	new = function()
		local entity = {
			components = {},
			tags = {},
			remove = false,
			loaded = false
		}
			
		entity:add = function(component)
			assert(component.__id)
			self.components[component.__id] = component
		end
		entity:get = function(id)
			return self.components[id]
		end
		entity:destroy = function()
			self.remove = true
		end
		
		return entity
	end
}