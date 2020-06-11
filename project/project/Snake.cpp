#include "Snake.h"

CSnake::CSnake()//蛇初始時將只由兩個點元素組成,初始移動方向設定為向右
{
	snake.push_back(CPoint(18, 16));
	snake.push_back(CPoint(16, 16));
	direction = moveDirection::RIGHT;
}

void CSnake::move()
{
	switch (direction)
	{
	case moveDirection::DOWN:
		snake.push_front(CPoint(snake.begin()->GetX(), snake.begin()->GetY() + 1));
		break;
	case moveDirection::RIGHT:
		snake.push_front(CPoint(snake.begin()->GetX() + 2, snake.begin()->GetY())); 
		break;
	case moveDirection::UP:
		snake.push_front(CPoint(snake.begin()->GetX(), snake.begin()->GetY() - 1));
		break;
	case moveDirection::LEFT:
		snake.push_front(CPoint(snake.begin()->GetX() - 2, snake.begin()->GetY()));
		break;
	}
	snake.pop_back();
}

bool CSnake::ChangeDirection(moveDirection direction)
{
	if ((direction + 2) % 4 == this->direction)	//玩家輸入方向與蛇當前移動方向相反將不改變此時蛇的前進方向
		return false;
	else
		this->direction = direction;
	return true; return false;
}

void CSnake::PaintSnake(HANDLE hOut)
{
	for (CPoint& point : snake)
	{
		CPoint::SetOutputPosition(point.GetX(), point.GetY(), hOut);
		point.Plot(hOut);
	}
}

bool CSnake::HitItself()
{
	for (CPoint& point : snake)
	{
		if (point == *snake.begin())
		{
			if (&point == &(*snake.begin()))	//將忽略蛇頭與蛇頭重合的情況。
				continue;
			else
				return true;
		}
	}
	return false;
}

bool CSnake::Hit(CPoint & point)
{
	for (CPoint& pointInSnake : snake)
	{
		if (point == pointInSnake)
			return true;
	}
	return false;
}

bool CSnake::HitEdge()
{
	int x = snake.begin()->GetX();
	int y = snake.begin()->GetY();
	if ((x == 0) || (y == 2) || (x == 78) || (y == 24))	//和預設牆的位置進行比較
		return true;
	else
		return false;
}

CPoint & CSnake::Head()
{
	return *snake.begin();
}

CPoint & CSnake::Tail()
{
	return *(snake.end() - 1);
}

bool CSnake::Eat(CFood & food)
{
	int foodx = food.GetPosition().GetX();
	int foody = food.GetPosition().GetY();
	int headx = Head().GetX();
	int heady = Head().GetY();
	bool toEat = ((foodx == headx) && (foody == (heady + 1)) && (direction == moveDirection::DOWN))
		|| ((foodx == headx) && (foody == (heady - 1)) && (direction == moveDirection::UP))
		|| (((foodx + 2) == headx) && (foody == heady) && (direction == moveDirection::LEFT))
		|| (((foodx - 2) == headx) && (foody == heady) && (direction == moveDirection::RIGHT));
	if (toEat)
	{
		snake.push_front(food.GetPosition());
		return true;
	}
	else
		return false;
}
