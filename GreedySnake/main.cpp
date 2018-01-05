#include<iostream>
#include <conio.h>
#include<Windows.h>
#include<time.h>
#include "Scene.h"
char dir = 'w';//Ĭ�Ϸ���,δ����ʱ
int score = 0;
double speed;
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
	gotoXY(5, 30);
	std::cout << "��ӭ����̰������Ϸ!" << std::endl;
	gotoXY(8, 28);
	std::cout << "�밴 W��A��S��D �����Ʒ���." << std::endl;
	gotoXY(11, 30);
	std::cout << " ���ո����ͣ��Ϸ." << std::endl;
	gotoXY(14, 29);
	std::cout << " ���������ʼѡ���Ѷ�." << std::endl;
	_getch();
	system("cls");
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

void Go()
{
	system("cls");
	snake.move();
	if (snake.is_EatFood())
	{
		score++;
		food.Set_Food();
	}
	map.Show_Map();
	gotoXY(5, 63);
	std::cout << "�÷�:" << score << std::endl;
}

void Init()//��ʼ������
{
	_getch();
	system("cls");
	map.Init_Map();
	snake.Init();
	food.Set_Food();
	map.Show_Map();
}

void Select()
{
	std::cout << "\n\n\n\t\t\t��������ſ�ʼ��Ϸ:" << std::endl;
	std::cout << "\n\n\n\t\t\t1.��ģʽ" << std::endl;
	std::cout << "\n\n\n\t\t\t2.����ģʽ" << std::endl;
	std::cout << "\n\n\n\t\t\t3.����ģʽ" << std::endl;
	std::cout << "\n\n\n\t\t\t4.����ģʽ" << std::endl;
	int hard;
	int flag = 1;
	while (flag)
	{
		std::cin >> hard; //������Żس���,��֪��Ϊɶ����������������ܽ�����Ϸ(BUG1��)
		switch (hard)
		{
		case 1:
			speed = 0.25;
			flag = 0;
			break;
		case 2:
			speed = 0.15;
			flag = 0;
			break;
		case 3:
			speed = 0.02;
			flag = 0;
			break;
		case 4:
			speed = 0.0001;
			flag = 0;
			break;
		default:
			std::cout << "����������,����������." << std::endl;
				flag = 1;
				break;
		}
	}
}

int main()
{
	Welcome();
	Select();
	Init();
	while (1)
	{
		double start = (double)clock() / CLOCKS_PER_SEC;
		while (1)                                                                                        //���������Ѷ�
		{
		    double end = (double)clock() / CLOCKS_PER_SEC;
		    if (end - start >=speed) break;                                  
		}
		if (!_kbhit())
			Go();
		else
		{
		   snake.ChangeDirection();
		  Go();
		}
		if (is_Dead())
			exit(0);
	}
	return 0;
}

