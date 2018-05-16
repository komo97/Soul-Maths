#pragma once
#include "SoulDefinitions.h"
#include "Matrix.h"
namespace SoulMaths {

	class Matrix4 : Matrix
	{
	public:
		Matrix4();
		Matrix4(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& w);
		Matrix4(const Matrix4& cpy);
		~Matrix4();
		Swizzle4 x, y, z, w;
		Matrix4& operator+=(const Matrix4& rhs);
		Matrix4& operator-=(const Matrix4& rhs);
		Matrix4& operator*=(const Matrix4& rhs);
		Matrix4& operator+=(const Matrix4& rhs);
		Matrix4& operator-=(const Matrix4& rhs);
		Matrix4& operator*=(const float& rhs);
		Matrix4& operator/=(const float& rhs);
		Vector3 operator*(const Vector3& rhs) const;
		Vector4 operator*(const Vector4& rhs) const;
		Matrix3 operator*(const Matrix3& rhs) const;
		Matrix4 operator*(const Matrix4& rhs) const;
		Matrix4 operator+(const Matrix4& rhs) const;
		Matrix4 operator-(const Matrix4& rhs) const;
		Matrix4 operator/(const float& rhs) const;
		Matrix4 operator*(const float& rhs) const;
		Matrix4& operator=(const Matrix4& rhs);
		bool operator==(const Matrix4& rhs);
		bool operator!=(const Matrix4& rhs);
		Matrix4& Scale(const float& scale, const Axis& axis);
		Matrix4& Scale(const Vector4& scale);
		static Matrix4 ScaleMatrix(const float& scale, const Axis& axis);
		static Matrix4 ScaleMatrix(const Vector4& scale);
		Matrix4& Translate(const Vector4& translate);
		static Matrix4 TranslateMatrix(const Vector4& translate);
		Matrix4& Rotate(const float& rotation, const Axis& axis);
		static Matrix4 RotateMatrix(const float& rotation, const Axis& axis);
		Matrix4 Inverse();
		Matrix4 Transpose();
		float Determinant();
		//Faltan las projecciones y los tipos de projecciones.
		// Look at, entre otras transformaciones.
	};
};
