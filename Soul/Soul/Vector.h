#pragma once
#include <memory>
#include <vector>
namespace SoulMaths {
	class Vector2;

	class Vector
	{
	protected:
		Vector(const size_t& size);
		std::vector<float> values;
	};

	typedef struct Swizzle2
	{
		float	&val1,
				&val2;
		Swizzle2& operator=(const Swizzle2& rhs);
		Swizzle2(float& v1, float& v2);
		operator Vector2();
	}Swizzle2;

	typedef struct Swizzle3
	{
		float	&val1,
				&val2,
				&val3;
		Swizzle3& operator=(const Swizzle3& rhs);
		Swizzle3(float& v1, float& v2, float& v3);
	}Swizzle3;

	typedef struct Swizzle4
	{
		float	&val1,
				&val2,
				&val3,
				&val4;
		Swizzle4& operator=(const Swizzle4& rhs);
		Swizzle4(float& v1, float& v2, float& v3, float& v4);
	}Swizzle4;
};