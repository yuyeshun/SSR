#include "Vector3.h"
#include "Vector4.h"

Vector4::Vector4(const Vector3 & V, float InW)
	: X(V.X)
	, Y(V.Y)
	, Z(V.Z)
	, W(InW)
{
}

std::ostream & operator<<(std::ostream & out, const Vector4 & V)
{
	out << "(" << V.X << ", " << V.Y << ", " << V.Z << ", " << V.W << ")";
	return out;
}
