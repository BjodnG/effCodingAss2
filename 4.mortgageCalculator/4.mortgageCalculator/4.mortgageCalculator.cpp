// 4.mortgageCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//Header?
double monthlycost(int debt, double rate, int terms) {

	double newrate = rate / 12;
	double factor = pow((1 + newrate), terms);

	return debt * newrate * factor / (factor - 1);

}

struct monthlyPayment {

	int term;
	int interest;
	int downpayment;
	const int fee = 50;
	int newDebt;

	monthlyPayment(int term, int currentdebt, double interestRate, int monthlyamount) {
		this->term = term;
		this->interest = currentdebt * (interestRate / 12);
		this->downpayment = monthlyamount - this->interest - this->fee;
		this->newDebt = currentdebt - this->downpayment;
	}
};

class loan {
public:

	vector<monthlyPayment> monthlyPayments;

	loan(int debt, int years, double interestRate) {

		int terms = years * 12;
		const int monthyamount = monthlycost(debt, interestRate, terms);
		int currentDebtForTerm = debt;

		for (int term = 1; term <= terms; term++) {
			monthlyPayments.push_back(monthlyPayment(term, currentDebtForTerm, interestRate, monthyamount));
			currentDebtForTerm = this->monthlyPayments[term - 1].newDebt;
		}
	}
	void printMonthlyPaymentInfo() {

		for (monthlyPayment term : this->monthlyPayments) {
			cout << "Term " << term.term << " Interest: " << term.interest << "	Avdrag: " << term.downpayment;
			cout << "	sum interest and downpayment: " << term.downpayment + term.interest;
			cout << "	Remaining debt: " << term.newDebt << endl;
		}

		
	}
};

int main()
{

	loan loanPlan(2000000, 20, 0.04);
	loanPlan.printMonthlyPaymentInfo();

    return 0;
}

