var json = JSON.parse(gPcgTile.tileJson, "utf8");

gPcgTile.version = json.version;
gPcgTile.orientation = json.orientation;
gPcgTile.renderOrder = json.renderorder;

gPcgTile.width = json.width;
gPcgTile.height = json.height;
gPcgTile.tileWidth = json.tilewidth;
gPcgTile.tileHeight = json.tileheight;

gPcgTile.nextObjectId = json.nextobjectid;
