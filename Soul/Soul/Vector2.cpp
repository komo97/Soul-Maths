#include "Vector2.h"
#include <array>

using namespace SoulMaths;

Vector2::Vector2() : Vector(2), x(values[0]), y(values[1]), xy(values[0], values[1])
{
	values[0] = 0;
	values[1] = 0;
}

SoulMaths::Vector2::Vector2(float x, float y) : Vector2()
{
	values[0] = x;
	values[1] = y;
}

SoulMaths::Vector2::Vector2(const Vector2 & cpy) : Vector2()
{
	values[0] = cpy.x;
	values[1] = cpy.y;
}

SoulMaths::Vector2::Vector2(const Swizzle2 & xy) : Vector2()
{
	values[0] = xy.val1;
	values[1] = xy.val2;
}


Vector2::~Vector2()
{
}

Vector2 & SoulMaths::Vector2::operator+=(const Vector2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 & SoulMaths::Vector2::operator-=(const Vector2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2 & SoulMaths::Vector2::operator*=(const Vector2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

Vector2 & SoulMaths::Vector2::operator*=(const float & rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

Vector2 & SoulMaths::Vector2::operator/=(const float & rhs)
{
	if (rhs <= 0)
		return *this;
	x /= rhs;
	y /= rhs;
	return *this;
}

Vector2 SoulMaths::Vector2::operator*(const Vector2 & rhs) const
{
	return Vector2();
}

Vector2 SoulMaths::Vector2::operator+(const Vector2 & rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 SoulMaths::Vector2::operator-(const Vector2 & rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 SoulMaths::Vector2::operator/(const float & rhs) const
{
	if (rhs <= 0)
		return Vector2(x, y);
	return Vector2(x / rhs, y / rhs);
}

Vector2 SoulMaths::Vector2::operator*(const float & rhs) const
{
	return Vector2(x * rhs, y * rhs);
}

Vector2& SoulMaths::Vector2::operator=(const Vector2 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

bool SoulMaths::Vector2::operator==(const Vector2 & rhs)
{
	return x == rhs.x && y == rhs.y;
}

bool SoulMaths::Vector2::operator!=(const Vector2 & rhs)
{
	return !(*this == rhs);
}

bool SoulMaths::Vector2::operator<(const Vector2 & rhs)
{
	return Magnitude() < rhs.Magnitude();
}

bool SoulMaths::Vector2::operator>(const Vector2 & rhs)
{
	return Magnitude() > rhs.Magnitude();
}

bool SoulMaths::Vector2::operator<=(const Vector2 & rhs)
{
	return (*this < rhs) || (*this == rhs);
}

bool SoulMaths::Vector2::operator>=(const Vector2 & rhs)
{
	return (*this > rhs) || (*this == rhs);
}

float SoulMaths::Vector2::Distance(const Vector2 & rhs)
{
	return sqrt(pow(rhs.x - x,2) + pow(rhs.y - y, 2));
}

float SoulMaths::Vector2::Distance(const Vector2 & lhs, const Vector2 & rhs)
{
	return sqrt(pow(rhs.x - lhs.x, 2) + pow(rhs.y - lhs.y, 2));
}

float SoulMaths::Vector2::DistanceSqr(const Vector2 & rhs)
{
	return (pow(rhs.x - x, 2) + pow(rhs.y - y, 2));
}

float SoulMaths::Vector2::DistanceSqr(const Vector2 & lhs, const Vector2 & rhs)
{
	return (pow(rhs.x - lhs.x, 2) + pow(rhs.y - lhs.y, 2));
}

float SoulMaths::Vector2::Dot(const Vector2 & rhs)
{
	return (x * rhs.x) + (y * rhs.y);
}

float SoulMaths::Vector2::Dot(const Vector2 & lhs, const Vector2 & rhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

Vector2 SoulMaths::Vector2::Normalize() const
{
	float mag = Magnitude();
	return Vector2(x / mag, y / mag);
}

float SoulMaths::Vector2::Magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float SoulMaths::Vector2::MagnitudeSqr() const
{
	return (pow(x, 2) + pow(y, 2));
}

Vector2 & SoulMaths::Vector2::Scale(const float & scale, const Axis & axis)
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
		break;
	case Axis::AxisW:
		break;
	case Axis::AxisXY:
		x *= scale;
		y *= scale;
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

Vector2 & SoulMaths::Vector2::Scale(const Vector2 & scale)
{
	*this *= scale;
	return *this;
}

Vector2 & SoulMaths::Vector2::Translate(const Vector2 & translate)
{
	*this += translate;
	return *this;
}

Vector2 & SoulMaths::Vector2::Rotate(const float & rotation)
{
	float sine = sin(deg2rad * rotation),
		cosine = cos(deg2rad * rotation);
	x = (x * cosine) + (y * (0 - sine));
	y = (x * sine) + (y * cosine);
	return *this;
}

SoulMaths::Vector2::operator Swizzle2()
{
	return Swizzle2(x, y);
}
