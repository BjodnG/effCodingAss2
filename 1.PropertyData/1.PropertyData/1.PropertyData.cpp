// 1.PropertyData.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


struct HouseStruct
{
	int countyNumber;
	int estateNumber;
	int lotNumber;
	int leaseNumber;
	HouseStruct() {};
	HouseStruct(int countyNumber, int estateNumber, int lotNumber, int leaseNumber)
	{
		this->countyNumber = countyNumber;
		this->estateNumber = estateNumber;
		this->lotNumber = lotNumber;
		this->leaseNumber = leaseNumber;
	};
};

class HouseClass
{
public:
	int countyNumber;
	int estateNumber;
	int lotNumber;
	int leaseNumber;

	HouseClass() {};
	HouseClass(int countyNumber, int estateNumber, int lotNumber, int leaseNumber)
	{
		if (isValidCountyNumber(countyNumber)) {
			this->countyNumber = countyNumber;
			this->estateNumber = estateNumber;
			this->lotNumber = lotNumber;
			this->leaseNumber = leaseNumber;
		}
		else {
			throw exception("Invalid countyNumber.");
		}
	};

	~HouseClass() {};

	bool isValidCountyNumber(int number) {
		return (number > 0 && number <= 5444) ? true : false;
	}
};

int main()
{

	// STRUCTS:

	vector<HouseStruct> listOfStructs(0);

	HouseStruct houseOne(712, 4090, 73, 15);
	listOfStructs.push_back(houseOne);

	HouseStruct houseTwo(713, 4091, 74, 16);
	listOfStructs.push_back(houseTwo);

	for (HouseStruct s : listOfStructs) {
		cout << s.countyNumber << endl;
		cout << s.estateNumber << endl;
		cout << s.lotNumber << endl;
		cout << s.leaseNumber << endl;
	}

	// CLASSES:

	vector<HouseClass> listOfClasses(0);

	try {
		HouseClass houseThree(1, 2, 3, 4);
		listOfClasses.push_back(houseThree);
	} 
	catch (exception expn) {
		cout << expn.what() << endl;
	}

	try {
		HouseClass houseFour(6000, 2, 3, 4);
		listOfClasses.push_back(houseFour);
	} 
	catch (exception expn) {
		cout << expn.what() << endl;
	}

	for (HouseClass c : listOfClasses) {
		cout << c.countyNumber << endl;
		cout << c.estateNumber << endl;
		cout << c.lotNumber << endl;
		cout << c.leaseNumber << endl;
	}

    return 0;
}

