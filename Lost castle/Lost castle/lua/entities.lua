entities = {}
	entities.pool = {}
	entities.iter = 0
	
	function entities:create()
		local i = 0
		while true do
			if self.pool[i] == nil then
				self.pool[i] = {
					exist = true,
					hidden = false
				}
				self.iter = self.iter + 1
				return i
			elseif self.pool[i].exist == false then
				self.pool[i].exist = true
				self.pool[i].hidden = false
			  return i
			end
			i = i + 1
		end
	end

	function entities:destroy(index)
		self.pool[index].exist = false
	end
	
	function entities:exists(index)
		if self.pool[index] == nil then return false end
		return self.pool[index].exist
	end
	
	function entities:hides(index)
		if self.pool[index] == nil then return false end
		return self.pool[index].hidden
	end
	
return entities
