#pragma once
#include "RasterSurface.h"
#include "XTime.h"
#include <vector>

#define RASTER_WIDTH 1280
#define RASTER_HEIGHT 720
#define NUM_PIXELS (RASTER_WIDTH * RASTER_HEIGHT)
#define PI 3.14159265f

extern unsigned SCREEN_ARRAY[NUM_PIXELS];
static float DEPTH_BUFFER[NUM_PIXELS];

struct Vector1 {
	float x;
	Vector1() = default;

	Vector1(float a) {
		x = a;
	}

	float& operator [] (int i) { return((&x)[i]); }

	const float& operator [](int i) const { return ((&x)[i]); }
};

struct Vector2 {
	float x, y;

	Vector2() = default;

	Vector2(float a, float b) {
		x = a;
		y = b;
	}

	float& operator [] (int i) { return((&x)[i]); }

	const float& operator [](int i) const { return ((&x)[i]); }

	static Vector2 zero()		{ return Vector2(0.0f, 0.0f); }
	static Vector2 up()			{ return Vector2(0.0f, 1.0f); }
	static Vector2 right()		{ return Vector2(1.0f, 0.0f); }
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

	float& operator [] (int i) { return ((&x)[i]); }

	const float& operator [](int i) const { return ((&x)[i]); }

	static Vector3 zero()		{return Vector3(0.0f, 0.0f, 0.0f); }
	static Vector3 right()		{return Vector3(1.0f, 0.0f, 0.0f); }
	static Vector3 up()			{return Vector3(0.0f, 1.0f, 0.0f); }
	static Vector3 forward()	{return Vector3(0.0f, 0.0f, 1.0f); }
};

struct Vertex {
	float x, y, z, w;
	float u, v;
	float nx, ny, nz;

	Vertex() = default;

	Vertex(float _x, float _y, float _z, float _w, float _u, float _v, float _nx, float _ny, float _nz) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;

		u = _u;
		v = _v;

		nx = _nx;
		ny = _ny;
		nz = _nz;
	}
};

struct Triangle {
	// Vertices 
	Vertex a, b, c;

	// Lighting (Surface Normals)
	Vector3 face_normal;

	// Texturing (UV's)
	Vector2 a_uv, b_uv, c_uv;

	// Normal Mapping / Advanced Shading (Tangents/Bitangents)
	//Vector3 tangent;
	//Vector3 bi_tangent;

	// Materials / Color
	int material_id = 0;

	Triangle* neighbor_ab = nullptr;
	Triangle* neighbor_bc = nullptr;
	Triangle* neighbor_ca = nullptr;

	Triangle() = default;

	Triangle(Vertex& _a, Vertex& _b, Vertex& _c) : a(_a), b(_b), c(_c) { 

		a_uv = Vector2(a.u, a.v);
		b_uv = Vector2(b.u, b.v);
		c_uv = Vector2(c.u, c.v);

		

	}
};

struct Mesh {
	std::vector<Triangle> triangles;
};

inline Vector3 operator * (const Vector3& v, float s) { return (Vector3(v.x * s, v.y * s, v.z * s)); }

inline Vector3 operator / (const Vector3& v, float s) { return (Vector3(v.x * (1.0f / s), v.y * (1.0f / s), v.z * (1.0f / s))); }

inline Vector3 operator - (const Vector3& v) { return (Vector3(-v.x, -v.y, -v.z));}

