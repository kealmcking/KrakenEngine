#pragma once
#include "Defines.h"
#include <cmath>

#pragma region Vector3 operators
inline Vector3 operator * (const Vector3& v, float s) {
	return (Vector3(v.x * s, v.y * s, v.z * s));
}

inline Vector3 operator / (const Vector3& v, float s) {
	s = 1.0f / s;
	return (Vector3(v.x * s, v.y * s, v.z * s));
}

inline Vector3 operator - (const Vector3& v) {
	return (Vector3(-v.x, -v.y, -v.z));
}
#pragma endregion

inline float Magnitude(const Vector3& v) {
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3 Normalize(const Vector3& v) {
	return (v / Magnitude(v));
}