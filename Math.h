#pragma once
#include <cmath>
#include "Defines.h"

// Arithmetic
Vector2 Add(const Vector2& a, const Vector2& b) { return Vector2(a.x + b.x, a.y + b.y); }
Vector3 Add(const Vector3& a, const Vector3& b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }

Vector2 Subtract(const Vector2& a, const Vector2& b) { return Vector2(a.x - b.x, a.y - b.y); }
Vector3 Subtract(const Vector3& a, const Vector3& b) { return Vector3(a.x - b.x, a.y - b.y, a.z - b.z); }

Vector2 Multiply(const Vector2& a, const Vector2& b){ return Vector2(a.x * b.x, a.y * b.y); }
Vector3 Multiply(const Vector3& a, const Vector3& b){ return Vector3(a.x * b.x, a.y * b.y, a.z * b.z); }

Vector2 Divide(const Vector2& a, const Vector2& b) {
	if (b.x == 0 || b.y == 0) return Vector2::zero();
	return Vector2(a.x * ( 1 / b.x), a.y * (1 / b.y));
}
Vector3 Divide(const Vector3& a, const Vector3& b) {
	if (b.x == 0 || b.y == 0 || b.z == 0) return Vector3::zero();
	return Vector3(a.x * (1 / b.x), a.y * (1 / b.y), a.z * (1 / b.z));
}

// Vector Algebra
float DotProduct(const Vector3& v1, const Vector3& v2) {
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector3 CrossProduct(const Vector3& v1, const Vector3& v2) {
	return Vector3{
		(v1.y * v2.z) - (v1.z * v2.y),
		(v1.z * v2.x) - (v1.x * v2.z),
		(v1.z * v2.y) - (v1.y * v2.x)
	};
}

float Magnitude(const Vector3& v) {
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

Vector3 Normalize(const Vector3& v) {
	return (v / Magnitude(v));
}