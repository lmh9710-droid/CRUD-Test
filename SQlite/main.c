#include <stdio.h>
#include "sqlite_test.h"
#define DBNAME ("vendor.db")

int main()
{
    CreateDB(DBNAME);
    InsertDB(DBNAME);
    
    return 0;
}