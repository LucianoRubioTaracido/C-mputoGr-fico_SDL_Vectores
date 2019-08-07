#pragma once
class Vector
{
public:

	int x, y;

	Vector();

	template<typename T1, typename T2>
	Vector(T1, T2);

	Vector operator+ (Vector);
	Vector operator- (Vector);
	float operator* (Vector);
	Vector operator* (float);
	//Vector operator= (Vector);

	~Vector();
};

