#include "MathUtilityForText.h"
#include <cmath>
#include <numbers>

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {
	Vector3 dm = scale;

	Matrix4x4 RotateMatyY = {cosf(rot.y), 0, - sinf(rot.y), 0, 0, 1, 0, 0, sinf(rot.y), 0, cosf(rot.y), 0, 0, 0, 0, 1};

	Matrix4x4 TranslateMat = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, translate.x, translate.y, translate.z, 1};

	Matrix4x4 ansMat = Multiply(RotateMatyY, TranslateMat);

	return ansMat;
}

Vector3& operator+=(Vector3& lhv, const Vector3& rhv) {
	lhv.x += rhv.x;
	lhv.y += rhv.y;
	lhv.z += rhv.z;
	return lhv;
}

Matrix4x4 Multiply(Matrix4x4& m1,Matrix4x4& m2) {
	Matrix4x4 Result = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				Result.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}
	return Result;
}

float EaseInOut(float x1, float x2, float t) { float easedT = -(std::cosf(std::numbers::pi_v<float> * t) - 1.0f) / 2.0f;
	return Lerp(x1, x2, easedT);
}

float Lerp(float x1, float x2, float t) { return (1.0f - t) * x1 + t * x2; }

Vector3 Lerp(const Vector3& v1, Vector3& v2, float t) { return Vector3(Lerp(v1.x, v2.x, t), Lerp(v1.y, v2.y, t), Lerp(v1.z, v2.z, t)); }

const Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	Vector3 temp(v1);
	return temp += v2;
}
