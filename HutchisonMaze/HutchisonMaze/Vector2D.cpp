#include "Vector2D.h"

const Vector2D Vector2D::Zero = Vector2D();

void Vector2D::operator+=(const Vector2D& pVector)
{
	x += pVector.x;
	y += pVector.y;
}

void Vector2D::operator-=(const Vector2D& pVector)
{
	x -= pVector.x;
	y -= pVector.y;
}

void Vector2D::operator*=(const float& num)
{
	x *= num;
	y *= num;
}

void Vector2D::operator/=(const float& num)
{
	x /= num;
	y /= num;
}

void Vector2D::operator=(const Vector2D& pVector)
{
	x = pVector.x;
	y = pVector.y;
}

bool Vector2D::operator==(const Vector2D& vector) const
{
	return x == vector.x && y == vector.y;
}

bool Vector2D::operator!=(const Vector2D& vector) const
{
	return x != vector.x || y != vector.y;
}

Vector2D Vector2D::operator+(const Vector2D& pVector) const
{
	return Vector2D(x + pVector.x, y + pVector.y);
}

Vector2D Vector2D::operator-(const Vector2D& pVector) const
{
	return Vector2D(x - pVector.x, y - pVector.y);
}

Vector2D Vector2D::operator*(const float& num) const
{
	return Vector2D(x * num, y * num);
}

Vector2D Vector2D::operator/(const float& num) const
{
	return Vector2D(x / num, y / num);
}

Vector2D Vector2D::operator*(const Vector2D& vector) const
{
	return Vector2D(x * vector.x, y * vector.y);
}

Vector2D Vector2D::operator/(const Vector2D& vector) const
{
	return Vector2D(x / vector.x, y / vector.y);
}

