#include "Matrix.h"

using namespace SoulMaths;


SoulMaths::Matrix::Matrix(const size_t & w, const size_t & h) : Vector(w*h), width(w), height(h)
{
	
}

size_t SoulMaths::Matrix::GetWidth() const
{
	return _width;
}

size_t SoulMaths::Matrix::GetHeight() const
{
	return _height;
}

Matrix::~Matrix()
{
}
