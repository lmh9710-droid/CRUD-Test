#include <stdio.h>
#include <sqlite3.h>
#include "sqlite_test.h"

void CreateDB(char* db_name)
{

    sqlite3* db;
    char* errMsg = NULL;

    if(sqlite3_open(db_name, &db) != SQLITE_OK)
    {
        printf("데이터베이스 열기 실패\n");
        return;
    }

    const char* query =
       "CREATE TABLE IF NOT EXISTS person ("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "phone TEXT"
        ");";
   
    if(sqlite3_exec(db, query, NULL, NULL, &errMsg) != SQLITE_OK)
    {
        printf("테이블 생성 실패: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    else {
        printf("%s 테이블 생성완료\n",db_name);
    }

    sqlite3_close(db);

    return;

}

void InsertDB(char* db_name)
{
    sqlite3* db;
    char* errMsg = NULL;

    if(sqlite3_open(db_name, &db) != SQLITE_OK)
    {
        printf("데이터베이스 열기 실패\n");
        return;
    }

    const char* query =
    "INSERT INTO person VALUES"
        "(1,'Hong Gil Dong','010-1234-5678'),"
        "(2,'Lee Sun Shin','010-2345-6789'),"
        "(3,'Kim Yu Shin','010-3456-7890'),"
        "(4,'Park Ji Sung','010-4567-8901'),"
        "(5,'Choi Min Soo','010-5678-9012');";

        if(sqlite3_exec(db, query, NULL, NULL, &errMsg) != SQLITE_OK)
        {
            printf("데이터 삽입 실패: %s\n", errMsg);
            sqlite3_free(errMsg);
        }
        else
        {
            printf("데이터 삽입 완료\n");
        }

        sqlite3_close(db);
        return;
}