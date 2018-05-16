#pragma once
#include <memory>
#include <vector>
namespace SoulMaths {
	class Vector2;
	class Vector3;
	class Vector4;
	
	class Matrix2;
	class Matrix3;
	class Matrix4;

	class Vector
	{
	public:
		float operator[](const size_t& index) const;
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
		operator Vector3();
	}Swizzle3;

	typedef struct Swizzle4
	{
		float	&val1,
				&val2,
				&val3,
				&val4;
		Swizzle4& operator=(const Swizzle4& rhs);
		Swizzle4(float& v1, float& v2, float& v3, float& v4);
		operator Vector4();
	}Swizzle4;
};