// 1.ConstructorAndDestructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class Transportmiddel {

public:
	string beskrivelse;
	int vekt;

	Transportmiddel(string beskrivelse, int vekt) {

		this->beskrivelse = beskrivelse;
		this->vekt = vekt;

		cout << " + " << this->beskrivelse << " opprettet." << endl;
		cout << "	" << "Vekt: " << this->vekt << endl << endl;

	}
	~Transportmiddel() {
		cout << " - " << this->beskrivelse << " slettes" << endl << endl;
	}

};

class Bil : Transportmiddel {
public:
	int hestekrefter;

	Bil(string beskrivelse, int vekt, int hk) : Transportmiddel(beskrivelse, vekt){

		this->hestekrefter = hk;
		cout << "	" << "Hestekrefter: " << this->hestekrefter << endl << endl;
	}
};

class Baat : Transportmiddel {
public:
	int knop;

	Baat(string beskrivelse, int vekt, int knop) : Transportmiddel(beskrivelse, vekt) {

		this->knop = knop;
		cout << "	" << "Knop: " << this->knop << endl << endl;
	}
};


int main()
{
	cout << "Begynnelse på program: " << endl << endl;

	Transportmiddel trans1("Transportmiddel", 10);
	Bil volvo("volvo", 100, 200);
	Baat yamarin("yamarin", 50, 20);

	{
		cout << "------------------------------" << endl;
		cout << "Begynnelse på nytt scope: " << endl << endl;

		Bil bmw("bmw", 80, 300);

		cout << "Avslutning på scope." << endl;
		cout << "------------------------------" << endl << endl;
	}

	cout << "Avslutning på program" << endl << endl;


    return 0;
}

