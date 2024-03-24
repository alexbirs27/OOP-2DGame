#pragma once
#include <iostream>
class Vector2D
{
public:

	Vector2D();
	Vector2D(float x, float y);
	Vector2D& Add(const Vector2D & vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
	//override +=, -=	

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);

	int GetX() { return int(x); }
	int GetY() { return int(y); }
	void SetX(float val) { x = val; }
	void SetY(float val) { y = val; }
	friend std::ostream& operator<<(std::ostream& cout, const Vector2D& vec);
private:
	float x;
	float y;
};

