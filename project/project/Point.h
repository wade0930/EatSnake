#pragma once
#include<iostream>
#include<Windows.h>
using std::cout;
using std::cin;

class CPoint {
public:
	CPoint();
	CPoint(int x, int y);
	void Plot(HANDLE hout);
	void Clear(HANDLE hout);
	void Clear();
	static void SetOutputPosition(int x, int y, HANDLE hout);
	bool operator == (CPoint& point);
	void SetPosition(int x, int y);
	int GetX();
	int GetY();
private:
	int x, y;
};