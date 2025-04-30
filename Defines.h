#pragma once

#define RASTER_WIDTH 1280
#define RASTER_HEIGHT 720
#define NUM_PIXELS (RASTER_WIDTH * RASTER_HEIGHT)

unsigned SCREEN_ARRAY[NUM_PIXELS];
static float DEPTH_BUFFER[NUM_PIXELS];


struct Vector2 {
	float x, y;

	Vector2() = default;

	Vector2(float a, float b) {
		x = a;
		y = b;
	}

	float& operator [] (int i) {
		return((&x)[i]);
	}

	const float& operator [](int i) const {
		return ((&x)[i]);
	}
};

struct Vector3 {
	float x, y, z;

	Vector3() = default;

	Vector3(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}

	// Scalar Multiplication (+)
	Vector3& operator *= (float s) {
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}

	// Scalar Multiplication (-)
	Vector3& operator /= (float s) {
		s = 1.0F / s;
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}

	float& operator [] (int i) {
		return ((&x)[i]);
	}

	const float& operator [](int i) const {
		return ((&x)[i]);
	}
};