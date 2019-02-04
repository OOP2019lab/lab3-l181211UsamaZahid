#pragma once
#include <iostream>
using namespace std;

class Rectangle
{
private:
	int width;
	int length;
public:
	void getWidth() const;
	void getLength() const;
	void setLength(int ln);
	void setWidth(int wd);
	void getArea() const;
	void rotateRectangle();
	void draw() const;
};
