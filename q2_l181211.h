#pragma once
#include <iostream>
using namespace std;

class Rectangle
{
private:
	int width;
	int length;

public:
	//display width
	void getWidth() const;
	
	//display length
	void getLength() const;
	
	//store value of ln in length
	void setLength(int ln);
	
	//store value of wd in width
	void setWidth(int wd);
	
	//display area of rectangle
	void getArea() const;
	
	//swaps values of length and width
	void rotateRectangle();
	
	//draws an '*' based rectangle
	void draw() const;
};
