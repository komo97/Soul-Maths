#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix2.h"

using namespace SoulMaths;

Matrix4::Matrix4() : Matrix(4, 4),
	x(values[0], values[1], values[2], values[3]),
	y(values[4],values[5],values[6],values[7]),
	z(values[8], values[9], values[10], values[11]),
	w(values[12], values[13], values[14], values[15])
{
	x.val1 = 1, x.val2 = 0, x.val3 = 0, x.val4 = 0,
	y.val1 = 0, y.val2 = 1, y.val3 = 0, y.val4 = 0,
	z.val1 = 0, z.val2 = 0, z.val3 = 1, z.val4 = 0,
	w.val1 = 0, w.val2 = 0, w.val3 = 0, w.val4 = 1; 
}

SoulMaths::Matrix4::Matrix4(const Vector4 & x, const Vector4 & y, const Vector4 & z, const Vector4 & w) : Matrix4()
{
}

SoulMaths::Matrix4::Matrix4(const Matrix4 & cpy) : Matrix4()
{
	for (int i = 16; --i;)
		values[i] = cpy.values[i];
}


Matrix4::~Matrix4()
{
}

Matrix4 & SoulMaths::Matrix4::operator+=(const Matrix4 & rhs)
{
	for (int i = 16; --i;)
		values[i] += rhs.values[i];
	return *this;
}

Matrix4 & SoulMaths::Matrix4::operator-=(const Matrix4 & rhs)
{
	for (int i = 16; --i;)
		values[i] -= rhs.values[i];
	return *this;
}

Matrix4 & SoulMaths::Matrix4::operator*=(const Matrix4 & rhs)
{
	// TODO: insert return statement here
	Matrix4 res(*this);
	res.x.val1 = x.val1 * rhs.x.val1 + x.val2 * rhs.y.val1 + x.val3 * rhs.z.val1 + x.val4 * rhs.w.val1;
	res.x.val2 = x.val1 * rhs.x.val2 + x.val2 * rhs.y.val2 + x.val3 * rhs.z.val2 + x.val4 * rhs.w.val2;
	res.x.val3 = x.val1 * rhs.x.val3 + x.val2 * rhs.y.val3 + x.val3 * rhs.z.val3 + x.val4 * rhs.w.val3;
	res.x.val4 = x.val1 * rhs.x.val4 + x.val2 * rhs.y.val4 + x.val3 * rhs.z.val4 + x.val4 * rhs.w.val4;

	res.y.val1 = y.val1 * rhs.x.val1 + y.val2 * rhs.y.val1 + y.val3 * rhs.z.val1 + y.val4 * rhs.w.val1;
	res.y.val2 = y.val1 * rhs.x.val2 + y.val2 * rhs.y.val2 + y.val3 * rhs.z.val2 + y.val4 * rhs.w.val2;
	res.y.val3 = y.val1 * rhs.x.val3 + y.val2 * rhs.y.val3 + y.val3 * rhs.z.val3 + y.val4 * rhs.w.val3;
	res.y.val4 = y.val1 * rhs.x.val4 + y.val2 * rhs.y.val4 + y.val3 * rhs.z.val4 + y.val4 * rhs.w.val4;

	res.z.val1 = z.val1 * rhs.x.val1 + z.val2 * rhs.y.val1 + z.val3 * rhs.z.val1 + z.val4 * rhs.w.val1;
	res.z.val2 = z.val1 * rhs.x.val2 + z.val2 * rhs.y.val2 + z.val3 * rhs.z.val2 + z.val4 * rhs.w.val2;
	res.z.val3 = z.val1 * rhs.x.val3 + z.val2 * rhs.y.val3 + z.val3 * rhs.z.val3 + z.val4 * rhs.w.val3;
	res.z.val4 = z.val1 * rhs.x.val4 + z.val2 * rhs.y.val4 + z.val3 * rhs.z.val4 + z.val4 * rhs.w.val4;

	res.w.val1 = w.val1 * rhs.x.val1 + w.val2 * rhs.y.val1 + w.val3 * rhs.z.val1 + w.val4 * rhs.w.val1;
	res.w.val2 = w.val1 * rhs.x.val2 + w.val2 * rhs.y.val2 + w.val3 * rhs.z.val2 + w.val4 * rhs.w.val2;
	res.w.val3 = w.val1 * rhs.x.val3 + w.val2 * rhs.y.val3 + w.val3 * rhs.z.val3 + w.val4 * rhs.w.val3;
	res.w.val4 = w.val1 * rhs.x.val4 + w.val2 * rhs.y.val4 + w.val3 * rhs.z.val4 + w.val4 * rhs.w.val4;
	*this = res;
	return *this;
}

