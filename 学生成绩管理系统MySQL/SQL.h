#pragma once

#include<iostream>
#include<mysql.h>

#pragma comment(lib,"libmysql.lib")
using namespace std;


class SQL
{
public:
	SQL();
	~SQL();

	unsigned __int64 Get_table_lines();	//获取数据个数
	/*封装MySQL API*/
	inline int query(string my_query) { return mysql_query(&this->mysql, my_query.c_str()); }
	inline const char* error() { return mysql_error(&this->mysql); }
	inline MYSQL_RES* store_result() { return mysql_store_result(&this->mysql); }
private:
	MYSQL mysql;
	/*根据自己实际填写*/
	const char user[7] = { "ho229" };						//ROOT Name
	const char password[12] = { "123456" };					//ROOT PassWord
	const char host[11] = { "localhost" };					//HOST
	const char database_name[18] = { "student_dataBase" };	//DATABASE Name

	/*
	mysql> use student_dataBase
	Database changed
	mysql> desc stu;
	+---------+----------+------+-----+---------+----------------+
	| Field   | Type     | Null | Key | Default | Extra          |
	+---------+----------+------+-----+---------+----------------+
	| ID      | int(10)  | NO   | PRI | NULL    | auto_increment |
	| name    | char(10) | YES  |     | NULL    |                |
	| chinese | float    | YES  |     | NULL    |                |
	| math    | float    | YES  |     | NULL    |                |
	| English | float    | YES  |     | NULL    |                |
	| sum     | float    | YES  |     | NULL    |                |
	| date    | date     | YES  |     | NULL    |                |
	+---------+----------+------+-----+---------+----------------+
	*/
};