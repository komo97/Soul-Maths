#include "Vector.h"
#include "Vector2.h"

using namespace SoulMaths;

Swizzle2 & SoulMaths::Swizzle2::operator=(const Swizzle2 & rhs)
{
	this->val1 = rhs.val1;
	this->val2 = rhs.val2;
	return *this;
}

SoulMaths::Swizzle2::Swizzle2(float & v1, float & v2) : val1(v1), val2(v2)
{
}

SoulMaths::Swizzle2::operator Vector2()
{
	return Vector2(val1, val2);
}

Swizzle3 & SoulMaths::Swizzle3::operator=(const Swizzle3 & rhs)
{
	this->val1 = rhs.val1;
	this->val2 = rhs.val2;
	this->val3 = rhs.val3;
	return *this;
}

SoulMaths::Swizzle3::Swizzle3(float & v1, float & v2, float & v3) : val1(v1), val2(v2), val3(v3)
{
}

Swizzle4 & SoulMaths::Swizzle4::operator=(const Swizzle4 & rhs)
{
	this->val1 = rhs.val1;
	this->val2 = rhs.val2;
	this->val3 = rhs.val3;
	this->val4 = rhs.val4;
	return *this;
}

SoulMaths::Swizzle4::Swizzle4(float & v1, float & v2, float & v3, float & v4) : val1(v1), val2(v2), val3(v3), val4(v4)
{
}

SoulMaths::Vector::Vector(const size_t & size)
{
	values.resize(size);
}
