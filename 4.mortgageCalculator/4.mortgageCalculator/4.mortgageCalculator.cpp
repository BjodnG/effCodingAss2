// 4.mortgageCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
#include "mortgageCalc.h"

using namespace std;

int main()
{

	loan loanPlan(2000000, 20, 0.04);
	loanPlan.printMonthlyPaymentInfo();

    return 0;
}

