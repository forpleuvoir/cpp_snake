#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include "Snake.h"
#include <thread>

#define random(x) rand()%(x)

Snake snake(12, 12);
NODE food;
void ChangeDir();
void CreateFood();

void DrawSnake()
{
	clearcliprgn();
	setfillcolor(BLUE);
	for (int i = 0; i < snake.len; i++)
	{
		NODE node = snake.body[i];
		int x = node.x * 20;
		int y = node.y * 20;
		fillrectangle(x + 10, y - 10, x - 10, y + 10);
	}
}
void CreateFood()
{
	srand((int)time(0));
	food.x = 1+random(480 / 20);
	food.y = 1+random(480 / 20);
	food.size = 20;
}

void DrawFood()
{
	setfillcolor(RED);
	fillcircle(food.x*20, food.y*20, 10);
}

using namespace std;
// 主函数
int main()
{
	initgraph(500, 500, SHOWCONSOLE);
	// 创建绘图窗口
	CreateFood();
	thread cd(ChangeDir);
	cd.detach();
	while (true) {
		snake.move();
		if (snake.eat(&food))
			CreateFood();
		DrawSnake();
		DrawFood();
		Sleep(175);
	}

	closegraph();
	while (true)
		cout << _getch() << endl;// 关闭绘图窗口
}

void ChangeDir()
{
	cout << "change dir" << endl;
	while (true)
	{
		switch (_getch())
		{
		case 119:
			snake.changeDir(UP);
			break;
		case  97:
			snake.changeDir(LEFT);
			break;
		case 115:
			snake.changeDir(DOWN);
			break;
		case 100:
			snake.changeDir(RIGHT);
			break;
		default:
			break;
		}
	}

}