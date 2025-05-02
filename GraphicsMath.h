#pragma once
#include "Math.h"

class GraphicsMath
{
public:
	void PlotPixel(int x, int y, int z, unsigned color);
	void DrawLine(Vector3& a, Vector3& b);
	void DrawTriangle(Vector3& a, Vector3& b, Vector3& c);

	void CreateCube();
	void CreateGrid();
	void CreateSphere();

private:
};

