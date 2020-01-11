#include<iostream>
#include<Windows.h>
#include<string>
#include<ctime>
#include"GUI.h"
#include"SQL.h"
using namespace std;

struct Student
{
	unsigned short num;
	string name;
	float math;
	float chinese;
	float English;
	float sum;
};

SQL sql;									//��ʼ�����ݿ�

void menu();
void In();
void Search();
void del();
void modify();
void Print_allstu(bool mode);				//mode=ture:��ѧ��;mode=false:������;

void menu()
{
	while (true)
	{
		int ch;
		GUI_1();
		color(11);
		gotoxy(27, 7);
		cout << "1.¼��ɼ���Ϣ";
		gotoxy(27, 9);
		cout << "2.��ѯ�ɼ���Ϣ";
		gotoxy(27, 11);
		cout << "3.ɾ���ɼ���Ϣ";
		gotoxy(27, 13);
		cout << "4.�޸ĳɼ���Ϣ";
		gotoxy(27, 15);
		cout << "0.�˳�����";
		gotoxy(24, 17);
		color(12);
		cout << "��ѡ��[ 0 - 4 ]:[ ]\b\b";
		color(14);
		cin >> ch;
		switch (ch)
		{
		case 1:
			In();
			break;
		case 2:
			GUI_1();
			color(11);
			gotoxy(25, 8);
			cout << "1.��ѧ�Ų���ѧ����Ϣ";
			gotoxy(25, 10);
			cout << "2.��ѧ�Ŵ�ӡѧ����Ϣ";
			gotoxy(25, 12);
			cout << "3.��������ӡѧ����Ϣ";
			gotoxy(25, 14);
			cout << "0.���ز˵�";
			color(12);
			gotoxy(24, 17);
			cout << "��ѡ��[ 0 - 3 ]:[ ]\b\b";
			color(14);
			cin >> ch;
			if (ch == 1)
				Search();
			else if (ch == 2)
				Print_allstu(true);
			else if (ch == 3)
				Print_allstu(false);
			break;
		case 3:
			del();
			break;
		case 4:
			modify();
			break;
		default:
			return;
		}
	}
}

void In()
{
	int ch;
	Student Temp;
start:
	GUI_1();
	if (sql.Get_table_lines() == 0)
	{
		color(14);
		gotoxy(29, 6);
		cout << "��ǰ�޼�¼";
	}
	gotoxy(20, 7);
	color(11);
	cout << "ѧ��:";
	cin >> Temp.num;
	gotoxy(40, 7);
	cout << "����:";
	cin >> Temp.name;
	gotoxy(15, 9);
	cout << "��ѧ:";
	cin >> Temp.math;
	gotoxy(30, 9);
	cout << "����:";
	cin >> Temp.chinese;
	gotoxy(45, 9);
	cout << "Ӣ��:";
	cin >> Temp.English;
	Temp.sum = Temp.math + Temp.chinese + Temp.English;
	if (sql.query("INSERT INTO STU VALUES(" + to_string(Temp.num) + ",'" + Temp.name 
		+ "'," + to_string(Temp.chinese) + ',' + to_string(Temp.math) + ',' 
		+ to_string(Temp.English) + ',' + to_string(Temp.sum) + ", NOW());"))
	{
		GUI_1();
		color(12);
		gotoxy(10, 8);
		cerr << "¼��ʧ��:" << sql.error() << endl;
		color(11);
		gotoxy(10, 10);
		system("pause");
		return;
	}
	else
	{
		GUI_1();
		color(11);
		gotoxy(28, 11);
		cout << Temp.name << " ¼��ɹ�";
		color(12);
		gotoxy(21, 17);
		cout << "1.���ز˵�;2����;��ѡ��:[ ]\b\b";
		cin >> ch;
		if (ch == 2)
			goto start;
	}
	return;
}

