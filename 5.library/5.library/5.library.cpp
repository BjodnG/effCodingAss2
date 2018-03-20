// 5.library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Library.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{

	Library library;
	library.addBook("123a", "Gummitarzan", "huskerikke", children);
	library.addBook("123a", "Gummitarzan2", "huskerikke", children);
	for (Book b : library.books)
		cout << b.getISBN() << endl;

	cout << library.books[0].getISBN() << endl;
	cout << library.books[1].getISBN() << endl;
	//library.books[0].operator==(library.books[1].getISBN());
	cout << (library.books[0] == library.books[1]) << endl;

    return 0;
}
	
