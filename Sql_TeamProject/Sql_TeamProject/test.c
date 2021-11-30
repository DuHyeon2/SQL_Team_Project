#include <stdio.h>
#include <stdio.h>
#include "insert_db.h"

void main()
{
	DB_connect();
	Insert_tuple();
	Update_tuple();
	Delete_tuple();
}