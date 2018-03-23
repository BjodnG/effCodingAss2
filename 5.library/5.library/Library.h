#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <ctime>
#include <ostream>
#include <algorithm>
#include "BjarneDate.cpp"
using namespace std;
using namespace Chrono;

enum Genre {
	fiction,
	nonfiction,
	periodical,
	biography,
	children
};

class Book {
private:
	bool checkedOut;
	string ISBN;
	string title;
	string author;
	//ctime date;
	Genre genre;

	bool validateISBNinput(string const &ISBN);

public:
	Book();
	Book(string const &ISBN, string const &title, string const &author, Genre genre);
	~Book();
	bool operator==(Book otherBook);
	bool operator!=(Book otherBook);
	friend ostream& operator<<(ostream& stream, const Book& book);
	void checkInOutBook(bool checkOut);

	bool isCheckedOut();
	string getISBN();
	string getTitle();
	string getAuthor();
	//ctime date;
	Genre getGenre();
};

struct Fee {
	int price;
};

class Patron {
private:
	string username;
	int cardNumber;
	vector<Fee> fees;

public:
	Patron();
	Patron(string username, int cardNumber);
	bool operator==(Patron otherPatron);
	bool operator!=(Patron otherPatron);
	string getUsername();
	int getCardNumber();
	bool hasFees();
	void addFee(int price);
	vector<Fee> getFees();
};

struct Transaction {
	Book book;
	Patron patron;
	Chrono::Date date;
	Transaction();
	Transaction(Book const &book, Patron const &patron, Chrono::Date date);
};

class Library {
public:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;

	void addBook(string const &ISBN, string const &title, string const &author, Genre genre);
	Book* getBook(string const &ISBN);
	void addPatron(string const &username, int const &cardnumber);
	Patron* getPatron(string const &username);
	void checkInOutBook(string ISBN, string username, Chrono::Date date, bool checkOut);
	vector<string> findPatronsWithFees();
	
};