Matrix4 & SoulMaths::Matrix4::operator*=(const float & rhs)
{
	for (int i = 16; --i;)
		values[i] *= rhs;
	return *this;
}

Matrix4 & SoulMaths::Matrix4::operator/=(const float & rhs)
{
	if (rhs <= 0)
		return *this;
	for (int i = 16; --i;)
		values[i] /= rhs;
	return *this;
}

Vector3 SoulMaths::Matrix4::operator*(const Vector3 & rhs) const
{
	return Vector3();
}

Vector4 SoulMaths::Matrix4::operator*(const Vector4 & rhs) const
{
	return Vector4();
}

Matrix3 SoulMaths::Matrix4::operator*(const Matrix3 & rhs) const
{
	return Matrix3();
}

Matrix4 SoulMaths::Matrix4::operator*(const Matrix4 & rhs) const
{
	Matrix4 res(*this);
	res.x.val1 = x.val1 * rhs.x.val1 + x.val2 * rhs.y.val1 + x.val3 * rhs.z.val1 + x.val4 * rhs.w.val1;
	res.x.val2 = x.val1 * rhs.x.val2 + x.val2 * rhs.y.val2 + x.val3 * rhs.z.val2 + x.val4 * rhs.w.val2;
	res.x.val3 = x.val1 * rhs.x.val3 + x.val2 * rhs.y.val3 + x.val3 * rhs.z.val3 + x.val4 * rhs.w.val3;
	res.x.val4 = x.val1 * rhs.x.val4 + x.val2 * rhs.y.val4 + x.val3 * rhs.z.val4 + x.val4 * rhs.w.val4;

	res.y.val1 = y.val1 * rhs.x.val1 + y.val2 * rhs.y.val1 + y.val3 * rhs.z.val1 + y.val4 * rhs.w.val1;
	res.y.val2 = y.val1 * rhs.x.val2 + y.val2 * rhs.y.val2 + y.val3 * rhs.z.val2 + y.val4 * rhs.w.val2;
	res.y.val3 = y.val1 * rhs.x.val3 + y.val2 * rhs.y.val3 + y.val3 * rhs.z.val3 + y.val4 * rhs.w.val3;
	res.y.val4 = y.val1 * rhs.x.val4 + y.val2 * rhs.y.val4 + y.val3 * rhs.z.val4 + y.val4 * rhs.w.val4;

	res.z.val1 = z.val1 * rhs.x.val1 + z.val2 * rhs.y.val1 + z.val3 * rhs.z.val1 + z.val4 * rhs.w.val1;
	res.z.val2 = z.val1 * rhs.x.val2 + z.val2 * rhs.y.val2 + z.val3 * rhs.z.val2 + z.val4 * rhs.w.val2;
	res.z.val3 = z.val1 * rhs.x.val3 + z.val2 * rhs.y.val3 + z.val3 * rhs.z.val3 + z.val4 * rhs.w.val3;
	res.z.val4 = z.val1 * rhs.x.val4 + z.val2 * rhs.y.val4 + z.val3 * rhs.z.val4 + z.val4 * rhs.w.val4;

	res.w.val1 = w.val1 * rhs.x.val1 + w.val2 * rhs.y.val1 + w.val3 * rhs.z.val1 + w.val4 * rhs.w.val1;
	res.w.val2 = w.val1 * rhs.x.val2 + w.val2 * rhs.y.val2 + w.val3 * rhs.z.val2 + w.val4 * rhs.w.val2;
	res.w.val3 = w.val1 * rhs.x.val3 + w.val2 * rhs.y.val3 + w.val3 * rhs.z.val3 + w.val4 * rhs.w.val3;
	res.w.val4 = w.val1 * rhs.x.val4 + w.val2 * rhs.y.val4 + w.val3 * rhs.z.val4 + w.val4 * rhs.w.val4;
	return res;
}

Matrix4 SoulMaths::Matrix4::operator+(const Matrix4 & rhs) const
{
	Matrix4 ret(*this);
	for (int i = 16; --i;)
		ret.values[i] += rhs.values[i];
	return ret;
}

Matrix4 SoulMaths::Matrix4::operator-(const Matrix4 & rhs) const
{
	Matrix4 ret(*this);
	for (int i = 16; --i;)
		ret.values[i] -= rhs.values[i];
	return ret;
}

