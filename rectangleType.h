#pragma once

#include<fstream>
#include<iostream>

using namespace std;

class rectangleType {
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
	double length, width, area, perimeter;
	


};

//PART A: Overloading the pre increment operator
rectangleType rectangleType::operator ++ () {
	rectangleType rectangle;
	rectangle.length = rectangle.length++;
	rectangle.width = rectangle.width++;
	return rectangle;
}

//post incremenet operator
rectangleType rectangleType::operator ++ (int) {
	rectangleType rectangle;
	rectangle.length = ++rectangle.length;
	rectangle.width = ++rectangle.width;
	return rectangle;
}

//PART B: Overloading "-" operator
inline rectangleType rectangleType::operator - (const rectangleType&) const {
	rectangleType rectangle1;
	rectangleType rectangle2;
	int finalLength, finalWidth;
	finalLength = rectangle2.length - rectangle1.length;
	finalWidth = rectangle2.width - rectangle1.width;
	if (finalLength < 0 || finalWidth < 0) {
		cout << "ERROR" << endl;
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
	osRectangle << "Length = " << rectangle.length
		<< " Width = " << rectangle.width;
	return osRectangle;
}

istream& operator >> (istream& isRectangle, rectangleType& rectangle) {
	isRectangle >> rectangle.length >> rectangle.width;
	return isRectangle;
}

//arithmetic operations
rectangleType rectangleType::operator * (const rectangleType& rectangle) const {
	rectangleType rectangle1;
	rectangle1.width = width * rectangle.width;
	rectangle1.length = length * rectangle.length;
	return rectangle1;
}

rectangleType rectangleType::operator + (const rectangleType& rectangle) const {
	rectangleType rectangle1;
	rectangle1.length = length + rectangle.length;
	rectangle1.width = width + rectangle.width;
	return rectangle1;
}

rectangleType rectangleType::operator -- () {
	if (length > 0 && width > 0) {
		rectangleType rectangle;
		rectangle.length = --length;
		rectangle.width = --width;
		return rectangle;
	}
	else cout << "ERROR\n";
}

rectangleType rectangleType::operator -- (int u) {
	if (length > 0 && width > 0) {
		rectangleType rectangle;
		rectangle.length = length--;
		rectangle.width = width--;
		return rectangle;
	}
	else cout << "ERROR\n";

}

void rectangleType::setDimension(double l, double w) {
	if (l >= 0)
		length = l;
	else
		length = 0;

	if (w >= 0)
		width = w;
	else
		width = 0;
}

double rectangleType::getLength() const {
	return length;
}

double rectangleType::getWidth()const {
	return width;
}

double rectangleType::area() const {
	return length * width;
}

double rectangleType::perimeter() const {
	return 2 * (length + width);
}

rectangleType::rectangleType(double l, double w) {
	setDimension(l, w);
}

rectangleType::rectangleType() {
	length = 0;
	width = 0;
}