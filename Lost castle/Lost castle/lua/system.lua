return{
	new = function(requires)
		assert(type(requires) == "table")
		local system = {
			requires = requires
		}
		
		system:match = function(entity)
			for i=1, #self.requires do
				if entity:get(self.requires[i]) == nil then
					return false
				end
			end
			return true
		end
		system:load = function(entity)
		end
		system:update = function(dt,entity)
		end
		system:draw = function(entity)
		end
		system:ui_draw = function(entity)
		end
		system:destroy = function(entity)
		end
	end
}