#include "Vector2.h"
#include "Vector3.h"

const Vector2 Vector2::ZeroVector(0, 0);
const Vector2 Vector2::OneVector(1.f, 1.f);

Vector2::Vector2(const Vector3& V)
	: X(V.X)
	, Y(V.Y)
{

}

float Vector2::CrossProduct(const Vector2 & A, const Vector2 & B)
{
	return A ^ B;
}

float Vector2::DotProduct(const Vector2 & A, const Vector2 & B)
{
	return A | B;
}


std::ostream & operator<<(std::ostream & out, const Vector2 & V)
{
	out << "(" << V.X << ", " << V.Y << ")";
	return out;
}
