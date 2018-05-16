#pragma once
#include "Vector.h"

namespace SoulMaths
{
	class Vector4 : Vector
	{
	public:
		Vector4();
		~Vector4();
		Vector4(float x, float y, float z, float w);
		Vector4(const Vector4& cpy);
		Vector4(const Swizzle4& xyzw);
		Swizzle2 xy, yz, xz, xw, yw;
		Swizzle3 xyz, yzw;
		Swizzle4 xyzw;
		float &x,
			&y,
			&z,
			&w,
			&r,
			&g,
			&b,
			&a;
	};

};
