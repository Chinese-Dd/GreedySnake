#include<iostream>
#include <conio.h>
#include "Scene.h"

int main()
{
	std::cout << "\n\n\n\t\t\t ��ӭ����̰������Ϸ!" << std:: endl;
	std::cout << "\n\n\n\t\t\t ����������Ͽ�ʼ!" <<std:: endl;
	std::cout << "\n\n\n\t\t\t�밴 w��s��a��d �����Ʒ���"<< std::endl;


	_getch();
	system("cls");
	Snake snake;
	map.Init_Map();
	snake.Init();
	food.Set_Food();
	map.Show_Map();
	int score=0;
	while (1)
	{
		char dir = _getch();
		if (snake.is_Direction(dir))
		{
			system("cls");
			snake.move(dir);
			snake.Show();
			if (snake.is_EatFood())
			{
				food.Set_Food();
				map.ShowScore(++score);
			}
			map.Show_Map();
		}
		if (snake.is_EatSelf())
		{
			std::cout << "\n\n\n\t\t\t ��Ե����Լ�,��Ϸ����!" << std::endl;
			exit(0);
		}
		if (snake.is_HitGround())
		{
			std::cout << "\n\n\n\t\t\t ײǽ��,��Ϸ����!" << std::endl;
			exit(0);
		}
	}
	return 0;
}

