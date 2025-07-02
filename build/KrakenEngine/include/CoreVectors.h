#pragma once
#include <cmath>

namespace GLOBAL {

	struct VECTOR2 {
		float x, y;
	
		VECTOR2(float _x, float _y) {
			x = _x;
			y = _y;
		}
	};

	struct VECTOR3 {
		float x, y, z;

		VECTOR3(float _x, float _y, float _z) {
			x = _x;
			y = _y;
			z = _z;
		}

		VECTOR3() = default;
	};

	struct VECTOR4 {
		float x, y, z, w;

		VECTOR4(float _x, float _y, float _z, float _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
	
	};

	struct QUATERNION {
		double x, y, z, w;

		
		QUATERNION(double _x, double _y, double _z, double _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

		QUATERNION() = default;
	};

	struct TRANSFORM { 
		VECTOR3 position; QUATERNION rotation; VECTOR3 scale; 
	
		TRANSFORM(VECTOR3 _position, QUATERNION _rotation, VECTOR3 _scale) {
			position = _position;
			rotation = _rotation;
			scale = _scale;
		}
	};
}