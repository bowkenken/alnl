var json = JSON.parse(gPcgCharGraph.cgJson, "utf8");

gPcgCharGraph.versionMajor = json.versionMajor;
gPcgCharGraph.versionMinor = json.versionMinor;
gPcgCharGraph.versionPatch = json.versionPatch;

gPcgCharGraph.charWidth = json.charWidth;
gPcgCharGraph.charHeight = json.charHeight;

gPcgCharGraph.width = json.width;
gPcgCharGraph.height = json.height;

gPcgCharGraph.rulerColumnLineHead = json.rulerColumnLineHead;
gPcgCharGraph.rulerColumnLineTail = json.rulerColumnLineTail;
gPcgCharGraph.rulerRowCharHead = json.rulerRowCharHead;
gPcgCharGraph.rulerRowCharTail = json.rulerRowCharTail;
gPcgCharGraph.backSlashChar = json.backSlashChar;

var maxRow
	= json.rulerColumnLineHead
	+ json.height
	+ json.rulerColumnLineTail;

var i = 0;
for (i = 0; i < maxRow; i++) {
	gPcgCharGraph.row = i;
	if (json.tile[i])
		gPcgCharGraph.tile = json.tile[i];
	else
		gPcgCharGraph.tile = "";
	if (json.color[i])
		gPcgCharGraph.color = json.color[i];
	else
		gPcgCharGraph.color = "";
}
gPcgCharGraph.row = i;
