// 6.StdLibVectorDrill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> gv{1,2,4,8,16};
vector<int> vv{ 1, 2 * 1, 3 * 2 * 1, 4 * 3 * 2 * 1, 5 * 4 * 3 * 2 * 1, 6 * 5 * 4 * 3 * 2 * 1, 7 * 6 * 5 * 4 * 3 * 2 * 1, 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1, 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1, 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 };

void f(vector<int> &av) {

	vector<int> lv(av.size());
	for (int i = 0; i < av.size(); i++) {
		lv[i] = av[i];
		cout << lv[i] << " ";
	}
	cout << endl;

	vector<int> lv2 = av;
	for (int ele : lv2)
		cout << ele << " ";
	cout << endl;

}

int main()
{
	f(gv);
	f(vv);
    return 0;
}

