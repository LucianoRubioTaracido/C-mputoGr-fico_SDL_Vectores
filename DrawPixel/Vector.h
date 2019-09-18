#pragma once

class Vector
{
public:
	int x, y;

	Vector();

	Vector(int T1,int T2);

	Vector operator+ (Vector);
	Vector operator- (Vector);
	float operator* (Vector);
	Vector operator* (float);
	//Vector operator= (Vector);

	~Vector();
};

