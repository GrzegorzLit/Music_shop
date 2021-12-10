#include <iostream>
#include <fstream>
#include "Instrument.h"
#include "dataBase.h"
#include <conio.h>

using namespace std;

void menu()
{
    while (1)
    {
        DataBase data;
        data.loadData();
        cout << "1. Show database " << endl;
        cout << "2. Manufacturer filter" << endl;
        cout << "3. Add instrument" << endl;
        int choice;
        cin >> choice;
        system("cls");
        switch ( choice )
        {
        case 1: data.mainDataBase(); break;
        case 2: data.manufacturerFilter(); break;
        case 3:data.addInstrument(); break;
        }
        _getch();
        system("cls");
    }
}


int main()
{
   
    menu();
    

    

}

