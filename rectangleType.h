#pragma once

#include<fstream>
#include<iostream>

using namespace std;

class rectangleType {
public:
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
	return rectangle;
}

//post incremenet operator
rectangleType rectangleType::operator ++ (int) {
	rectangleType rectangle;
	rectangle.dblLength = ++rectangle.dblLength;
	rectangle.dblWidth = ++rectangle.dblWidth;
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
	rectangleType rectangle1;
	rectangle1.dblLength = dblLength + rectangle.dblLength;
	rectangle1.dblWidth = dblWidth + rectangle.dblWidth;
	return rectangle1;
}

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