#pragma once
#include "Vector.h"
#include "SoulDefinitions.h"

namespace SoulMaths {

	class Vector3 : Vector
	{
	public:
		Vector3();
		~Vector3();
		Vector3(float x, float y, float z);
		Vector3(const Vector3& cpy);
		Vector3(const Swizzle3& xyz);
		Swizzle2 xy, yz, xz;
		Swizzle3 xyz;
		float &x,
			&y,
			&z,
			&r,
			&g,
			&b;
		Vector3& operator+=(const Vector3& rhs);
		Vector3& operator-=(const Vector3& rhs);
		Vector3& operator*=(const Vector3& rhs);
		Vector3& operator*=(const float& rhs);
		Vector3& operator/=(const float& rhs);
		Vector3 operator*(const Vector3& rhs) const;
		Vector3 operator+(const Vector3& rhs) const;
		Vector3 operator-(const Vector3& rhs) const;
		Vector3 operator/(const float& rhs) const;
		Vector3 operator*(const float& rhs) const;
		Vector3& operator=(const Vector3& rhs);
		bool operator==(const Vector3& rhs);
		bool operator!=(const Vector3& rhs);
		bool operator<(const Vector3& rhs);
		bool operator>(const Vector3& rhs);
		bool operator<=(const Vector3& rhs);
		bool operator>=(const Vector3& rhs);
		float Distance(const Vector3& rhs);
		static float Distance(const Vector3& lhs, const Vector3& rhs);
		float DistanceSqr(const Vector3& rhs);
		static float DistanceSqr(const Vector3& lhs, const Vector3& rhs);
		float Dot(const Vector3& rhs);
		static float Dot(const Vector3& lhs, const Vector3& rhs);
		Vector3 Normalize() const;
		float Magnitude() const;
		float MagnitudeSqr() const;
		Vector3& Scale(const float& scale, const Axis& axis);
		Vector3& Scale(const Vector3& scale);
		Vector3& Translate(const Vector3& translate);
		Vector3& Rotate(const float& rotation, const Axis& axis);
		operator Swizzle3();
	};
};
