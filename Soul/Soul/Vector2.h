#pragma once
#include "Vector.h"
#include "SoulDefinitions.h"

namespace SoulMaths {

	class Vector2 : Vector
	{
	public:
		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2& cpy);
		Vector2(const Swizzle2& xy);
		~Vector2();
		Swizzle2 xy;
		float &x,
			&y;
		Vector2& operator+=(const Vector2& rhs);
		Vector2& operator-=(const Vector2& rhs);
		Vector2& operator*=(const Vector2& rhs);
		Vector2& operator*=(const float& rhs);
		Vector2& operator/=(const float& rhs);
		Vector2 operator*(const Vector2& rhs) const;
		Vector2 operator+(const Vector2& rhs) const;
		Vector2 operator-(const Vector2& rhs) const;
		Vector2 operator/(const float& rhs) const;
		Vector2 operator*(const float& rhs) const;
		Vector2& operator=(const Vector2& rhs);
		bool operator==(const Vector2& rhs);
		bool operator!=(const Vector2& rhs);
		bool operator<(const Vector2& rhs);
		bool operator>(const Vector2& rhs);
		bool operator<=(const Vector2& rhs);
		bool operator>=(const Vector2& rhs);
		float Distance(const Vector2& rhs);
		static float Distance(const Vector2& lhs, const Vector2& rhs);
		float DistanceSqr(const Vector2& rhs);
		static float DistanceSqr(const Vector2& lhs, const Vector2& rhs);
		float Dot(const Vector2& rhs);
		static float Dot(const Vector2& lhs, const Vector2& rhs);
		Vector2 Normalize() const;
		float Magnitude() const;
		float MagnitudeSqr() const;
		Vector2& Scale(const float& scale, const Axis& axis);
		Vector2& Scale(const Vector2& scale);
		Vector2& Translate(const Vector2& translate);
		Vector2& Rotate(const float& rotation);
		operator Swizzle2();
		operator Vector3();
		//Faltan matrices, operaciones con vector3, vector4, y operaciones con matrices y producto cruz
	};

};