Matrix4 SoulMaths::Matrix4::operator/(const float & rhs) const
{
	Matrix4 ret(*this);
	if (rhs <= 0)
		return ret;
	for (int i = 16; --i;)
		ret.values[i] /= rhs;
	return ret;
}

Matrix4 SoulMaths::Matrix4::operator*(const float & rhs) const
{
	Matrix4 ret(*this);
	for (int i = 16; --i;)
		ret.values[i] *= rhs;
	return ret;
}

Matrix4 & SoulMaths::Matrix4::operator=(const Matrix4 & rhs)
{
	for (int i = 16; --i;)
		values[i] = rhs.values[i];
	return *this;
}

bool SoulMaths::Matrix4::operator==(const Matrix4 & rhs)
{
	for (int i = 16; --i;)
		if (values[i] != rhs.values[i])
			return false;
	return true;
}

bool SoulMaths::Matrix4::operator!=(const Matrix4 & rhs)
{
	return !(*this == rhs);
}

Matrix4 & SoulMaths::Matrix4::Scale(const float & scale, const Axis & axis)
{
	*this *= ScaleMatrix(scale, axis);
	return *this;
}

Matrix4 & SoulMaths::Matrix4::Scale(const Vector4 & scale)
{
	*this *= ScaleMatrix(scale);
	return *this;
}

Matrix4 SoulMaths::Matrix4::ScaleMatrix(const float & scale, const Axis & axis)
{
	Matrix4 res;
	switch (axis)
	{
	case Axis::AxisX:
		res.x.val1 = scale;
		break;
	case Axis::AxisY:
		res.y.val2 = scale;
		break;
	case Axis::AxisZ:
		res.z.val3 = scale;
		break;
	case Axis::AxisW:
		res.w.val4 = scale;
		break;
	case Axis::AxisXY:
		res.x.val1 = scale;
		res.y.val2 = scale;
		break;
	case Axis::AxisXZ:
		res.x.val1 = scale;
		res.z.val3 = scale;
		break;
	case Axis::AxisXW:
		res.x.val1 = scale;
		res.w.val4 = scale;
		break;
	case Axis::AxisYZ:
		res.y.val2 = scale;
		res.z.val3 = scale;
		break;
	case Axis::AxisYW:
		res.y.val2 = scale;
		res.w.val4 = scale;
		break;
	case Axis::AxisZW:
		res.z.val3 = scale;
		res.w.val4 = scale;
		break;
	case Axis::AxisXYZ:
		res.x.val1 = scale;
		res.y.val2 = scale;
		res.z.val3 = scale;
		break;
	case Axis::AxisXYW:
		res.x.val1 = scale;
		res.y.val2 = scale;
		res.w.val4 = scale;
		break;
	case Axis::AxisXZW:
		res.x.val1 = scale;
		res.z.val3 = scale;
		res.w.val4 = scale;
		break;
	case Axis::AxisYZW:
		res.y.val2 = scale;
		res.z.val3 = scale;
		res.w.val4 = scale;
		break;
	case Axis::AxisXYZW:
		res.x.val1 = scale;
		res.y.val2 = scale;
		res.z.val3 = scale;
		res.w.val4 = scale;
		break;
	default:
		break;
	}
	return res;
}

Matrix4 SoulMaths::Matrix4::ScaleMatrix(const Vector4 & scale)
{
	Matrix4 res;
	res.x.val1 = scale.x;
	res.y.val2 = scale.y;
	res.z.val3 = scale.z;
	res.w.val4 = scale.w;
	return res;
}

Matrix4 & SoulMaths::Matrix4::Translate(const Vector4 & translate)
{
	*this *= TranslateMatrix(translate);
	return *this;
}

Matrix4 SoulMaths::Matrix4::TranslateMatrix(const Vector4 & translate)
{
	Matrix4 res;
	res.x.val4 = translate.x;
	res.y.val4 = translate.y;
	res.z.val4 = translate.z;
	res.w.val4 = translate.w;
	return res;
}

Matrix4 & SoulMaths::Matrix4::Rotate(const float & rotation, const Axis & axis)
{
	*this *= RotateMatrix(rotation, axis);
	return *this;
}

