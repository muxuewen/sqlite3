#include <cstdio> 
#include <cstdlib>
#include "sqlite.h"

int Sqlite::testdb()
{
	sqlite3 *db = NULL;

	char *zErrMsg = 0;

	int rc;



	//打开指定的数据库文件,如果不存在将创建一个同名的数据库文件

	rc = sqlite3_open("zsl.db", &db);

	if (rc)

	{

		fprintf(stderr, "Can’t open database : %s\n", sqlite3_errmsg(db));

		sqlite3_close(db);

		return (1);

	}

	else

		printf("You have opened a sqlite3 database named zsl.db successfully!\n");



	//创建一个表,如果该表存在，则不创建，

	//并给出提示信息，存储在zErrMsg 中

	char *sql = "CREATE TABLE test(ID INTEGER PRIMARY KEY, AGE INTEGER, LEVEL INTEGER, NAME VARCHAR(12), SALARY REAL); ";

	sqlite3_exec(db, sql, 0, 0, &zErrMsg);



	//插入数据

	sql = "INSERT INTO \"test\" VALUES(NULL, 1, 1, '200605011206', 18.9);"; 

	sqlite3_exec(db, sql, 0, 0, &zErrMsg);

	int nrow = 0, ncolumn = 0; //查询结果集的行数、列数

	char **azResult; //二维数组存放结果



	//查询数据

	sql = "SELECT * FROM test ";

	sqlite3_get_table(db, sql, &azResult, &nrow, &ncolumn, &zErrMsg);

	int i = 0;

	printf("row:%d column = %d \n", nrow, ncolumn);

	printf("\nThe result of querying is : \n");

	for (i = 0; i < (nrow + 1) * ncolumn; i++)

		printf("azResult[%d] = %s\n", i, azResult[i]);



	//删除数据

	sql = "DELETE FROM test WHERE AGE = 1; ";

	sqlite3_exec(db, sql, 0, 0, &zErrMsg);

	//释放掉azResult 的内存空间

	sqlite3_free_table(azResult);

	sqlite3_close(db); //关闭数据库

	int c = getchar();



	return 0;
}