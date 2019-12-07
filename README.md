# Student-Achievement-Management-System-MySQL-
### 开发环境
* IDE：Visual Studio 2017<br>
* Compiler：Microsoft Visual C++ 2017（x64）<br>
* SQL：MySQL-8.0.17-win（x64）
---------
### 项目介绍 
* 这是一个基于MySQL的学生成绩管理系统，里面用到了 `MySQL C++ API` 以及一些SQL命令等等，希望能够帮到大家，也请各位大佬多多指教。<br>
---------
### 运行说明
* 正确安装对应版本的MySQL数据库，并正确添加MySQL库文件到项目中。<br>
* 正确创建数据库和数据表。（下面提供参考步骤，省略数据库初始化及登录）<br>
>```sql
>mysql>CREATE DATABASE IF NOT EXISTS test_db_char
>    -> DEFAULT CHARACTER SET utf8
>    -> DEFAULT COLLATE utf8_chinese_ci;
>Query OK, 1 row affected
>mysql>CREATE TABLE stu
>    -> (
>    -> ID INT(10) NOT NULL PRIMARY KEY,
>    -> name CHAR(10),
>    -> chinese FLOAT,
>    -> math FLOAT,
>    -> English FLOAT,
>    -> sum FLOAT,
>    -> date DATE
>    -> ); 
>Query OK, 0 rows affected
>```
* 正确填写信息并以x64编译
---------
### 关于作者
* QQ：2189684957<br>
* E-mail：2189684957@qq.com<br>