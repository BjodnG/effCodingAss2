// 8.ListDrill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>
using namespace std;

list<int> aList{1,2,3,4,5};
list<int>::iterator it;

list<int> anotherList = aList;

int main()
{
	it = find(aList.begin(), aList.end(), 3);
	(*it == 3) ? cout << *it : cout << "Finnes ikke.";
	cout << endl;

	it = find(anotherList.begin(), anotherList.end(), 3);
	(*it == 3) ? cout << *it : cout << "Finnes ikke.";
	cout << endl;
    return 0;
}

