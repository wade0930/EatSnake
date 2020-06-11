#pragma once
#include<iostream>
#include "Point.h"
using std::cout;
class CFood
{
public:
	CFood();
	CFood(int x, int y);
	void PlaceFood(int x, int y);
	CPoint& GetPosition();
	void Show();
private:
	CPoint position;
};
