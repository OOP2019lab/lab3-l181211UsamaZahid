#include "q2_l181211.h"
void Rectangle::getWidth() const
{
	cout << "Width of Rectangle= " << width << endl;
}

void Rectangle::getLength() const
{

	cout << "Length of Rectangle= " << length << endl;
}

void Rectangle::setLength(int ln)
{
	if (ln < 0)
		length = -ln;
	else
		length = ln;
}

void Rectangle::setWidth(int wd)
{
	if (wd < 0)
		width = -wd;
	else
		width = wd;
}

void Rectangle::getArea() const
{
	cout << endl;
	cout << "Area of Rectangle= " << width*length << endl;
}

void Rectangle::rotateRectangle()
{
	int temp;
	temp = width;
	width = length;
	length = temp;
}

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