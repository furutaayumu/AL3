#pragma once
#include <vector>
class MapChipField {
	MapChipData mapChipData_;
	void ResetMapChipData();
	void LoadMapChipCsv(const std::string& filePath);
};

enum class MapChipType { 
	kBlank,
	kBlock,
};

struct MapChipData {
	std::vector<std::vector<MapChipData>> data;
};