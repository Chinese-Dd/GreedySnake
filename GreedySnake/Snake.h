#ifndef _Snake_H_
#define _Snake_H_
#include "Scene.h"
#define N 100
class Snake
{
public:
	Snake();
	void Init();
	bool is_EatSelf();//�Ƿ�Ե��Լ�
	bool is_HitGround();//�Ƿ�ײǽ
	bool is_EatFood();//�Ƿ�Ե�ʳ��
	bool is_Direction(char dir);
	void move(char direction);
	void Show();
private:
	int m_x[N];
	int m_y[N];
	int m_length;
};

#endif