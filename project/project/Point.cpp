#include"Point.h"

CPoint::CPoint()
{
}

CPoint::CPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CPoint::Plot(HANDLE hout)
{
	SetOutputPosition(x, y, hout);
	cout << "¡½";
}

void CPoint::Clear(HANDLE hout)
{
	SetOutputPosition(x, y, hout);
	cout << "  ";
}

void CPoint::Clear()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " ";
}

void CPoint::SetOutputPosition(int x, int y, HANDLE hout)
{	
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hout, position);
}

bool CPoint::operator==(CPoint & point)
{
	return (point.x == this->x) && (point.y == this->y);
}

void CPoint::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

int CPoint::GetX()
{
	return x;
}

int CPoint::GetY()
{
	return y;
}
