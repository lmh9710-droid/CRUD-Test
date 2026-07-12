#include "sqlite_test.h"
#include "manager_s.h"
#include <iostream>
#include "Format.h"

DataBase::DataBase(const char* db_name, sqlite3* db)
:
mdb_name(db_name),
mdb(db)
{
    if(sqlite3_open(mdb_name.c_str(), &mdb) 
       !=SQLITE_OK)
    {
       std::cout<<"데이터 베이스 오픈 실패"<<std::endl;
    }

    else{
       std::cout<<"데이터 베이스 오픈 성공"<<std::endl;
    }
}

void DataBase::Create_DB()
{
   std::string query=
   "CREATE TABLE IF NOT EXISTS person ("
   "id INTEGER PRIMARY KEY autoincrement,"
   "vendor TEXT NOT NULL,"
   "staff_name TEXT NOT NULL,"
   "phone_number TEXT NOT NULL"
   ");";
   
   char* err_msg = nullptr;
   int result = sqlite3_exec(this->mdb, query.c_str(), nullptr, nullptr, &err_msg);
   
   if(result != SQLITE_OK)
   {
     std::cout<<"테이블 생성 실패"<<std::endl;
   }
}

void DataBase::Insert_DB()
{
   Vendor vendor;
   char* err_msg = nullptr;

   //Table 삽입 정보 입력===============================
   std::cout <<"협력사명 입력" << std::endl;
   std::cin >> vendor.company;
   
   std::cout <<"협력사 담당자 입력" << std::endl;
   std::cin >> vendor.manager;

   std::cout <<"담당자 번호 입력" << std::endl;
   std::cin >> vendor.phone;
 
   std::string query = 
   Format()
   <<"insert into person values("<<vendor.id<<",'"<<vendor.company<<"','"<<vendor.manager<<"','"<<vendor.phone<<"');";
   // std::cout << query << std::endl;
   //==================================================
      
   if(sqlite3_exec(this->mdb, query.c_str(), NULL, NULL, &err_msg) != SQLITE_OK)
   {
            printf("데이터 삽입 실패: %s\n", err_msg);
            sqlite3_free(err_msg);
   }
   
   else {
            printf("데이터 삽입 완료\n");
   }

}

void DataBase::Delete_DB()
{

}

void DataBase::Select_DB()
{
  sqlite3_stmt* stmt;
  
  const std::string query = "select id, vendor, staff_name, phone_number from person;";
  
  if(sqlite3_prepare_v2(this->mdb, query.c_str(), -1, 
                      &stmt, nullptr) != SQLITE_OK)
   {
      std::cout << "조회 준비 실패" << std::endl;
   }

   std::cout<< "ID\tVendor\tName\tPhone" << std::endl;

   while(sqlite3_step(stmt) == SQLITE_ROW)
   {
      int id = sqlite3_column_int(stmt, 0);
      const unsigned char* Vendor = sqlite3_column_text(stmt,1);
      const unsigned char* Name = sqlite3_column_text(stmt, 2);
      const unsigned char* Phone = sqlite3_column_text(stmt, 3);
      
      std::cout << id << "\t"
                << Vendor << "\t"
                << Name << "\t"
                << Phone << "\t" << std::endl;

   }

   sqlite3_finalize(stmt);

   
}

void DataBase::Update_DB()
{
   
}

DataBase::~DataBase()
{
    if(sqlite3_close(this->mdb) == SQLITE_OK)
    {
       std::cout << "데이터베이스 닫혔습니다." << std::endl;
    }//개체(Object) 파괴시 DB Close

    else{
      std::cout << "데이터베이스 닫히지 않음" << std::endl;
    }
}

std::string& get_DBNAME() const
{

}