#include "Vector3.h"

const Vector3 Vector3::ZeroVector(0, 0, 0);
const Vector3 Vector3::OneVector(1.f, 1.f, 1.f);
const Vector3 Vector3::ForwardVector(1.f, 0, 0);
const Vector3 Vector3::RightVector(0, 1.f, 0);
const Vector3 Vector3::UpVector(0, 0, 1.f);

Vector3 Vector3::CrossProduct(const Vector3 & A, const Vector3 & B)
{
	return A ^ B;
}

float Vector3::DotProduct(const Vector3 & A, const Vector3 & B)
{
	return A | B;
}

std::ostream & operator<<(std::ostream & out, const Vector3 & V)
{
	out << "(" << V.X << ", " << V.Y << ", " << V.Z << ")";
	return out;
}