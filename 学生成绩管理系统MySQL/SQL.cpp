#include"GUI.h"
#include"SQL.h"

SQL::SQL()
{
	color(14);
	system("NET START MySQL");
	cout << "��ʼ�����ݿ�....." << endl;
	if (mysql_init(&this->mysql) != NULL &&
		mysql_real_connect(&this->mysql, host, user, password, database_name, 3306, NULL, 0) != NULL &&
		mysql_set_character_set(&mysql, "GBK") == 0)
	{
		color(11);
		cout << "���ݿ��ʼ���ɹ�";
	}
	else
	{
		color(12);
		cout << "���ݿ��ʼ��ʧ�ܣ�" << endl;
		cout << mysql_error(&this->mysql) << endl;
		system("pause");
		exit(-1);
	}
}

SQL::~SQL()
{
	system("cls");
	cout << "���ڹر����ݿ� . . ." << endl;
	mysql_close(&this->mysql);
	system("NET STOP MySQL");
}

unsigned __int64 SQL::Get_table_lines()
{
	this->query("SELECT * FROM STU;");
	MYSQL_RES*result = this->store_result();
	unsigned __int64 num = mysql_num_rows(result);
	mysql_free_result(result);
	return num;
}