outside = {
  _host = 696969,
  config = {
    res_width = 800,
    res_height = 600,
    framerate_limit = 60
  },
  map = {
  version = "1.4",
  luaversion = "5.1",
  tiledversion = "1.4.2",
  orientation = "orthogonal",
  renderorder = "right-down",
  width = 50,
  height = 15,
  tilewidth = 32,
  tileheight = 32,
  nextlayerid = 2,
  nextobjectid = 1,
  properties = {},
  tilesets = {
    {
      name = "tilesheet",
      firstgid = 1,
      tilewidth = 32,
      tileheight = 32,
      spacing = 0,
      margin = 0,
      columns = 20,
      image = "tilesheet.png",
      imagewidth = 640,
      imageheight = 640,
      objectalignment = "unspecified",
      tileoffset = {
        x = 0,
        y = 0
      },
      grid = {
        orientation = "orthogonal",
        width = 32,
        height = 32
      },
      properties = {},
      terrains = {},
      tilecount = 400,
      tiles = {}
    }
  },
  layers = {
    {
      type = "tilelayer",
      x = 0,
      y = 0,
      width = 50,
      height = 15,
      id = 1,
      name = "Слой тайлов 1",
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      encoding = "lua",
      data = {
        2, 3, 4, 0, 0, 0, 42, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        22, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0, 65, 0, 0,
        22, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        22, 23, 24, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        22, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 63, 29, 63, 63, 63, 63, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        22, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 65, 0, 0, 0, 2, 3, 3, 3, 3, 3, 4, 0, 0, 0,
        22, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23, 23, 23, 23, 23, 24, 0, 0, 0,
        22, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23, 23, 23, 23, 23, 24, 0, 2, 3,
        22, 23, 24, 0, 0, 0, 0, 2, 3, 3, 3, 3, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 27, 23, 23, 23, 23, 23, 24, 0, 22, 23,
        22, 23, 26, 3, 3, 3, 3, 27, 23, 23, 23, 23, 26, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 64, 0, 0, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 24, 0, 22, 23,
        22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 26, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 24, 0, 22, 23,
        22, 23, 23, 23, 23, 6, 43, 43, 43, 7, 23, 23, 23, 23, 26, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 26, 3, 27, 23,
        22, 23, 23, 23, 23, 24, 0, 0, 0, 22, 23, 23, 23, 23, 23, 26, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 27, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
        22, 23, 23, 23, 23, 26, 3, 3, 3, 27, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
        22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23
      }
    }
  }
}





}
  function outside._LoadConfig(_host,config)
    print("load config: host = ".._host..", config.width = "..config.res_width..", config.height = "..config.res_height)
  end
  function outside._LoadMap(_host, image, width, height, tilewidth, tileheight, columns, data)
    print("load map: host = ".._host..", image = "..image..", width = "..width..", height = "..height..", tilewidth = "..tilewidth..", tileheight = "..tileheight..", columns = "..columns..", data = "..type(data))
  end
  function outside._CameraChangePositon(_host, center_x, center_y, scale)
    print("camera change position: host = ".._host..", center_x = "..center_x..", center_y = "..center_y..", scale = "..scale)
  end
  function outside._LoadSprite(_host, texture_location, sprite_x, sprite_y, start_x, start_y, end_x, end_y) --return pointer
  end
  function outside._ChangeSprite(_host, pointer_to_sprite, sprite_x, sprite_y, start_x, start_y, end_x, end_y)
  end
  function outside._ReloadSprite(_host, texture_location, sprite_x, sprite_y, start_x, start_y, end_x, end_y)
  end
  function outside._RenderSprites(_host,numbers)
  end
return ouside