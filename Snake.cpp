#include "Snake.h"
#include <iostream>
Snake::Snake(int x, int y)
{
	dir = RIGHT;
	len = 5;
	cout << "Snake{" << endl;
	for (int i = 0; i < len; i++)
	{
		NODE node;
		node.size = 20;
		node.x = x;
		node.y = y + i;
		body[i] = node;
		cout << "\t x=" << node.x << ",y=" << node.y << endl;
	}
	cout << "}" << endl;
}

void Snake::move()
{
	NODE head = body[0];
	cout << "head{x=" << head.x << ",y=" << head.y << "}" << endl;
	cout << "dir=" << dir << endl;
	NODE node;
	node.size = 20;
	switch (dir)
	{
	case RIGHT:
		node.x = head.x + 1;
		node.y = head.y;
		break;
	case LEFT:
		node.x = head.x - 1;
		node.y = head.y;
		break;
	case UP:
		node.y = head.y - 1;
		node.x = head.x;
		break;
	case DOWN:
		node.y = head.y + 1;
		node.x = head.x;
		break;
	default:
		break;
	}
	Insert(&body[0], node, 1, len);

}

void Snake::changeDir(Direction dir)
{

	switch (dir)
	{
	case RIGHT:
		if (this->dir != LEFT)
			this->dir = dir;
		break;
	case LEFT:
		if (this->dir != RIGHT)
			this->dir = dir;
		break;
	case UP:
		if (this->dir != DOWN)
			this->dir = dir;
		break;
	case DOWN:
		if (this->dir != UP)
			this->dir = dir;
		break;
	default:
		break;
	}
	
}

bool Snake::eat(NODE* food)
{
	if (body[0].x == food->x && body[0].y == food->y)
	{
		NODE node;
		node.x = body[len - 1].x;
		node.y = body[len - 1].y;
		node.size = 20;
		len++;
		cout << "eat,now len=" << len << endl;
		body[len-1] = node;
		return true;
	}
	return false;
}

void Snake::Insert(NODE* arr, NODE num, int pos, int len)
{
	for (int i = len; i >= pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos - 1] = num;
}



