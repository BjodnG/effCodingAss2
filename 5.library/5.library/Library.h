#pragma once
#include <vector>
#include <string>
#include <ctime>
using namespace std;
class Library {
public:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;

	void addBook(Book newBook);
	void addPatron(Patron newPatron);
	void checkInOutBook(string ISBN);
	vector<Patron> findPatronsWithFees();
	
};

class Book {
private:
	string ISBN;
	string title;
	string author;
	//ctime date;
	bool checkedOut;
	Genre genre;

public:
	void checkInOutBook(bool checkOut);
	bool getCheckedIn();

	void printInfo();
	string getISBN();
};

enum Genre {
	fiction,
	nonfiction,
	periodical,
	biography,
	children
};

class Patron {
private:
	string firstName;
	string lastName;
	int cardNumber;
	int amountOfFees;

public:
	void printInfo();
	bool hasFees();
	void setFees();

};

struct Transaction {
	Book book;
	Patron patron;
	// DATE
};