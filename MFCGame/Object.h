#ifndef __OBJECT_H__
#define __OBJECT_H__

#include"Globals.h"
#include"Random.h"
//�ĸ�����
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

class Object{
public:
	//ͼ��
	CImage character;
	//��С
	int width;
	int height;
	//λ��
	int x; 
	int y;
	//�ٶ�
	int speed;
	//����
	int direct;
	//�����ж���ײ
	int xCenter;
	int yCenter;
	//����
	int life;

	void calCenter(){
		xCenter = x + width / 2;
		yCenter = y + height / 2;
	}

	virtual void draw(CDC* cDC){
		character.Draw(*cDC, x, y, width, height, 0, 0, character.GetWidth(), character.GetHeight());
	}

	virtual void move(){
		if (direct == UP)y -= speed;
		else if (direct == DOWN)y += speed;

		calCenter();
	}

	virtual void move(int x, int y){//��ɻ��ƶ�
		//ˮƽ���򿿽�
		if (this->x<x)this->x += speed;
		else if (this->x>x)this->x -= speed;
		//��ֱ�����Ͽ���
		if (this->y < y)this->y += speed;
		else if (this->y>y) this->y -= speed;

		calCenter();
	}

	~Object(){
		character.Destroy();
	}
};

class Beauty :public Object{
public:
	Beauty(){
		character.Load(_T("fox.png"));

		width = character.GetWidth();
		height = character.GetHeight();
		
		x = WINDOW_WIDTH;
		y =-character.GetHeight();

		direct = UP;
		speed = 3;

		calCenter();
	}
};

class Flower :public Object{
public:
	Flower(){
		character.Load(_T("flower.png"));

		width = character.GetWidth()/4;
		height = character.GetHeight()/4;

		x = random(0, WINDOW_WIDTH);
		y = random(0, WINDOW_HEIGHT);

		speed = 1;
	}

	void move(){
		y += speed;
		if (y >= WINDOW_HEIGHT)y = 0;

		if (rand() % 2 == 0)
			x += speed;
		else x -= speed;
		if (x<0)x = WINDOW_WIDTH;
		else if (x >= WINDOW_WIDTH)x = 0;
	}
};

#endif