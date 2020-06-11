#pragma once
#include<iostream>
#include "Point.h"
#include<deque>
#include "Point.h"
#include "Food.h"
using std::cout;
using std::cin;
using std::deque;
class CSnake
{
public:
	enum moveDirection { UP, LEFT, DOWN, RIGHT };
	CSnake();
	void move();
	bool ChangeDirection(moveDirection direction);
	void PaintSnake(HANDLE hOut);
	bool HitItself();
	bool Hit(CPoint& point);
	bool HitEdge();
	CPoint& Head();
	CPoint& Tail();
	bool Eat(CFood& food);
private:
	deque<CPoint> snake;
	moveDirection direction;
};