//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//* Class name      : RectangleType                                     *
//*                                                                     *
//* Written by      : Clarence Defiesta, Kenjustin Yabut, Allen Dadia   *
//*                                                                     *
//* Purpose         : Defines the overloaded functions in order to      *
//*                   be tested in L2-1.cpp, and sets conditions when   *
//*                   invalid possible values are present				*
//*                                                                     *
//* Inputs          : None in this header					            *
//*                                                                     *
//* Outputs         : Return the defined operations						*
//*                                                                     *
//* Methods         : rectangleType firstRect(), rectangleType			*
//* 				  secondRect()					                    *
//*                                                                     *
//*---------------------------------------------------------------------*
//* Change Log:                                                         *
//*                         Revision                                    *
//*       Date    Changed  Rel Ver Mod Purpose                          *
//* 09/12/23      cdefiest 000.000.000 Initial release of program       *
//* 09/14/23      aidaida  000.001.000 Parts C and D, fixed A and B     *
//* 09/15/23      kyabut   000.002.000 Part E and header, troubleshoot  *
//*                                                                     *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#pragma once

#include<fstream>
#include<iostream>

using namespace std;
static int instanceCount;

//Small Class for header 
class SmallClass {
public: 
	SmallClass()
	{
		if (instanceCount++ == 0)
			cout << "Sinigang\t" << "L2-1\t" << "L2-1.exe\n" << endl;
	}
};

class rectangleType {
public:
	//Provided operations to overload
	double area() const;
	double getLength() const;
	double getWidth() const;
	double perimeter() const;
	void setDimension(double l, double w);

	friend ostream& operator<<(ostream&, const rectangleType&);
	friend istream& operator>>(istream&, rectangleType&);

	rectangleType operator + (const rectangleType&) const;
	rectangleType operator - (const rectangleType&) const;
	rectangleType operator * (const rectangleType&) const;
	rectangleType operator ++ ();
	rectangleType operator ++ (int);
	rectangleType operator -- ();
	rectangleType operator -- (int);
	bool operator == (const rectangleType&) const;
	bool operator != (const rectangleType&) const;
	bool operator <= (const rectangleType&) const;
	bool operator < (const rectangleType&) const;
	bool operator >= (const rectangleType&) const;
	bool operator > (const rectangleType&) const;
	rectangleType();
	rectangleType(double l, double w);

protected:
	double dblLength, dblWidth, dblArea, dblPerimeter;
};

//PART A: Overloading the pre increment operator
rectangleType rectangleType::operator ++ () {
	rectangleType rectangle;
	rectangle.dblLength = rectangle.dblLength++;
	rectangle.dblWidth = rectangle.dblWidth++;
	return *this;
}

//post incremenet operator
rectangleType rectangleType::operator ++ (int) {
	rectangleType temp = *this;
	dblLength++;
	dblWidth++;
	return temp;
}

//overloading the pre decrement operator
rectangleType rectangleType::operator -- () {
	rectangleType rectangle;
	if (dblLength > 0 && dblWidth > 0) {
		rectangle.dblLength = --dblLength;
		rectangle.dblWidth = --dblWidth;
		return rectangle;
	}
	else cout << "ERROR\n";
	return rectangle;
}

//post decrement operator
rectangleType rectangleType::operator -- (int u) {
	rectangleType rectangle;
	if (dblLength > 0 && dblWidth > 0) {
		rectangle.dblLength = dblLength--;
		rectangle.dblWidth = dblWidth--;
		return rectangle;
	}
	else cout << "ERROR\n";
	return rectangle;
}

//PART B: Overloading "-" operator
inline rectangleType rectangleType::operator - (const rectangleType&) const {
	rectangleType rectangle1;
	rectangleType rectangle2;
	double finalLength, finalWidth;
	finalLength = rectangle2.dblLength - rectangle1.dblLength;
	finalWidth = rectangle2.dblWidth - rectangle1.dblWidth;
	if (finalLength < 0 || finalWidth < 0) {
		cout << "ERROR" << endl;
	}
}

//PART C: Overload relational operators by considering
//the areas of the rectangle, if they are equal or not equal
bool rectangleType::operator == (const rectangleType& rectangle) const {
	return this->area() == rectangle.area();
}

bool rectangleType::operator != (const rectangleType& rectangle) const {
	return this->area() != rectangle.area();
}
bool rectangleType::operator <= (const rectangleType& rectangle) const {
	return this->area() <= rectangle.area();
}

bool rectangleType::operator < (const rectangleType& rectangle) const {
	return this->area() < rectangle.area();
}

bool rectangleType::operator >= (const rectangleType& rectangle) const {
	return this->area() >= rectangle.area();
}

bool rectangleType::operator > (const rectangleType& rectangle) const {
	return this->area() > rectangle.area();
}

//PART D: overloading other functions
//stream functions
ostream& operator << (ostream& osRectangle, const rectangleType& rectangle) {
	osRectangle << "Length = " << rectangle.dblLength
		<< " Width = " << rectangle.dblWidth;
	return osRectangle;
}

istream& operator >> (istream& isRectangle, rectangleType& rectangle) {
	isRectangle >> rectangle.dblLength >> rectangle.dblWidth;
	return isRectangle;
}

//arithmetic operations
rectangleType rectangleType::operator * (const rectangleType& rectangle) const {
	rectangleType rectangle1;
	rectangle1.dblWidth = dblWidth * rectangle.dblWidth;
	rectangle1.dblLength = dblLength * rectangle.dblLength;
	return rectangle1;
}

rectangleType rectangleType::operator + (const rectangleType& rectangle) const {
	rectangleType result;
	result.dblLength = dblLength + rectangle.dblLength;
	result.dblWidth = dblWidth + rectangle.dblWidth;
	return result;
}

void rectangleType::setDimension(double l, double w) {
	if (l >= 0)
		dblLength = l;
	else
		dblLength = 0;

	if (w >= 0)
		dblWidth = w;
	else
		dblWidth = 0;
}

double rectangleType::getLength() const {
	return dblLength;
}

double rectangleType::getWidth()const {
	return dblWidth;
}

double rectangleType::area() const {
	return dblLength * dblWidth;
}

double rectangleType::perimeter() const {
	return 2 * (dblLength + dblWidth);
}

rectangleType::rectangleType(double l, double w) {
	setDimension(l, w);
}

rectangleType::rectangleType() {
	dblLength = 0;
	dblWidth = 0;
	
}