#pragma once
#include <assert.h>
#include <iostream>
#include "Vector2.h"

class Vector3;

class Vector2
{
public:
	float X;
	float Y;	

public:
	Vector2() : X(0), Y(0) {}
	Vector2(float value) : X(value), Y(value){}
	Vector2(float x, float y) : X(x), Y(y) {}

	explicit Vector2(const Vector3& V);

public:
	//0,0
	static const Vector2 ZeroVector;
	//1,1
	static const Vector2 OneVector;	

public:
	inline Vector2 operator+(const Vector2& V) const;
	inline Vector2 operator-(const Vector2& V) const;
	inline Vector2 operator+(float Bias) const;
	inline Vector2 operator-(float Bias) const;

	inline Vector2 operator*(const Vector2& V) const;
	inline Vector2 operator/(const Vector2& V) const;
	inline Vector2 operator*(float scale) const;
	inline Vector2 operator/(float scale) const;

	inline Vector2 operator-() const;

	inline Vector2 operator+=(const Vector2& V);
	inline Vector2 operator-=(const Vector2& V);
	inline Vector2 operator*=(float scale);

	inline Vector2 operator/=(float V);
	inline Vector2 operator/=(const Vector2& V);
	inline Vector2 operator*=(const Vector2& V);

	inline float& operator[](int index);
	inline float operator[](int index) const;

	inline bool operator==(const Vector2& V) const;
	inline bool operator!=(const Vector2& V) const;

public:
	inline bool Equals(const Vector2& V, float Tolerance = 1.e-4) const;

	inline bool IsNearlyZero(float Tolerance = 1.e-4) const;

	inline float Size() const;

	inline float SizeSquared() const;

	inline Vector2 GetNormal(float Tolerance = 1.e-8) const;

	inline bool Normalize(float Tolerance = 1.e-8);

public:
	inline float operator^(const Vector2& V) const;
	static float CrossProduct(const Vector2& A, const Vector2& B);

	inline float operator|(const Vector2& V) const;
	static float DotProduct(const Vector2& A, const Vector2& B);

	friend std::ostream& operator<<(std::ostream& out, const Vector2& V);
};

inline Vector2 Vector2::operator+(const Vector2 & V) const
{
	return Vector2(X + V.X, Y + V.Y);
}

inline Vector2 Vector2::operator-(const Vector2 & V) const
{
	return Vector2(X - V.X, Y - V.Y);
}

inline Vector2 Vector2::operator+(float Bias) const
{
	return Vector2(X + Bias, Y + Bias);
}

inline Vector2 Vector2::operator-(float Bias) const
{
	return Vector2(X - Bias, Y - Bias);
}

inline Vector2 Vector2::operator*(const Vector2 & V) const
{
	return Vector2(X * V.X, Y * V.Y);
}

inline Vector2 Vector2::operator/(const Vector2 & V) const
{
	return Vector2(X / V.X, Y / V.Y);
}

inline Vector2 Vector2::operator*(float scale) const
{
	return Vector2(X * scale, Y * scale);
}

inline Vector2 Vector2::operator/(float scale) const
{
	return Vector2(X / scale, Y / scale);
}

inline Vector2 Vector2::operator-() const
{
	return Vector2(-X, -Y);
}

inline Vector2 Vector2::operator+=(const Vector2 & V)
{
	X += V.X; Y += V.Y;
	return *this;
}

inline Vector2 Vector2::operator-=(const Vector2 & V)
{
	X -= V.X; Y -= V.Y;
	return *this;
}

inline Vector2 Vector2::operator*=(float scale)
{
	X *= scale; Y *= scale;
	return *this;
}

inline Vector2 Vector2::operator/=(float V)
{
	const float RV = 1.f / V;
	*this *= RV;
	return *this;
}

inline Vector2 Vector2::operator/=(const Vector2 & V)
{
	X /= V.X; Y /= V.Y;
	return *this;
}

inline Vector2 Vector2::operator*=(const Vector2 & V)
{
	X *= V.X; Y *= V.Y;
	return *this;
}

inline float & Vector2::operator[](int index)
{
	assert(index >= 0 && index < 2);
	return (&X)[index];
}

inline float Vector2::operator[](int index) const
{
	assert(index >= 0 && index < 2);
	return (&X)[index];
}

inline bool Vector2::operator==(const Vector2 & V) const
{
	return X == V.X && Y == V.Y;
}

inline bool Vector2::operator!=(const Vector2 & V) const
{
	return X != V.X || Y != V.Y;
}

inline bool Vector2::Equals(const Vector2 & V, float Tolerance) const
{
	return abs(X - V.X) <= Tolerance && abs(Y - V.Y) <= Tolerance;
}

inline bool Vector2::IsNearlyZero(float Tolerance) const
{
	return abs(X) <= Tolerance && abs(Y) <= Tolerance;
}

inline bool Vector2::Normalize(float Tolerance)
{
	const float SquareSum = X * X + Y * Y;
	if (SquareSum > Tolerance)
	{
		const float Scale = 1.0f / sqrtf(SquareSum);
		*this *= Scale;
		return true;
	}
	X = 0.0f;
	Y = 0.0f;
	return false;
}

inline float Vector2::Size() const
{
	return sqrt(X * X + Y * Y);
}

inline float Vector2::SizeSquared() const
{
	return X * X + Y * Y;
}

inline Vector2 Vector2::GetNormal(float Tolerance) const
{
	const float SquareSum = this->SizeSquared();	
	if (SquareSum < Tolerance)
	{
		return Vector2::ZeroVector;
	}
	const float Scale = 1.0f / sqrtf(SquareSum);
	return Vector2(X * Scale, Y * Scale);
}

inline float Vector2::operator^(const Vector2 & V) const
{
	return X * V.Y - Y * V.X;
}

inline float Vector2::operator|(const Vector2 & V) const
{
	return X * V.X + Y * V.Y;
}
