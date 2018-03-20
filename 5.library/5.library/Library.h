#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <ctime>
using namespace std;

enum Genre {
	fiction,
	nonfiction,
	periodical,
	biography,
	children
};

class Book {
private:
	string ISBN;
	string title;
	string author;
	//ctime date;
	bool checkedOut;
	Genre genre;

	bool validateISBNinput(string const &ISBN);

public:
	Book(string const &ISBN, string const &title, string const &author, Genre genre);
	~Book();
	bool operator==(Book otherBook);
	void checkInOutBook(bool checkOut);
	bool isCheckedOut();

	void printInfo();
	string getISBN();
};

class Patron {
private:
	string firstName;
	string lastName;
	int cardNumber;
	int amountOfFees;

public:
	Patron(string firstName, string lastName, int cardNumber);
	void printInfo();
	bool hasFees();
	void addFee();

};

struct Transaction {
	Book book;
	Patron patron;
	// DATE
};

class Library {
public:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;

	void addBook(string const &ISBN, string const &title, string const &author, Genre genre);
	void addPatron(Patron newPatron);
	void checkInOutBook(string ISBN, bool checkOut);
	vector<Patron> findPatronsWithFees();
	
};
