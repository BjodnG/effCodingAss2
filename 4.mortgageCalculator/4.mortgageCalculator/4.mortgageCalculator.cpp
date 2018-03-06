// 4.mortgageCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

struct loan {
public:
	int beginingDebt;
	double interestRate;
	int terms;
	int monthyamount;
	//int interestAmonunt;
	//int downpaymentAmount;

};

struct monthlyPayment {
	int term;
	int debt;
	int interest;
	int downpayment;
	const int fee = 50;

	monthlyPayment(int term, int currentdebt, double interestRate, int monthlyamount) {
		//this->debt = currentdebt;
		this->interest = (currentdebt * interestRate) - this->fee;
		this->downpayment = monthlyamount - this->interest;
		this->debt = currentdebt - this->downpayment;
	}
};

double monthlycost(int l, double r, int n) {
	double factor = pow((1 + r), n);
	double t = l * r * factor / (factor - 1);
	cout << t << endl;
	return t;
}

int main()
{
	monthlycost(2000000, 0.03, 1);
    return 0;
}

