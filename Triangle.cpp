//Triangle with base or height of 0.0
//is declared/intended. An actual 
//existing triangle can not have base 0.0
//with height greater than 0.0, nor vice versa. 
//If base or height becomes 0.0, the other value
//is set to 0.0. Negative values should not be
//passed. Negative values passed to
//base or height sets both to 0.0

#include <iostream>
#include <iomanip>
#include "Triangle.h"

using namespace std;

//Default constructor
Triangle::Triangle()
{
	base = 1;
	height = 1;
}

//Overloaded constructor
//If base or height called to be less than
//0 unit, set base and height to 0 
Triangle::Triangle(double base, double height)
{
	if (base <= 0.0 || height <= 0.0)
	{
		base = 0.0;
		height = 0.0;
	}
	else
	{
		base = base;
		height = height;
	}
}

//If base called to be less than 0
//unit, set base and height to 0
void Triangle::setBase(double b)
{
	if (b <= 0.0)
	{
		base = 0.0;
		height = 0.0;
	}
	else
	{
		base = b;
	}
}

//If height called to be less than 0
//unit, set base and height to 0
void Triangle::setHeigth(double h)
{
	if (h <= 0.0)
	{
		height = 0.0;
		base = 0.0;
	}
	else
	{
		height = h;
	}
}

double Triangle::getBase() const
{
	return base;
}

double Triangle::getHeight()const
{
	return height;
}

//Triangle Area = (b x h)/2
double Triangle::getArea()const
{
	return (base * height * 0.5);
}

//Prefix ++ operator
Triangle Triangle::operator ++()
{
	base++;
	height++;
	return *this;
}

//Postfix ++ operator
Triangle Triangle::operator ++(int)
{
	Triangle temp(base, height);
	++base;
	++height;
	return temp;
}

//Prefix -- operator
//If base or height is called to be less than
//0 unit, post error message, set base and
//height to 0 units
Triangle Triangle::operator --()
{
	if (base <= 0.0 || height <= 0.0)
	{
		base = 0.0;
		height = 0.0;
		cout << "Triangle's " << ((base <= height) ? "base" : "height") << " can not be further decreased.\n";
	}
	else
	{
		base--;
		height--;
	}

	//if after reducing lengths, base or height
	//is 0, set both to 0
	if (base <= 0.0 || height <= 0.0)
	{
		base = 0.0;
		height = 0.0;
	}
	return *this;
}

//Postfix -- operator
//If base or height is called to be less than
//0 unit, post error message, set base and
//height to 0 units
Triangle Triangle::operator --(int)
{
	Triangle temp(base, height);
	if (base <= 0.0 || height <= 0.0)
	{
		base = 0.0;
		height = 0.0;
		cout << "Triangle's properties can not be further decreased.\n";
	}
	else
	{
		--base;
		--height;
	}

	//if after reducing lengths, base or height
	//is 0, set both to 0
	if (base <= 0.0 || height <= 0.0)
	{
		base = 0.0;
		height = 0.0;
	}

	return temp;
}

//For cout << triangle
//Display all of triangle's properties
ostream &operator <<(ostream &strm, const Triangle &triangle)
{
	strm << "Triangle base is " << triangle.getBase() << "\n"
		<< "Triangle height is " << triangle.getHeight() << "\n"
		<< "Triangle area is " << triangle.getArea() << endl;		
	return strm;
}
