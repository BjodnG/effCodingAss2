// 7TemplDrill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

template <typename T> struct S{
private:
	T val;
public:
	S(T arg) {
		val = arg;
	}
	T get();
	void set(T newVal);
};

template<typename T>
T S<T>::get()
{
	T& valRef = this->val;
	return valRef;
}

template<typename T>
void S<T>::set(T newVal)
{
	this->val = newVal;
}

int main()
{
	string streng = "En streng med tekst";
	S<string> enStreng(streng);
	cout << enStreng.get() << endl;

	enStreng.set("En ny streng satt med setter.");
	cout << enStreng.get() << endl;

	const int i = 22;
	S<int> Integer(i);
	cout << Integer.get() << endl;
	
	const char c = 'c';
	S<char> Character(c);
	cout << Character.get() << endl;

	const double d = 20.5;
	S<char> Double(d);
	cout << Double.get() << endl;


	vector<int> listemedint(3, 5);
	S<vector<int>> enListe(listemedint);
	for (int el : enListe.get()) {
		cout << el << endl;
	}

    return 0;
}