void Search()
{
	int ch, snum;
	if (sql.Get_table_lines() == 0)
	{
		GUI_1();
		color(14);
		gotoxy(29, 6);
		cout << "��ǰ�޼�¼";
		color(11);
		gotoxy(10, 9);
		system("pause");
	}
	else
	{
	start:
		GUI_1();
		gotoxy(13, 6);;
		cout << "������ѧ��:";
		cin >> snum;
		sql.query("SELECT * FROM STU WHERE ID=" + to_string(snum) + ';');
		MYSQL_RES*result = sql.store_result();
		if (mysql_num_rows(result) == NULL)
		{
			GUI_1();
			color(12);
			gotoxy(27, 8);
			cerr << "�޷��ҵ��˼�¼" << endl;
			gotoxy(21, 11);
			cout << "1.���ز˵�;2����;��ѡ��:[ ]\b\b";
			cin >> ch;
			if (ch == 2)
			{
				mysql_free_result(result);
				goto start;
			}
		}
		else
		{
			MYSQL_ROW row = mysql_fetch_row(result);
			GUI_1();
			color(14);
			gotoxy(51, 17);
			cout << "����:" << sql.Get_table_lines();
			color(11);
			gotoxy(21, 7);
			cout << "ѧ��:" << row[0];
			gotoxy(40, 7);
			cout << "����:" << row[1];
			gotoxy(15, 9);
			cout << "��ѧ:";
			gotoxy(25, 9);
			cout << "����:";
			gotoxy(35, 9);
			cout << "Ӣ��:";
			gotoxy(45, 9);
			cout << "�ܷ�:";
			gotoxy(15, 11);
			cout << "¼������:" << row[6];
			color(12);
			gotoxy(20, 9);
			cout << row[3];
			gotoxy(30, 9);
			cout << row[2];
			gotoxy(40, 9);
			cout << row[4];
			gotoxy(50, 9);
			cout << row[5];			
			color(12);
			gotoxy(21, 13);
			cout << "1.���ز˵�;2����;��ѡ��:[ ]\b\b";
			cin >> ch;
			if (ch == 2)
				goto start;
			mysql_free_result(result);
		}
	}
	return;
}

void del()
{
	int ch, snum;
	char chose;
	if (sql.Get_table_lines() == 0)
	{
		GUI_1();
		color(14);
		gotoxy(29, 6);
		cout << "��ǰ�޼�¼";
		color(11);
		gotoxy(10, 9);
		system("pause");
	}
	else
	{
		MYSQL_RES*result;
	start:
		GUI_1();
		gotoxy(13, 6);;
		cout << "������ѧ��:";
		cin >> snum;
		sql.query("SELECT * FROM STU WHERE ID=" + to_string(snum) + ';');
		result = sql.store_result();
		if (mysql_num_rows(result) != 1)
		{
			GUI_1();
			color(12);
			gotoxy(27, 8);
			cerr << "�޷��ҵ��˼�¼" << endl;
			gotoxy(21, 11);
			cout << "1.���ز˵�;2����;��ѡ��:[ ]\b\b";
			cin >> ch;
			if (ch == 2)
				goto start;
		}
		else
		{
			color(12);
			gotoxy(13, 7);
			cout << "�ҵ�ѧ�ţ��Ƿ�ɾ����(y/n)";
			cin >> chose;
			if (chose == 'Y' || chose == 'y')
			{
				if (sql.query("DELETE FROM STU WHERE ID=" + to_string(snum) + ';'))
				{
					GUI_1();
					color(12);
					gotoxy(10, 7);
					cout << "ɾ��ʧ��:" << sql.error() << endl;
					color(11);
					gotoxy(10, 9);
					system("pause");
					mysql_free_result(result);
					return;
				}
				else
				{
					GUI_1();
					color(11);
					gotoxy(30, 8);
					cout << "��ɾ��";
					color(12);
					gotoxy(20, 11);
					cout << "1.���ز˵�;2����;��ѡ��:[ ]\b\b";
					cin >> ch;
					if (ch == 2)
						goto start;
				}
			}
		}
		mysql_free_result(result);
	}
	return;
}

