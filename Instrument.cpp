#include "Instrument.h"
#include <iostream>
using namespace std;

void Instrument::show()
{
	cout << "Manufacturer: "<<manufacturer << endl
		<< "Model: "<<name << endl
		<< "Price: "<<price << endl
		<< "Year of production: "<<yearOfProduction
		<<endl<< "Ammount: "<<ammount << endl << endl;
}