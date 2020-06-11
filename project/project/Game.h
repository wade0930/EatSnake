#pragma once
#include<iostream>
#include "Snake.h"
#include "Food.h"
#include "Point.h"
#include "conio.h"
#include<windows.h>
#include<time.h>
using std::endl;
class CSnake;
class CGame
{
public:
	CGame();
	bool Exit();
	void NewGame();
	void SetGame();
	void PaintEdge();
	void ShowState();
	void UpdateScore(bool eaten);
	bool DirectionChanged();
	void RandomFood(CFood& food);
	void PlayGame();
	void GameOver();
private:
	bool exit;
	int level;
	int speed;
	bool gameOver;
	CSnake snake;
	CFood food;
	int length;	//�C���ϰ��`����
	int width;	//�C���ϰ��`�e��
	int score;
};

