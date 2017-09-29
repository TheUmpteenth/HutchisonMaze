#pragma once

class Vector2D
{
public:
	float x = 0.0f;
	float y = 0.0f;

	Vector2D() : x(0.0f), y(0.0f) {}
	Vector2D(float  in_x, float in_y) : x(in_x), y(in_y) {}
	Vector2D(const Vector2D& in_vec) : x(in_vec.x), y(in_vec.y) {}
	static const Vector2D Vector2D::Zero;

	Vector2D operator+(const Vector2D& pVector) const;
	Vector2D operator-(const Vector2D& pVector) const;
	Vector2D operator*(const float& num) const;
	Vector2D operator/(const float& num) const;
	Vector2D operator*(const Vector2D& vector) const;
	Vector2D operator/(const Vector2D& vector) const;
	void operator+=(const Vector2D& pVector);
	void operator-=(const Vector2D& pVector);
	void operator*=(const float& num);
	void operator/=(const float& num);
	void operator=(const Vector2D& pVector);
	bool operator==(const Vector2D& vector) const;
	bool operator!=(const Vector2D& vector) const;

};