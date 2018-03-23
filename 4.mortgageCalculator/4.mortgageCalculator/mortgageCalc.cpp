

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
#include "mortgageCalc.h"

monthlyPayment::monthlyPayment(int term, int currentdebt, double interestRate, int monthlyamount) {
	this->term = term;
	this->interest = currentdebt * (interestRate / 12);
	this->downpayment = monthlyamount - this->interest - this->fee;
	this->newDebt = currentdebt - this->downpayment;
}

loan::loan(int debt, int years, double interestRate) {

	int terms = years * 12;
	const int monthyamount = monthlycost(debt, interestRate, terms);
	int currentDebtForTerm = debt;

	for (int term = 0; term <= terms; term++) {
		this->monthlyPayments.push_back(monthlyPayment(term, currentDebtForTerm, interestRate, monthyamount));
		currentDebtForTerm = this->monthlyPayments[term].newDebt; //updates the current debt for next iteration.
	}
};

void loan::printMonthlyPaymentInfo() {

	vector<int> interestPayments;
	vector<int> downpayments;

	for (monthlyPayment term : this->monthlyPayments) {
		cout << "Term " << term.term << " Interest: " << term.interest << "	Avdrag: " << term.downpayment;
		cout << "	sum interest and downpayment: " << term.downpayment + term.interest;
		cout << "	Remaining debt: " << term.newDebt << endl;
		interestPayments.push_back(term.interest);
		downpayments.push_back(term.downpayment);
	}
	cout << "Total interest paid: " << accumulate(interestPayments.begin(), interestPayments.end(), 0) << endl;
	cout << "Total downpayments: " << accumulate(downpayments.begin(), downpayments.end(), 0) << endl;
}


double monthlycost(int debt, double rate, int terms) {

	double newrate = rate / 12;
	double factor = pow((1 + newrate), terms);

	return debt * newrate * factor / (factor - 1);

}