// 7TemplDrill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T> struct S{
public:
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

	const char c = c;
	S<char> Character(c);
	cout << Character.val << endl;

	const double d = 5.5;
	S<char> Double(d);
	cout << Double.val << endl;

	const double d = 5.5;
	S<char> Double(d);
	cout << Double.val << endl;

	
    return 0;
}

