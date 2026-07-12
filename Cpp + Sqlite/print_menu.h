#pragma once
#include <iostream>
#include "sqlite_test.h"

class Menu: public DataBase
{
    public:
    Menu() = default; 
    void Print_Menu() const;
    void Switch_Case();

    ~Menu();

    private: 

};