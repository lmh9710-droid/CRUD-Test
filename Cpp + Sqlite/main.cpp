#include <iostream>
#include "sqlite_test.h"

int main()
{ sqlite3* db= nullptr;
  DataBase* database= new DataBase("vendor.db", db);

  // database->Create_DB();
  // database->Insert_DB();
  database->Select_DB();
  delete database;
  return 0;

}