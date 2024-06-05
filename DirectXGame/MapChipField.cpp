#include "MapChipField.h"
#include <cstdint>
#include <map>
#include <string>

void MapChipField::ResetMapChipData() { 
    mapChipData_.data.clear();
	mapChipData_.data.resize(kNumBlockVirtical);
	for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.data) {
		mapChipDataLine.resize(kNumBlockHorizontal);
	}
}

void MapChipField::LoadMapChipCsv(const std::string& filePath) {
	ResetMapChipData();
	std::ifstream file;
	/*assert(file.is_open());*/

	std::stringstream mapChipCsv;
	mapChipCsv << file.rdbuf();

	file.close();
}

//サイズ
static inline const float kBlockWidth = 1.0f;
static inline const float kBlockHeight = 1.0f;
//個数
static inline const uint32_t kNumBlockVirtical = 20;
static inline const uint32_t kNumBlockHorizontal = 100;

namespace {
std::map<std::string, MapChipType> mapChipTable = {
    {"0", MapChipType::kBlank},
    {"1", MapChipType::kBlock},
};
}