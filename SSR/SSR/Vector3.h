#pragma once

#include <assert.h>
#include <math.h>
#include <iostream>

//左手系 x向前 y向右 z向上
class Vector3
{
public:
	float X;
	float Y;
	float Z;

public:
	Vector3() : X(0),Y(0),Z(0) {}
	Vector3(float value) : X(value), Y(value), Z(value) {}
	Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}

public:
	//0,0,0
	static const Vector3 ZeroVector;
	//1,1,1
	static const Vector3 OneVector;
	//0,0,1
	static const Vector3 UpVector;
	//1,0,0
	static const Vector3 ForwardVector;
	//0,1,0
	static const Vector3 RightVector;

public:
	inline Vector3 operator+(const Vector3& V) const;
	inline Vector3 operator-(const Vector3& V) const;
	inline Vector3 operator+(float Bias) const;
	inline Vector3 operator-(float Bias) const;

	inline Vector3 operator*(const Vector3& V) const;
	inline Vector3 operator/(const Vector3& V) const;
	inline Vector3 operator*(float scale) const;
	inline Vector3 operator/(float scale) const;

	inline Vector3 operator-() const;

	inline Vector3 operator+=(const Vector3& V);
	inline Vector3 operator-=(const Vector3& V);
	inline Vector3 operator*=(float scale);

	inline Vector3 operator/=(float V);
	inline Vector3 operator/=(const Vector3& V);
	inline Vector3 operator*=(const Vector3& V);

	inline float& operator[](int index);
	inline float operator[](int index) const;

	inline bool operator==(const Vector3& V) const;
	inline bool operator!=(const Vector3& V) const;

public:
	inline bool Equals(const Vector3& V, float Tolerance = 1.e-4) const;

	inline bool IsNearlyZero(float Tolerance = 1.e-4) const;	

	inline float Size() const;

	inline float SizeSquared() const;

	inline Vector3 GetNormal(float Tolerance = 1.e-8) const;

	inline bool Normalize(float Tolerance = 1.e-8);

public:
	inline Vector3 operator^(const Vector3& V) const;
	static Vector3 CrossProduct(const Vector3& A, const Vector3& B);

	inline float operator|(const Vector3& V) const;
	static float DotProduct(const Vector3& A, const Vector3& B);
	
	friend std::ostream& operator<<(std::ostream& out, const Vector3& V);
};

inline Vector3 Vector3::operator+(const Vector3 & V) const
{
	return Vector3(X + V.X, Y + V.Y, Z + V.Z);
}

inline Vector3 Vector3::operator-(const Vector3 & V) const
{
	return Vector3(X - V.X, Y - V.Y, Z - V.Z);
}

inline Vector3 Vector3::operator+(float Bias) const
{
	return Vector3(X + Bias, Y + Bias, Z + Bias);
}

inline Vector3 Vector3::operator-(float Bias) const
{
	return Vector3(X - Bias, Y - Bias, Z - Bias);
}

inline Vector3 Vector3::operator*(const Vector3 & V) const
{
	return Vector3(X * V.X, Y * V.Y, Z * V.Z);
}

inline Vector3 Vector3::operator/(const Vector3 & V) const
{
	return Vector3(X / V.X, Y / V.Y, Z / V.Z);
}

inline Vector3 Vector3::operator*(float scale) const
{
	return Vector3(X * scale, Y * scale, Z * scale);
}

inline Vector3 Vector3::operator/(float scale) const
{
	return Vector3(X / scale, Y / scale, Z / scale);
}

inline Vector3 Vector3::operator-() const
{
	return Vector3(-X, -Y, -Z);
}

inline Vector3 Vector3::operator+=(const Vector3 & V)
{
	X += V.X; Y += V.Y; Z += V.Z;
	return *this;
}

inline Vector3 Vector3::operator-=(const Vector3 & V)
{
	X -= V.X; Y -= V.Y; Z -= V.Z;
	return *this;
}

inline Vector3 Vector3::operator*=(float scale)
{
	X *= scale; Y *= scale; Z *= scale;
	return *this;
}

inline Vector3 Vector3::operator/=(float V)
{
	const float RV = 1.f / V;
	*this *= RV;
	return *this;
}

inline Vector3 Vector3::operator/=(const Vector3 & V)
{
	X /= V.X; Y /= V.Y; Z /= V.Z;
	return *this;
}

inline Vector3 Vector3::operator*=(const Vector3 & V)
{
	X *= V.X; Y *= V.Y; Z *= V.Z;
	return *this;
}

inline float & Vector3::operator[](int index)
{
	assert(index >= 0 && index < 3);
	return (&X)[index];
}

inline float Vector3::operator[](int index) const
{
	assert(index >= 0 && index < 3);
	return (&X)[index];
}

inline bool Vector3::operator==(const Vector3 & V) const
{
	return X == V.X && Y == V.Y && Z == V.Z;
}

inline bool Vector3::operator!=(const Vector3 & V) const
{
	return X != V.X || Y != V.Y || Z != V.Z;
}

inline bool Vector3::Equals(const Vector3 & V, float Tolerance) const
{
	return abs(X - V.X) <= Tolerance && abs(Y - V.Y) <= Tolerance && abs(Z - V.Z) <= Tolerance;
}

inline bool Vector3::IsNearlyZero(float Tolerance) const
{
	return abs(X) <= Tolerance && abs(Y) <= Tolerance && abs(Z) <= Tolerance;
}

inline bool Vector3::Normalize(float Tolerance)
{
	const float SquareSum = X * X + Y * Y + Z * Z;
	if (SquareSum > Tolerance)
	{
		const float Scale = 1.0f / sqrtf(SquareSum);
		*this *= Scale;
		return true;
	}
	return false;
}

inline float Vector3::Size() const
{
	return sqrt(X * X + Y * Y + Z * Z);
}

inline float Vector3::SizeSquared() const
{
	return X * X + Y * Y + Z * Z;
}

inline Vector3 Vector3::GetNormal(float Tolerance) const
{
	const float SquareSum = this->SizeSquared();
	if (SquareSum == 1.0f)
	{
		return *this;
	}
	else if (SquareSum < Tolerance)
	{
		return Vector3::ZeroVector;
	}
	const float Scale = 1.0f / sqrtf(SquareSum);
	return Vector3(X * Scale, Y * Scale, Z * Scale);
}

inline Vector3 Vector3::operator^(const Vector3 & V) const
{
	return Vector3
	(
		Y * V.Z - Z * V.Y,
		Z * V.X - X * V.Z,
		X * V.Y - Y * V.X
	);
}

inline float Vector3::operator|(const Vector3 & V) const
{
	return X * V.X + Y * V.Y + Z * V.Z;
}