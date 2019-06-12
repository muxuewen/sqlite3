#include <cstdio> 
#include <cstdlib>
#include "sqlite.h"

int Sqlite::testdb()
{
	sqlite3 *db = NULL;

	char *zErrMsg = 0;

	int rc;



	//��ָ�������ݿ��ļ�,��������ڽ�����һ��ͬ�������ݿ��ļ�

	rc = sqlite3_open("zsl.db", &db);

	if (rc)

	{

		fprintf(stderr, "Can��t open database : %s\n", sqlite3_errmsg(db));

		sqlite3_close(db);

		return (1);

	}

	else

		printf("You have opened a sqlite3 database named zsl.db successfully!\n");



	//����һ����,����ñ���ڣ��򲻴�����

	//��������ʾ��Ϣ���洢��zErrMsg ��

	char *sql = "CREATE TABLE test(ID INTEGER PRIMARY KEY, AGE INTEGER, LEVEL INTEGER, NAME VARCHAR(12), SALARY REAL); ";

	sqlite3_exec(db, sql, 0, 0, &zErrMsg);



	//��������

	sql = "INSERT INTO \"test\" VALUES(NULL, 1, 1, '200605011206', 18.9);"; 

	sqlite3_exec(db, sql, 0, 0, &zErrMsg);

	int nrow = 0, ncolumn = 0; //��ѯ�����������������

	char **azResult; //��ά�����Ž��



	//��ѯ����

	sql = "SELECT * FROM test ";

	sqlite3_get_table(db, sql, &azResult, &nrow, &ncolumn, &zErrMsg);

	int i = 0;

	printf("row:%d column = %d \n", nrow, ncolumn);

	printf("\nThe result of querying is : \n");

	for (i = 0; i < (nrow + 1) * ncolumn; i++)

		printf("azResult[%d] = %s\n", i, azResult[i]);



	//ɾ������

	sql = "DELETE FROM test WHERE AGE = 1; ";

	sqlite3_exec(db, sql, 0, 0, &zErrMsg);

	//�ͷŵ�azResult ���ڴ�ռ�

	sqlite3_free_table(azResult);

	sqlite3_close(db); //�ر����ݿ�

	int c = getchar();



	return 0;
}