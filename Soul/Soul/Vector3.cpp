#include "Vector3.h"

using namespace SoulMaths;

Vector3::Vector3() : Vector(3), x(values[0]),
		y(values[1]), z(values[2]),
		r(values[0]), g(values[1]),
		b(values[2]),
		xy(values[0], values[1]), 
		xz(values[0], values[2]),
		yz(values[1], values[2]),
		xyz(values[0], values[1], values[2])
{
	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
}


Vector3::~Vector3()
{
}

SoulMaths::Vector3::Vector3(float x, float y, float z) : Vector3()
{
	values[0] = x;
	values[1] = y;
	values[2] = z;
}

SoulMaths::Vector3::Vector3(const Vector3 & cpy) : Vector3()
{
	values[0] = cpy.x;
	values[1] = cpy.y;
	values[2] = cpy.z;
}

SoulMaths::Vector3::Vector3(const Swizzle3 & xyz) : Vector3()
{
	values[0] = xyz.val1;
	values[1] = xyz.val2;
	values[2] = xyz.val3;
}

Vector3 & SoulMaths::Vector3::operator+=(const Vector3 & rhs)
{
	values[0] += rhs.x;
	values[1] += rhs.y;
	values[2] += rhs.z;
	return *this;
}

Vector3 & SoulMaths::Vector3::operator-=(const Vector3 & rhs)
{
	values[0] -= rhs.x;
	values[1] -= rhs.y;
	values[2] -= rhs.z;
	return *this;
}

Vector3 & SoulMaths::Vector3::operator*=(const Vector3 & rhs)
{
	values[0] *= rhs.x;
	values[1] *= rhs.y;
	values[2] *= rhs.z;
	return *this;
}

Vector3 & SoulMaths::Vector3::operator*=(const float & rhs)
{
	values[0] *= rhs;
	values[1] *= rhs;
	values[2] *= rhs;
	return *this;
}

Vector3 & SoulMaths::Vector3::operator/=(const float & rhs)
{
	if (rhs <= 0)
		return *this;
	values[0] /= rhs;
	values[1] /= rhs;
	values[2] /= rhs;
	return *this;
}

Vector3 SoulMaths::Vector3::operator*(const Vector3 & rhs) const
{
	return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
}

Vector3 SoulMaths::Vector3::operator+(const Vector3 & rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 SoulMaths::Vector3::operator-(const Vector3 & rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 SoulMaths::Vector3::operator/(const float & rhs) const
{
	return Vector3(x / rhs, y / rhs, z / rhs);
}

Vector3 SoulMaths::Vector3::operator*(const float & rhs) const
{
	if (rhs <= 0)
		return Vector3(x, y, z);
	return Vector3(x * rhs, y * rhs, z * rhs);
}

Vector3 & SoulMaths::Vector3::operator=(const Vector3 & rhs)
{
	values[0] = rhs.x;
	values[1] = rhs.y;
	values[2] = rhs.z;
	return *this;
}

bool SoulMaths::Vector3::operator==(const Vector3 & rhs)
{
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

bool SoulMaths::Vector3::operator!=(const Vector3 & rhs)
{
	return !(*this == rhs);
}

bool SoulMaths::Vector3::operator<(const Vector3 & rhs)
{
	return Magnitude() < rhs.Magnitude();
}

bool SoulMaths::Vector3::operator>(const Vector3 & rhs)
{
	return Magnitude() > rhs.Magnitude();
}

bool SoulMaths::Vector3::operator<=(const Vector3 & rhs)
{
	return (*this < rhs) || (*this == rhs);
}

bool SoulMaths::Vector3::operator>=(const Vector3 & rhs)
{
	return (*this > rhs) || (*this == rhs);
}

float SoulMaths::Vector3::Distance(const Vector3 & rhs)
{
	return sqrt(pow(rhs.x - x, 2) + pow(rhs.y - y, 2) + pow(rhs.z - z, 2));
}

float SoulMaths::Vector3::Distance(const Vector3 & lhs, const Vector3 & rhs)
{
	return sqrt(pow(rhs.x - lhs.x, 2) + pow(rhs.y - lhs.y, 2) + pow(rhs.z - lhs.z, 2));
}

float SoulMaths::Vector3::DistanceSqr(const Vector3 & rhs)
{
	return (pow(rhs.x - x, 2) + pow(rhs.y - y, 2) + pow(rhs.z - z, 2));
}

float SoulMaths::Vector3::DistanceSqr(const Vector3 & lhs, const Vector3 & rhs)
{
	return (pow(rhs.x - lhs.x, 2) + pow(rhs.y - lhs.y, 2) + pow(rhs.z - lhs.z, 2));
}

float SoulMaths::Vector3::Dot(const Vector3 & rhs)
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}

float SoulMaths::Vector3::Dot(const Vector3 & lhs, const Vector3 & rhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector3 SoulMaths::Vector3::Normalize() const
{
	float mag = Magnitude();
	return Vector3(x / mag, y / mag, y / mag);
}

float SoulMaths::Vector3::Magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float SoulMaths::Vector3::MagnitudeSqr() const
{
	return (pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3 & SoulMaths::Vector3::Scale(const float & scale, const Axis & axis)
{
	switch (axis)
	{
	case Axis::AxisX:
		x *= scale;
		break;
	case Axis::AxisY:
		y *= scale;
		break;
	case Axis::AxisZ:
		z *= scale;
		break;
	case Axis::AxisW:
		break;
	case Axis::AxisXY:
		x *= scale;
		y *= scale;
		break;
	case Axis::AxisXZ:
		x *= scale;
		z *= scale;
		break;
	case Axis::AxisXW:
		break;
	case Axis::AxisYZ:
		y *= scale;
		z *= scale;
		break;
	case Axis::AxisYW:
		break;
	case Axis::AxisZW:
		break;
	case Axis::AxisXYZ:
		x *= scale;
		y *= scale;
		z *= scale;
		break;
	case Axis::AxisXYW:
		break;
	case Axis::AxisXZW:
		break;
	case Axis::AxisYZW:
		break;
	case Axis::AxisXYZW:
		break;
	default:
		break;
	}
	return *this;
}

Vector3 & SoulMaths::Vector3::Scale(const Vector3 & scale)
{
	*this *= scale;
	return *this;
}

Vector3 & SoulMaths::Vector3::Translate(const Vector3 & translate)
{
	*this += translate;
	return *this;
}

Vector3 & SoulMaths::Vector3::Rotate(const float & rotation, const Axis & axis)
{
	switch (axis)
	{
	case Axis::AxisX:
		break;
	case Axis::AxisY:
		break;
	case Axis::AxisZ:
		break;
	case Axis::AxisW:
		break;
	case Axis::AxisXY:
		break;
	case Axis::AxisXZ:
		break;
	case Axis::AxisXW:
		break;
	case Axis::AxisYZ:
		break;
	case Axis::AxisYW:
		break;
	case Axis::AxisZW:
		break;
	case Axis::AxisXYZ:
		break;
	case Axis::AxisXYW:
		break;
	case Axis::AxisXZW:
		break;
	case Axis::AxisYZW:
		break;
	case Axis::AxisXYZW:
		break;
	default:
		break;
	}
	return *this;
}

SoulMaths::Vector3::operator Swizzle3()
{
	return Swizzle3(x, y, z);
}
