/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Program name    : L2-1                                              *
'*                                                                     *
'* Written by      : Clarence Defiesta, Kenjustin Yabut, Allen Dadia   *
'*                                                                     *
'* Purpose         : create a program that tests various inputs of     *
'*                   the class rectangleType and show how to overload  *
'*                   operators                                         *
'*                                                                     *
'* Inputs          : Length and width of rectangle                     *
'*                                                                     *
'* Outputs         : length, width, perimeter, and area of rectangle   *
'* 					                                                   *
'* 					 									               *
'*                                                                     *
'* Calls           : No internal or external calls                     *
'*                                                                     *
'* Structure       : BEGIN                                             *
'*                        Straight line code no sub-processes          *
'*                   STOP                                              *
'*                        End of Program                               *
'*                                                                     *
'*---------------------------------------------------------------------*
'*                                                                     *
'* Collaboration: help from Professor Urrutia                          *
'*															           *
'*                                                                     *
'*---------------------------------------------------------------------*
'* Change Log:                                                         *
'*                         Revision                                    *
'*       Date    Changed  Rel Ver Mod Purpose                          *
'* 09/12/2023   cdefiest  000.001.000 Initial release of program       *
'* 09/12/2023   cdefiest  000.002.000 completed parts A and B          *
'* 09/14/2023   adadia    000.003.000 fixed redefining error           *
'* 09/15/2023   adadia    000.004.000 parts C and D					   *
'* 09/15/2023   kyabut    000.005.000 part E and heading line          *
'* 09/17/2023   kyabut    000.006.000 fixed heading line, increment op *
'* 09/18/2023   kyabut    000.007.000 fixed improper operations        *
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "rectangleType.h"
using namespace std;

int main() {
	//for first line executable code requirement
	SmallClass obj;

	//create a program that simulates the overloaded functions
	//in rectangleType.h by showing arithmetic operations
	rectangleType firstRec(12, 7);
	rectangleType secondRec(9, 6);
	

	cout << "First Rectangle: " << firstRec << endl;
	cout << "Second Rectangle: " << secondRec << "\n" << endl;
	
	//create another rectangle that is the sum of the first and second rectangle
	rectangleType thirdRec;
	thirdRec = firstRec + secondRec;
	cout << "Sum of Rectangle 1 and 2" << endl;
	cout << "Third Rectangle: " << thirdRec << "\n" << endl;
	
	//create another rectangle that is the product of the first and second rectangle
	rectangleType fourthRect;
	fourthRect = firstRec * secondRec;
	cout << "Product of rectangle 1 and 2" << endl;
	cout << "Fourth Rectangle: " << fourthRect << "\n" << endl;

	//compare the area of the first and second rectangle
	if (firstRec > secondRec) {
		cout << "Area of the first rectangle is greater than the second" << endl;
	}
	else if (secondRec > firstRec) {
		cout << "Area of second rectangle is greater than the first" << endl;
	}
	else cout << "Area is the same" << endl;

	//increment functions for the rectangles
	firstRec++;

	cout << "After increment the length and width of "
		<< "rectangle1 by one unit, \nrectangle1: "
		<< firstRec << endl;

	thirdRec++;
	fourthRect++;

	cout << "New dimension of Third Rectangle: " << thirdRec << endl;
	cout << "New dimension of Fourth Rectangle: " << fourthRect << endl;

	return 0;
}
