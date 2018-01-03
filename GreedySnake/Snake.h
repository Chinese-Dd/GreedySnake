#ifndef _Snake_H_
#define _Snake_H_
#include "Scene.h"
const int N = 25,M =50;
const int length =300;
class Snake
{
public:
	int m_x[length];
	int m_y[length];
	int m_length;
	void Init();
	bool is_EatSelf();//�Ƿ�Ե��Լ�
	bool is_HitGround();//�Ƿ�ײǽ
	bool is_EatFood();//�Ƿ�Ե�ʳ��
	bool is_Direction(char dir);
	void move(char direction);
	void Show();
    
};
extern Snake snake;
#endif