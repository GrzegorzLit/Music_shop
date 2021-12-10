#pragma once
#include <string>
#include "Instrument.h"

using namespace std;
class DataBase
{
public:
	Instrument instruments[100];
	int instrumentsCount = 0;
	void loadData();
	void mainDataBase();
	void manufacturerFilter();
	void addInstrument();
	
};

