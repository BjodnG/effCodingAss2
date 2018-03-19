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
	int countyNumber;
	int estateNumber;
	int lotNumber;
	int leaseNumber;
public:
	HouseClass(int countyNumber, int estateNumber, int lotNumber, int leaseNumber)
	{
		if (isValidCountyNumber(countyNumber)) {
			this->countyNumber = countyNumber;
			this->estateNumber = estateNumber;
			this->lotNumber = lotNumber;
			this->leaseNumber = leaseNumber;
		}
		else {
			cout << "Invalid countyNumber." << endl;
			this->~HouseClass();
		}
	};
	~HouseClass() {};
	bool isValidCountyNumber(int number) {
		return (number > 0 && number <= 5444) ? true : false;
	}
};

int main()
{
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

	HouseClass houseThree(1, 2, 3, 4);
	HouseClass houseFour(6000, 2, 3, 4);

    return 0;
}

