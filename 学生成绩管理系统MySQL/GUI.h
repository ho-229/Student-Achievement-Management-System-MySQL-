#pragma once

#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

int color(int c);												//设置控制台字体颜色
void GUI(int a, int b, int c, int d, int col);//a,b '-';c,d'|'	//打印边框
void gotoxy(int x, int y);										//设定光标位置
void GUI_1();													//界面模板1
void GUI_2();													//界面模板2