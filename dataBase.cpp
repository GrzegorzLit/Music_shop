#include "dataBase.h"
#include "Instrument.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void DataBase::loadData()
{
	ifstream data("instrumentsDataBase.txt");
	if ( data )
	{
		string breaklines;
		int countBreaklines = 0;

		ifstream dataCount("instrumentsDataBase.txt");
		while ( getline(dataCount, breaklines) )
		{
			if ( breaklines == "" )
			{
				countBreaklines++;
			}
		}

		string record;
		int counter = 0;
		instrumentsCount = 0;
		int stop = 0;
		while ( getline(data, record) )
		{
			counter++;
			

			if ( counter == 1 )
				instruments[instrumentsCount].manufacturer = record;
			else if ( counter == 2 )
				instruments[instrumentsCount].name = record;
			else if ( counter == 3 )
				instruments[instrumentsCount].price = stoi(record);
			else if ( counter == 4 )
				instruments[instrumentsCount].yearOfProduction = stoi(record);
			else if ( counter == 5 )
				instruments[instrumentsCount].ammount = stoi(record);
			else if ( counter == 6 )
			{
				counter = 0;
				instrumentsCount++;
			}
		};
	}
	else
	{
		cout << "ERROR: can not read file" << endl;
	}
}

void DataBase::mainDataBase()
{
	for ( int i = 0; i < instrumentsCount+1; i++ )
	{
		instruments[i].show();
	}
}

void DataBase::manufacturerFilter()
{
	string manufacturer;
	cout << "What manufacturer?: ";
	cin >> manufacturer;

	for ( int i = 0; i < instrumentsCount+1; i++ )
	{
		if ( instruments[i].manufacturer == manufacturer )
		{
			instruments[i].show();
		}

	}
}

void DataBase::addInstrument()
{
	string manufacturer;
	string model;
	int price;
	int yearOfProduction;
	int ammount;

	cout << "Manufacturer:: ";
	cin >> manufacturer;
	cout << "Model: ";
	cin >> model;
	cout << "Price: ";
	cin >> price;
	cout << "Year of production: ";
	cin >> yearOfProduction;
	cout << "Ammount: ";
	cin >> ammount;

	fstream file;
	file.open("instrumentsDataBase.txt", ios::out | ios::app);

	file <<endl<< manufacturer << endl;
	file << model << endl;
	file << price << endl;
	file << yearOfProduction << endl;
	file << ammount << endl;

}