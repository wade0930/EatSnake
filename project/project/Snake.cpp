#include "Snake.h"

CSnake::CSnake()//�D��l�ɱN�u�Ѩ���I�����զ�,��l���ʤ�V�]�w���V�k
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
	if ((direction + 2) % 4 == this->direction)	//���a��J��V�P�D��e���ʤ�V�ۤϱN�����ܦ��ɳD���e�i��V
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
			if (&point == &(*snake.begin()))	//�N�����D�Y�P�D�Y���X�����p�C
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
	if ((x == 0) || (y == 2) || (x == 78) || (y == 24))	//�M�w�]�𪺦�m�i����
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
