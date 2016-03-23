var json = JSON.parse(gPcgTile.tileJson, "utf8");

gPcgTile.version = json.version;
gPcgTile.orientation = json.orientation;
gPcgTile.renderOrder = json.renderorder;

gPcgTile.width = json.width;
gPcgTile.height = json.height;
gPcgTile.tileWidth = json.tilewidth;
gPcgTile.tileHeight = json.tileheight;

gPcgTile.nextObjectId = json.nextobjectid;

var i = 0;
for (i = 0; i < json.tilesets.length; i++) {
	gPcgTile.tileSetsNum = i;

	gPcgTileSets.name = json.tilesets[i].name;
	gPcgTileSets.image = json.tilesets[i].image;

	gPcgTileSets.imageWidth = json.tilesets[i].imagewidth;
	gPcgTileSets.imageHeight = json.tilesets[i].imageheight;
	gPcgTileSets.tileWidth = json.tilesets[i].tilewidth;
	gPcgTileSets.tileHeight = json.tilesets[i].tileheight;

	gPcgTileSets.margin = json.tilesets[i].margin;
	gPcgTileSets.spacing = json.tilesets[i].spacing;
	gPcgTileSets.firstGId = json.tilesets[i].firstgid;
}
gPcgTile.tileSetsNum = i;

for (i = 0; i < json.layers.length; i++) {
	gPcgTile.tileLayersNum = i;

	gPcgTileLayers.name = json.layers[i].name;

	gPcgTileLayers.width = json.layers[i].width;
	gPcgTileLayers.height = json.layers[i].height;

	gPcgTileLayers.type = json.layers[i].type;
	gPcgTileLayers.visible = json.layers[i].visible;
	gPcgTileLayers.opacity = json.layers[i].opacity;

	var j = 0;
	for (j = 0; j < json.layers[i].data.length; j++) {
		gPcgTileLayers.dataNum = j;
		gPcgTileLayers.data = json.layers[i].data[j];
	}
	gPcgTileLayers.dataNum = j;
}
gPcgTile.tileLayersNum = i;
