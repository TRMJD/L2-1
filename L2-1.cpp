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
'* 09/14/2023   cdefiest  000.002.000 fixed redefining error           *
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "rectangleType.h"
using namespace std;

int main() {
	rectangleType rectangle1(10, 5);
	rectangleType rectangle2(8, 7);
	rectangleType rectangle3;
	rectangleType rectangle4;

	cout << "rectangle1: " << rectangle1 << endl;

	cout << "rectangle2: " << rectangle2 << endl;

	rectangle3 = rectangle1 + rectangle2;

	cout << "rectangle3: " << rectangle3 << endl;

	rectangle4 = rectangle1 * rectangle2;

	cout << "rectangle4: " << rectangle4 << endl;

	if (rectangle1 > rectangle2)
		cout << "Area of rectangle1 is greater than the area "
		<< "of rectangle2 ." << endl;
	else
		cout << "Area of rectangle1 is less than or equal to the area "
		<< "of rectangle2 ." << endl;

	rectangle1++;

	cout << "After increment the length and width of "
		<< "rectangle1 by one unit, \nrectangle1: "
		<< rectangle1 << endl;

	rectangle4 = ++rectangle3;

	cout << "New dimension of rectangle3: " << rectangle3 << endl;
	cout << "New dimension of rectangle4: " << rectangle4 << endl;

	return 0;
}