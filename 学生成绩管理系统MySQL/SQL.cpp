#include"GUI.h"
#include"SQL.h"

SQL::SQL()
{
	color(14);
	system("NET START MySQL");
	cout << "初始化数据库....." << endl;
	if (mysql_init(&this->mysql) != NULL &&
		mysql_real_connect(&this->mysql, host, user, password, database_name, 3306, NULL, 0) != NULL &&
		mysql_set_character_set(&mysql, "GBK") == 0)
	{
		color(11);
		cout << "数据库初始化成功";
	}
	else
	{
		color(12);
		cout << "数据库初始化失败！" << endl;
		cout << mysql_error(&this->mysql) << endl;
		system("pause");
		exit(-1);
	}
}

SQL::~SQL()
{
	system("cls");
	cout << "正在关闭数据库 . . ." << endl;
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