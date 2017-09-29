#pragma once

class Vector2D
{
public:
	float x = 0.0f;
	float y = 0.0f;

	Vector2D() : x(0.0f), y(0.0f) {}
	Vector2D(float  in_x, float in_y) : x(in_x), y(in_y) {}
};