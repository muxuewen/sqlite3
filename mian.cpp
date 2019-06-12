#include "sqlite.h"
#include <iostream>
using namespace std;


int main(int args, int argv[])
{
	Sqlite sq;
	sq.testdb();

	system("PAUSE");
	return 0;
}
