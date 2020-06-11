#include "Food.h"

CFood::CFood()
{
	CPoint position;
}

CFood::CFood(int x, int y)
{
	position.SetPosition(x, y);
}

void CFood::PlaceFood(int x, int y)
{
	position.SetPosition(x, y);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	CPoint::SetOutputPosition(x, y, hOut);
	cout << "$$";
}

CPoint & CFood::GetPosition()
{
	return position;
}

void CFood::Show()
{
	cout << '(' << position.GetX() << ',' << position.GetY() << ')';
}
