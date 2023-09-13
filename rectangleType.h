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
rectangleType rectangleType::operator - (const rectangleType&) const {
	rectangleType rectangle1;
	rectangleType rectangle2;
	int finalLength, finalWidth;
	finalLength = rectangle2.length - rectangle1.length;
	finalWidth = rectangle2.width - rectangle1.width;
	if (finalLength < 0 || finalWidth < 0) {
		cout << "ERROR" << endl;
	}
}