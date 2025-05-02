#pragma once
#include "Defines.h"

class Camera
{
public:
	Vector3 position;
	Vector2 camRot;

	float nearZ;
	float farZ;
	float fovDeg;
	float aspectRatio = RASTER_WIDTH / RASTER_HEIGHT;

	float translationSpeed;
	float rotationSpeed;

	Vector3 targetPos;
};

