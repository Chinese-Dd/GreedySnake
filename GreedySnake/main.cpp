#include<iostream>
#include <conio.h>
#include<Windows.h>
#include "Scene.h"

void gotoXY(int x, int y)
{
	HANDLE hout;
	COORD coord;
	coord.X = y;             //x��y�ǵߵ���.���ϲ鲻��,���û��ͨ....
	coord.Y = x;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	return;
}

void Welcome()
{
	std::cout << "\n\n\n\t\t\t ��ӭ����̰������Ϸ!" << std::endl;
	std::cout << "\n\n\n\t\t\t�밴 W��A��S��D �����Ʒ���." << std::endl;
	std::cout << "\n\n\n\t\t\t ���ո����ͣ��Ϸ." << std::endl;
	std::cout << "\n\n\n\t\t\t ����������Ͽ�ʼ." << std::endl;
}

bool is_Dead()
{
	if (snake.is_EatSelf())
	{
		gotoXY(27, 0);
		std::cout << "\n\n\n\t\t\t ��Ե����Լ�,��Ϸ����!" << std::endl;
		return 1;
	}
	else  if (snake.is_HitGround())
	{
		gotoXY(27, 0);
		std::cout << "\n\n\n\t\t\t ײǽ��,��Ϸ����!" << std::endl;
		return 1;
	}
	else
		return 0;

}
int main()
{
	Welcome();
	_getch();
	system("cls");
	map.Init_Map();
	snake.Init();
	food.Set_Food();
	map.Show_Map();
	int score=0;
	while (1)
	{
		char dir = _getch();
		if (dir == ' ')
		{
			gotoXY(26, 0);
			system("pause");
			std::cout << "���ո��������Ϸ." << std::endl;
			if(dir == ' ')
			continue;
		}
		if (snake.is_Direction(dir))
		{
			system("cls");
			snake.move(dir);
			snake.Show();
			if (snake.is_EatFood())
			{
			    score++;
				food.Set_Food();
			}
			map.Show_Map();
			gotoXY(5, 63);
			std::cout << "�÷�:" << score << std::endl;
		}
		if (is_Dead())
			exit(0);
	}
	return 0;
}

