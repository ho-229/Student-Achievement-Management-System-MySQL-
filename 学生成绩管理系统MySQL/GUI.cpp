#include"GUI.h"

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

void GUI(int a, int b, int c, int d, int col)//a,b '-';c,d'|';
{
	int i, j = 1;
	color(col);
	for (i = a; i <= b; i++)
	{
		for (j = c; j <= d; j++)
		{
			gotoxy(j, i);
			if (i == a || i == b)cout << "-";
			else if (j == c || j == d)cout << "|";
		}
	}
}

void GUI_1()
{
	system("mode con cols=70 lines=23");	//设置控制台窗口大小
	tm lt;
	time_t now;
	time(&now);
	localtime_s(&lt, &now);
	gotoxy(22, 2);
	color(14);
	cout << "学 生 成 绩 管 理 系 统";
	GUI(5, 18, 7, 60, 15);
	color(11);
	gotoxy(9, 16);
	cout << lt.tm_year + 1900 << "/" << lt.tm_mon + 1 << "/" << lt.tm_mday;
	gotoxy(9, 17);
	cout << lt.tm_hour << ":" << lt.tm_min;
}

void GUI_2()
{
	system("mode con cols=100 lines=30");	//设置控制台窗口大小
	tm lt;
	time_t now;
	time(&now);
	localtime_s(&lt, &now);
	gotoxy(38, 2);
	color(14);
	cout << "学 生 成 绩 管 理 系 统";
	color(11);
	gotoxy(2, 27);
	cout << lt.tm_year + 1900 << "/" << lt.tm_mon + 1 << "/" << lt.tm_mday;
	gotoxy(2, 28);
	cout << lt.tm_hour << ":" << lt.tm_min;
}