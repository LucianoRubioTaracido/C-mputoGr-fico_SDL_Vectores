#include "pch.h"
#include "Vector.h"

Vector::Vector()
{
	x = 0;
	y = 0;
}

template<typename T1, typename T2>
Vector::Vector(T1, T2)
{
	x = T1;
	y = T2;
}


Vector::~Vector()
{
}

Vector Vector::operator+ (Vector param)
{
	Vector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

Vector Vector::operator- (Vector param)
{
	Vector temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return temp;
}

float Vector::operator* (Vector param)
{
	float temp;
	temp = (x * param.x) + (y * param.y);
	return temp;
}

Vector Vector::operator* (float param)
{
	Vector temp;
	temp.x = (param * this->x);
	temp.y = (param * this->y);
	return temp;
}

//Vector Vector::operator= (Vector param)
//{
//
//}