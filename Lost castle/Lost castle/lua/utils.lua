return{
	new = function(original)
		local original_type = type(original)
		local copy
		if original_type == "table" then
			copy = {}
			for original_key, original_value in next, original, nil do
				copy[new(original_key)] = new(original_value)
			end
		else
			copy = original
		end
		return copy
	end
}