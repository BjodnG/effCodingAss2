// 5.library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Library.h"
#include <string>
#include <iostream>
#include <ostream>
#include <algorithm>
using namespace std;
using namespace Chrono;

int main()
{

	Library library;
	library.addBook("123a", "Gummitarzan", "huskerikke", children);
	library.addPatron("bruker", 1234);
	Chrono::Date date(2018, Date::mar, 23);
	library.checkInOutBook("123a", "bruker", date, true);


    return 0;
}
	
