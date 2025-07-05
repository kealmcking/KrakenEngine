#include "MathFunctions.h"

using namespace GLOBAL;

namespace MATH {

	float DISTANCE(VECTOR3 a, VECTOR3 b) {
		VECTOR3 delta(b.x - a.x, b.y - a.y, b.z - a.z);

		float sum_of_squares =
			delta.x * delta.x +
			delta.y * delta.y +
			delta.z * delta.z;

		return std::sqrt(sum_of_squares);
	}
}