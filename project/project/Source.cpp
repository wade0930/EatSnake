#include "Game.h"
#include<windows.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	SetConsoleTitle("�g���D"); //�Ω�]�w�����i�����W
	CGame* Game = new CGame();
	Game->NewGame();
	do
	{
		delete Game;
		Game = new CGame();
		Game->SetGame();
		Game->PlayGame();
		Game->GameOver();
	} while (!Game->Exit());
	Sleep(2000);
	return 0;
}