Matrix4 SoulMaths::Matrix4::RotateMatrix(const float & rotation, const Axis & axis)
{
	Matrix4 res;
	Matrix4 o1, o2, o3, o4;
	float sine = sinf(deg2rad * rotation),
		cosine = cosf(deg2rad * rotation);
	switch (axis)
	{
	case Axis::AxisX:
		res.y.val2 = cosine;
		res.y.val3 = 0 - sine;
		res.z.val2 = sine;
		res.z.val3 = cosine;
		break;
	case Axis::AxisY:
		res.x.val1 = cosine;
		res.x.val3 = sine;
		res.z.val1 = 0 - sine;
		res.z.val3 = cosine;
		break;
	case Axis::AxisZ:
		res.x.val1 = cosine;
		res.x.val2 = 0 - sine;
		res.y.val1 = sine;
		res.y.val2 = cosine;
		break;
	case Axis::AxisW:
		break;
	case Axis::AxisXY:
		o1.y.val2 = cosine;
		o1.y.val3 = 0 - sine;
		o1.z.val2 = sine;
		o1.z.val3 = cosine;

		o2.x.val1 = cosine;
		o2.x.val3 = sine;
		o2.z.val1 = 0 - sine;
		o2.z.val3 = cosine;

		res = o2 * o1;
		break;
	case Axis::AxisXZ:
		o1.y.val2 = cosine;
		o1.y.val3 = 0 - sine;
		o1.z.val2 = sine;
		o1.z.val3 = cosine;

		o2.x.val1 = cosine;
		o2.x.val2 = 0 - sine;
		o2.y.val1 = sine;
		o2.y.val2 = cosine;

		res = o2 * o1;
		break;
	case Axis::AxisXW:
		break;
	case Axis::AxisYZ:
		o1.x.val1 = cosine;
		o1.x.val3 = sine;
		o1.z.val1 = 0 - sine;
		o1.z.val3 = cosine;

		o2.x.val1 = cosine;
		o2.x.val2 = 0 - sine;
		o2.y.val1 = sine;
		o2.y.val2 = cosine;

		res = o2 * o1;
		break;
	case Axis::AxisYW:
		break;
	case Axis::AxisZW:
		break;
	case Axis::AxisXYZ:
		o1.y.val2 = cosine;
		o1.y.val3 = 0 - sine;
		o1.z.val2 = sine;
		o1.z.val3 = cosine;

		o2.x.val1 = cosine;
		o2.x.val3 = sine;
		o2.z.val1 = 0 - sine;
		o2.z.val3 = cosine;

		o3.x.val1 = cosine;
		o3.x.val2 = 0 - sine;
		o3.y.val1 = sine;
		o3.y.val2 = cosine;

		res = o3 * o2 * o1;
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
	return res;
}

Matrix4 SoulMaths::Matrix4::Inverse()
{
	float det = Determinant();
	if (det <= 0)
		return Matrix4();
	//for(int i = 0; i < )
	//return Matrix4();
}

Matrix4 SoulMaths::Matrix4::Transpose()
{
	return Matrix4();
}

float SoulMaths::Matrix4::Determinant()
{
	return 	x.val4 * y.val3 * z.val2 * w.val1 - x.val3 * y.val4 * z.val2 * w.val1 -
		x.val4 * y.val2 *z.val3 * w.val1 + x.val2 * y.val4 *z.val3 * w.val1 +
		x.val3 * y.val2 * z.val4 * w.val1 - x.val2 * y.val3 * z.val4 * w.val1 -
		x.val4 * y.val3 * z.val1 * w.val2 + x.val3 * y.val4 * z.val1 * w.val2 +
		x.val4 * y.val1 *z.val3 * w.val2 - x.val1 * y.val4 *z.val3 * w.val2 -
		x.val3 * y.val1 * z.val4 * w.val2 + x.val1 * y.val3 * z.val4 * w.val2 +
		x.val4 * y.val2 * z.val1 * w.val3 - x.val2 * y.val4 * z.val1 * w.val3 -
		x.val4 * y.val1 * z.val2 * w.val3 + x.val1 * y.val4 * z.val2 * w.val3 +
		x.val2 * y.val1 * z.val4 * w.val3 - x.val1 * y.val2 * z.val4 * w.val3 -
		x.val3 * y.val2 * z.val1 * w.val4 + x.val2 * y.val3 * z.val1 * w.val4 +
		x.val3 * y.val1 * z.val2 * w.val4 - x.val1 * y.val3 * z.val2 * w.val4 -
		x.val2 * y.val1 *z.val3 * w.val4 + x.val1 * y.val2 *z.val3 * w.val4;
}
