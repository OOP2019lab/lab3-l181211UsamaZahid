#include "q2_l181211.h"
//display width
void Rectangle::getWidth() const
{
	cout << "Width of Rectangle= " << width << endl;
}

//display length
void Rectangle::getLength() const
{

	cout << "Length of Rectangle= " << length << endl;
}

//store value of ln in length
void Rectangle::setLength(int ln)
{
	if (ln < 0)
		length = -ln;
	else
		length = ln;
}

//store value of wd in width
void Rectangle::setWidth(int wd)
{
	if (wd < 0)
		width = -wd;
	else
		width = wd;
}

//display area of rectangle
void Rectangle::getArea() const
{
	cout << endl;
	cout << "Area of Rectangle= " << width*length << endl;
}

//swaps values of length and width
void Rectangle::rotateRectangle()
{
	int temp;
	temp = width;
	width = length;
	length = temp;
}

//draws an '*' based rectangle
void Rectangle::draw() const
{
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}