//Circle with radius of 0.0 are 
//declared/intended. Actual existing
//circles must have radius > 0.0. 
//Negative values should not be
//passed. Any negative
//values passed to radius
//sets radius to 0.0

#include <iostream>
#include <iomanip>
#include "Circle.h"

using namespace std;

//Default Constructor
Circle::Circle()
{
	radius = 1.0;
}

//Overload constructor
//If circle radius called to be less
//than 0 units, set radius to 0.0
Circle::Circle(double r)
{
	if (r < 0.0)
	{
		radius = 0.0;
	}
	else
	{
		radius = r;
	}
}

//If circle radius called to be less
//than 0 units, set radius to 0.0
void Circle::setRadius(double r)
{
	if (r < 0.0)
	{
		radius = 0.0;
	}
	else
	{
		radius = r;
	}
}

double Circle::getRadius() const
{
	return radius;
}

//Circle Area = radius^2 x pi
double Circle::getArea() const
{
	return(radius * radius * 3.1415);
}

//Circle Circumference = 2pi x radius
double Circle::getCirumference() const
{
	return(2.0 * 3.1415 * radius);
}

//Prefix ++ operator
Circle Circle::operator++()
{
	radius++;
	return *this;
}

//Postfix ++ operator
Circle Circle::operator ++(int)
{
	Circle temp;
	++(*this);
	return temp;
}

//If radius is called to be less than
//0 units, error message posted, radius 
//set to 0.0
Circle Circle::operator --()
{
	radius--;
	if (radius < 0.0)
	{
		radius = 0.0;
		cout << "Circle's radius can not be further decreased.\n";
	}
	return *this;
}

//If radius is called to be less than
//0 units, error message posted, radius 
//set to 0.0
Circle Circle::operator --(int)
{
	Circle temp = *this;
	--(*this);
	if ((*this).radius < 0.0)
	{
		(*this).radius = 0.0;
		cout << "Circle's radius can not be further decreased.\n";
	}
	return temp;
}

//For cout << circle
//Displays circle's properties
ostream &operator <<(ostream &strm, const Circle &circle)
{
	strm << "Circle radius is " << circle.getRadius() << "\n"
	 << "Circle area is " << circle.getArea() << "\n"
	<< "Circle circumference is " << circle.getCirumference() << endl;
	return strm;
}
