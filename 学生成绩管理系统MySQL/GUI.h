#pragma once
#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

inline int color(int c);										//���ÿ���̨������ɫ
inline void gotoxy(int x, int y);								//�趨���λ��
void GUI(int a, int b, int c, int d, int col);//a,b '-';c,d'|'	//��ӡ�߿�
void GUI_1();													//����ģ��1
void GUI_2();													//����ģ��2