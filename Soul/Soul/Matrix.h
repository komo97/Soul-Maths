#pragma once
#include "Vector.h"

namespace SoulMaths {

	class Matrix : protected Vector
	{
	public:
		Matrix(const size_t& w, const size_t& h);
		size_t GetWidth() const;
		size_t GetHeight() const;
		~Matrix();
	protected:
		size_t _width, _height;
	};
};
