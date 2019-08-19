#pragma once
#include <list>
#include "direction.cpp"

using namespace std;
class Snake
{
private:
	Direction dir;
	void Insert(NODE* arr, NODE num, int pos, int len);
public:
	NODE body[1200];
	Snake(int x, int y);
	int len;
	void move();
	void changeDir(Direction dir);
	bool eat(NODE *food);
	
};

