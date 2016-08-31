//Square side length of 0.0 means a 
//square is declared/intended.
//However, an actual existing square
//can not have a 0.0 or negative side
//length. Negative values should not 
//be passed. All negative values passed
//into side length sets to 0.0

#include <iostream>
#include <iomanip>
#include "Square.h"

using namespace std;

//Default constructor
Square::Square()
{
	length = 1;
}

//Overloaded constructor
//If side length called to be less 
//than 0 units, set length to 0
Square::Square(double side)
{
	if (side < 0.0)
	{
		length = 0.0;
	}
	else
	{
		length = side;
	}
}

//if square's length called to be less
//than 0 units, set length to 0
void Square::setLength(double side)
{
	if (side < 0.0)
	{
		length = 0.0;
	}
	else
	{
		length = side;
	}
}

double Square::getLength() const
{
	return length;
}

//Square Area = length x length
double Square::getArea() const
{
	return (length * length);
}

//Square Perimeter = length x 4
double Square::getPerimeter() const
{
	return (length * 4);
}

//Prefix ++ operator
Square Square::operator ++()
{
	length++;
	return *this;
}

//Postfix ++ operator
Square Square::operator ++(int)
{
	Square temp;
	++(*this);
	return temp;
}

//Prefix -- operator
//If length is called to be less than 0 unit, 
//post error message, set length to 0 units
Square Square::operator --()
{
	length--;
	if (length < 0.0)
	{
		length = 0.0;
		cout << "Square's side length can not be further decreased.\n";
	}
	return *this;
}

//Postfix -- operator
//If length is called to be less than 0 unit, 
//post error message, set length to 0 units
Square Square::operator --(int)
{
	Square temp;
	--(*this);
	if ((*this).length < 0.0)
	{
		(*this).length = 0.0;
		cout << "Square's side length can not be further decreased.\n";
	}
	return temp;
}

//For cout << square
//Display square's properties
ostream &operator <<(ostream &strm, const Square &square)
{
	strm << "Square side length is " << square.getLength() << "\n"
		<< "Square area is " << square.getArea() << "\n"
		<< "Square perimeter is " << square.getPerimeter() << endl;
	return strm;
}
