#pragma once

#include <assert.h>
#include <math.h>
#include <iostream>

class Vector4;

class Vector4
{
public:
	float X;
	float Y;
	float Z;
	float W;

public:
	Vector4() : X(0), Y(0), Z(0), W(1) {}
	Vector4(const Vector3& V, float InW = 1.0f);
	Vector4(float x, float y, float z, float w = 1.0f) : X(x), Y(y), Z(z), W(w) {}

public:
	inline Vector4 operator+(const Vector4& V) const;
	inline Vector4 operator-(const Vector4& V) const;	

	inline Vector4 operator*(const Vector4& V) const;
	inline Vector4 operator/(const Vector4& V) const;
	inline Vector4 operator*(float scale) const;
	inline Vector4 operator/(float scale) const;

	inline Vector4 operator-() const;

	inline Vector4 operator+=(const Vector4& V);
	inline Vector4 operator-=(const Vector4& V);
	inline Vector4 operator*=(float scale);

	inline Vector4 operator/=(float V);
	inline Vector4 operator/=(const Vector4& V);
	inline Vector4 operator*=(const Vector4& V);

	inline float& operator[](int index);
	inline float operator[](int index) const;

	inline bool operator==(const Vector4& V) const;
	inline bool operator!=(const Vector4& V) const;

public:
	inline bool Equals(const Vector4& V, float Tolerance = 1.e-4) const;
	//is nearly zero vector3
	inline bool IsNearlyZero(float Tolerance = 1.e-4) const;

	inline float Size() const;

	inline float SizeSquared() const;

	inline Vector4 GetNormal(float Tolerance = 1.e-8) const;	

	Vector3 GetVector3() const;
public:

	friend std::ostream& operator<<(std::ostream& out, const Vector4& V);
};

inline Vector4 Vector4::operator+(const Vector4 & V) const
{
	return Vector4(X + V.X, Y + V.Y, Z + V.Z, W + V.W);
}

inline Vector4 Vector4::operator-(const Vector4 & V) const
{
	return Vector4(X - V.X, Y - V.Y, Z - V.Z, W - V.W);
}

inline Vector4 Vector4::operator*(const Vector4 & V) const
{
	return Vector4(X * V.X, Y * V.Y, Z * V.Z, W * V.W);
}

inline Vector4 Vector4::operator/(const Vector4 & V) const
{
	return Vector4(X / V.X, Y / V.Y, Z / V.Z, W / V.W);
}

inline Vector4 Vector4::operator*(float scale) const
{
	return Vector4(X * scale, Y * scale, Z * scale, W * scale);
}

inline Vector4 Vector4::operator/(float scale) const
{
	const float RScale = 1.f / scale;
	return Vector4(X * RScale, Y * RScale, Z * RScale, W * RScale);
}

inline Vector4 Vector4::operator-() const
{
	return Vector4(-X, -Y, -Z, -W);
}

inline Vector4 Vector4::operator+=(const Vector4 & V)
{
	X += V.X; Y += V.Y; Z += V.Z; W += V.W;
	return *this;
}

inline Vector4 Vector4::operator-=(const Vector4 & V)
{
	X -= V.X; Y -= V.Y; Z -= V.Z; W -= V.W;
	return *this;
}

inline Vector4 Vector4::operator*=(float scale)
{
	X *= scale; Y *= scale; Z *= scale; W *= scale;
	return *this;
}

inline Vector4 Vector4::operator/=(float V)
{
	const float RV = 1.f / V;
	*this *= RV;
	return *this;
}

inline Vector4 Vector4::operator/=(const Vector4 & V)
{
	X /= V.X; Y /= V.Y; Z /= V.Z; W /= V.W;
	return *this;
}

inline Vector4 Vector4::operator*=(const Vector4 & V)
{
	X *= V.X; Y *= V.Y; Z *= V.Z; W *= V.W;
	return *this;
}

inline float & Vector4::operator[](int index)
{
	assert(index >= 0 && index < 4);
	return (&X)[index];
}

inline float Vector4::operator[](int index) const
{
	assert(index >= 0 && index < 4);
	return (&X)[index];
}

inline bool Vector4::operator==(const Vector4 & V) const
{
	return X == V.X && Y == V.Y && Z == V.Z && W == V.W;
}

inline bool Vector4::operator!=(const Vector4 & V) const
{
	return X != V.X || Y != V.Y || Z != V.Z || W != V.W;
}

inline bool Vector4::Equals(const Vector4 & V, float Tolerance) const
{
	return abs(X - V.X) <= Tolerance && abs(Y - V.Y) <= Tolerance && abs(Z - V.Z) <= Tolerance && abs(W - V.W) <= Tolerance;
}

inline bool Vector4::IsNearlyZero(float Tolerance) const
{
	return abs(X) <= Tolerance && abs(Y) <= Tolerance && abs(Z) <= Tolerance;
}

inline float Vector4::Size() const
{
	return sqrt(X * X + Y * Y + Z * Z + W * W);
}

inline float Vector4::SizeSquared() const
{
	return X * X + Y * Y + Z * Z + W * W;
}

inline Vector4 Vector4::GetNormal(float Tolerance) const
{
	const float SquareSum = X * X + Y * Y + Z * Z;	
	if (SquareSum > Tolerance)
	{
		const float Scale = 1.0f / sqrtf(SquareSum);
		return Vector4(X * Scale, Y * Scale, Z * Scale, 0.0f);		
	}
	return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
}

inline Vector3 Vector4::GetVector3() const
{
	return Vector3(X, Y, Z);
}
