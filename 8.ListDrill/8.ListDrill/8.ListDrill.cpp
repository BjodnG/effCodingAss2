// 8.ListDrill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>
using namespace std;

list<int> l{1,2,3,4,5};
list<int>::iterator it;

// Skal den initialiseres på en spesiell måte??
list<int> l2 = l;

int main()
{
	it = find(l.begin(), l.end(), 3);
	(*it == 3) ? cout << *it : cout << "Finnes ikke.";
	cout << endl;

	it = find(l2.begin(), l2.end(), 3);
	(*it == 3) ? cout << *it : cout << "Finnes ikke.";
	cout << endl;
    return 0;
}

