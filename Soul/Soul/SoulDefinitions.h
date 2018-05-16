#pragma once
namespace SoulMaths {
	const float pi = 3.14159265359f;
	const float rad2deg = 57.2957795130785f;
	const float deg2rad = 0.01745329251994f;

	typedef enum Axis {
		AxisX,
		AxisY,
		AxisZ,
		AxisW,
		AxisXY,
		AxisXZ,
		AxisXW,
		AxisYZ,
		AxisYW,
		AxisZW,
		AxisXYZ,
		AxisXYW,
		AxisXZW,
		AxisYZW,
		AxisXYZW,
	}Axis;

	//	switch (axis)
	//	{
	//	case Axis::AxisX:
	//		break;
	//	case Axis::AxisY:
	//		break;
	//	case Axis::AxisZ:
	//		break;
	//	case Axis::AxisW:
	//		break;
	//	case Axis::AxisXY:
	//		break;
	//	case Axis::AxisXZ:
	//		break;
	//	case Axis::AxisXW:
	//		break;
	//	case Axis::AxisYZ:
	//		break;
	//	case Axis::AxisYW:
	//		break;
	//	case Axis::AxisZW:
	//		break;
	//	case Axis::AxisXYZ:
	//		break;
	//	case Axis::AxisXYW:
	//		break;
	//	case Axis::AxisXZW:
	//		break;
	//	case Axis::AxisYZW:
	//		break;
	//	case Axis::AxisXYZW:
	//		break;
	//	default:
	//		break;
	//	}
	//	return *this;
};