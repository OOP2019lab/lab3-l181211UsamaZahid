#include<iostream>
#include "q2_l181211.h"
using namespace std;

//test run of class rectangle
int main()
{
	Rectangle r1;
	int ln, wd;
	
	cout << "Input r1 length ('-' will be changed to '+' during input): ";
	cin >> ln;
	r1.setLength(ln);
	
	cout << "Input r1 width ('-' will be changed to '+' during input): ";
	cin >> wd;
	r1.setWidth(wd);
	
	r1.getWidth();
	
	r1.getLength();
	
	r1.getArea();
	
	r1.draw();
	
	r1.rotateRectangle();
	
	r1.draw();
	
	system("pause");
}