#pragma once

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct monthlyPayment {

	int term;
	int interest;
	int downpayment;
	const int fee = 50;
	int newDebt;

	monthlyPayment(int term, int currentdebt, double interestRate, int monthlyamount);
};

class loan {
public:
	vector<monthlyPayment> monthlyPayments;

	loan(int debt, int years, double interestRate);
	void printMonthlyPaymentInfo();
};

double monthlycost(int debt, double rate, int terms);