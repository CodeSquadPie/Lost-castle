chars = {}

chars.main_hero = function(arg)
  if arg[1] == nil then arg[1] = 0 end
  if arg[2] == nil then arg[2] = 0 end
  if arg[3] == nil then arg[3] = 0 end
  if arg[4] == nil then arg[4] = 0 end
  char = {}
  char[1] = {"position",{arg[1],arg[2]}}
  char[2] = {"velocity",{arg[3],arg[4]}}
  char[3] = {"camera"}
  char[4] = {"controller"}
  return char
end

chars.test_char = function(arg)
  if arg[1] == nil then arg[1] = 0 end
  if arg[2] == nil then arg[2] = 0 end
  if arg[3] == nil then arg[3] = 0 end
  if arg[4] == nil then arg[4] = 0 end
  char = {}
  char[1] = {"position",{arg[1],arg[2]}}
  char[2] = {"velocity",{arg[3],arg[4]}}
  return char
end

return chars