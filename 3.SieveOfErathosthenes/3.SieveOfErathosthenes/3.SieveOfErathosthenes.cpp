// 3.SieveOfErathosthenes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	SieveOfEratosthenes(50);
    return 0;
}

void SieveOfEratosthenes(int n) {

	vector<bool> primes(n + 1, true);

	for (int p = 2; p*p <= n; p++) {

		if (primes[p] == true) {
			for (int i = p * 2; i <= n; i += p)
				primes[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (primes[p])
			cout << p << " ";

	cout << endl;
}