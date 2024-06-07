#pragma once
#include<vector>
#include "WorldTransform.h"
#include "Model.h"


enum class MapChipType {
	kBlank,
	kBlock,
};

class MapChipField {
public:
	void ResetMapChipData();
	void LoadMapChipCsv(const std::string& filePath);
	MapChipType GetMapChipTypeByIndex(uint32_t xindex, uint32_t yIndex);
	Vector3 GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex);


private:
	MapChipData mapChipData_;
	// サイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;
	// 個数
	static inline const uint32_t kNumBlockVirtical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;
};



struct MapChipData {
	std::vector<std::vector<MapChipData>> data;
};



