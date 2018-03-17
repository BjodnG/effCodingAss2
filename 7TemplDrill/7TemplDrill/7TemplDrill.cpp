// 7TemplDrill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T> struct S{
	T val;
	S(T arg) {
		val = arg;
	}
};	


int main()
{
	const int i = 22;
	S<int> Integer(i);
	cout << Integer.val << endl;

	const char c = 'c';
	S<char> Character(c);
	cout << Character.val << endl;

	const double d = 1.5;
	S<char> Double(d);
	cout << Double.val << endl;

	string streng = "En streng med tekst";
	S<string> enStreng(streng);
	cout << enStreng.val << endl;

	vector<int> listemedint(3, 5);
	S<vector<int>> enListe(listemedint);
	for (int el : enListe.val) {
		cout << el << endl;
	}
	
    return 0;
}