void modify()
{
	int ch, snum;
	Student Temp;
	if (sql.Get_table_lines() == 0)
	{
		GUI_1();
		color(14);
		gotoxy(29, 6);
		cout << "��ǰ�޼�¼";
		color(11);
		gotoxy(10, 9);
		system("pause");
	}
	else
	{
		MYSQL_RES*result;
	start:
		GUI_1();
		gotoxy(13, 6);
		cout << "������ѧ��:";
		cin >> snum;
		sql.query("SELECT * FROM STU WHERE ID=" + to_string(snum) + ';');
		result = sql.store_result();
		if (mysql_num_rows(result) == 0)
		{
			GUI_1();
			color(12);
			gotoxy(27, 8);
			cerr << "�޷��ҵ��˼�¼" << endl;
			gotoxy(21, 11);
			cout << "1.���ز˵�;2����;��ѡ��:[ ]\b\b";
			cin >> ch;
			if (ch == 2)
				goto start;
		}
		else
		{
			color(11);
			gotoxy(40, 7);
			cout << "����:";
			cin >> Temp.name;
			gotoxy(15, 9);
			cout << "��ѧ:";
			cin >> Temp.math;
			gotoxy(30, 9);
			cout << "����:";
			cin >> Temp.chinese;
			gotoxy(45, 9);
			cout << "Ӣ��:";
			cin >> Temp.English;
			Temp.sum = Temp.math + Temp.chinese + Temp.English;
			if (sql.query("UPDATE STU SET name='" + Temp.name + "',chinese=" + to_string(Temp.chinese) 
				+ ",math=" + to_string(Temp.math) + ",English=" + to_string(Temp.English) 
				+ ",sum=" + to_string(Temp.sum) + " where ID=" + to_string(snum) + ';'))
			{
				GUI_1();
				color(12);
				gotoxy(10, 8);
				cerr << "�޸�ʧ��:" << sql.error() << endl;
				color(11);
				gotoxy(10, 9);
				system("pause");
			}
			else
			{
				GUI_1();
				color(11);
				gotoxy(28, 11);
				cout << Temp.name << " �޸ĳɹ�";
				color(12);
				gotoxy(21, 17);
				cout << "1.���ز˵�;2����;��ѡ��:[ ]\b\b";
				cin >> ch;
				if (ch == 2)
					goto start;
			}
		}
		mysql_free_result(result);
	}
	return;
}

void Print_allstu(bool mode)
{
	int i;
	if (sql.Get_table_lines() == 0)
	{
		GUI_1();
		color(14);
		gotoxy(29, 6);
		cout << "��ǰ�޼�¼";
		color(11);
		gotoxy(10, 9);
		system("pause");
	}
	else
	{
		if (mode == true)
			sql.query("SELECT * FROM STU ORDER BY ID ASC;");		//��ѧ�������ӡ
		else
			sql.query("SELECT * FROM STU ORDER BY sum DESC;");		//�Գɼ������ӡ
		MYSQL_RES*result = sql.store_result();
		MYSQL_ROW row;
		GUI_2();
		color(14);
		gotoxy(28, 6);
		cout << "ѧ��      ����      ��ѧ     ����     Ӣ��";
		gotoxy(60, 4);
		cout << "����:" << mysql_num_rows(result);
		color(15);
		gotoxy(34, 6);
		cout << "|";
		gotoxy(45, 6);
		cout << "|";
		gotoxy(54, 6);
		cout << "|";
		gotoxy(63, 6);
		cout << "|";
		for ( i = 0; row = mysql_fetch_row(result); i++)
		{
			color(15);
			gotoxy(34, i * 2 + 8);
			cout << "|";
			gotoxy(45, i * 2 + 8);
			cout << "|";
			gotoxy(54, i * 2 + 8);
			cout << "|";
			gotoxy(63, i * 2 + 8);
			cout << "|";
			color(11);
			gotoxy(29, i * 2 + 8);
			cout << row[0];
			gotoxy(37, i * 2 + 8);
			cout << row[1];
			color(12);
			gotoxy(48, i * 2 + 8);
			cout << row[3];
			gotoxy(57, i * 2 + 8);
			cout << row[2];
			gotoxy(66, i * 2 + 8);
			cout << row[4];
			color(15);
			gotoxy(26, i * 2 + 7);
			cout << "--------+----------+--------+--------+--------";
		}
		GUI(5, 7 + i * 2, 25, 72, 15);
		mysql_free_result(result);
		color(13);
		gotoxy(41, i * 2 + 9);
		system("pause");
	}
}

int main()
{
	menu();
	return EXIT_SUCCESS;
}