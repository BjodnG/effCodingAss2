#include "stdafx.h"
#include "Library.h"
#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <ostream>
#include <ctype.h>
#include <algorithm>
#include "BjarneDate.cpp"
using namespace std;
using namespace Chrono;

Book::Book(){}
Book::Book(string const &ISBN, string const &title, string const &author, Genre genre) {
		if (validateISBNinput(ISBN)) {
			this->ISBN = ISBN;
			this->title = title;
			this->author = author;
			this->genre = genre;
		}
		else {
			throw exception("Invalid ISBN");
		}
	}
Book::~Book() {};
bool Book::operator==(Book otherBook) {
	
	return (this->ISBN == otherBook.getISBN()) ? true : false;
}
bool Book::operator!=(Book otherBook) {

	return (this->ISBN != otherBook.getISBN()) ? true : false;
}
ostream& operator<<(ostream& stream, const Book& book) {
	stream << book.title << endl;
	stream << book.author << endl;
	stream << book.ISBN << endl;
	return stream;
}
void Book::checkInOutBook(bool checkOut) {
	this->checkedOut = checkOut;
}
bool Book::isCheckedOut() {
	return this->checkedOut;
}
string Book::getISBN() {
	return this->ISBN;
}
string Book::getTitle() {
	return this->title;
}
string Book::getAuthor() {
	return this->author;
}
Genre Book::getGenre() {
	return this->genre;
}
bool Book::validateISBNinput(string const &ISBN) {
	cout << ISBN << endl;
	
	if (ISBN.length() != 4) return false;
	for (int i = 0; i < 3; i++)
		if (!isdigit(ISBN.at(i))) return false;
	if (!isdigit(ISBN.at(3)) && !isalpha(ISBN.at(3))) return false;
	
	return true;
}

Patron::Patron() {}
Patron::Patron(string username, int cardNumber) {
	this->username = username;
	this->cardNumber = cardNumber;
}
bool Patron::operator==(Patron otherPatron) {
	return (this->cardNumber == otherPatron.getCardNumber()) ? true : false;
}
bool Patron::operator!=(Patron otherPatron) {
	return(this->cardNumber != otherPatron.getCardNumber()) ? true : false;
}
string Patron::getUsername() {
	return this->username;
}
int Patron::getCardNumber() {
	return this->cardNumber;
}
bool Patron::hasFees() {
	cout << "hasFees: " << this->fees.size() << endl;
	return (this->fees.size() > 0) ? true : false;
}
void Patron::addFee(int price) {
	Fee fee;
	fee.price = price;
	this->fees.push_back(fee);
}
vector<Fee> Patron::getFees() {
	return this->fees;
}

Transaction::Transaction() {}
Transaction::Transaction(Book const &book, Patron const &patron, Chrono::Date date) {
	this->book = book;
	this->patron = patron;
	this->date = date;
}

void Library::addBook(string const &ISBN, string const &title, string const &author, Genre genre) {
	try {
		Book newBook(ISBN, title, author, genre);
		cout << "ISBN of new book is: " << newBook.getISBN() << endl;
		this->books.push_back(newBook);

	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}
Book* Library::getBook(string const &ISBN) {

	Book *bookToBeFetched = NULL;
	for (Book book : this->books) {
		if (book.getISBN() == ISBN) {
			cout << book.getISBN() << endl;
			bookToBeFetched = &book;
		}
	}
	if (!bookToBeFetched)
		throw exception("Book doesn't exist");
	return bookToBeFetched;

}
void Library::addPatron(string const &username, int const &cardnumber) {
	Patron newPatron(username, cardnumber);
	this->patrons.push_back(newPatron);
}
Patron* Library::getPatron(string const &username) {

	Patron *patronToBeFetched = NULL;
	for (Patron patron : this->patrons) {
		if (patron.getUsername() == username) {
			patronToBeFetched = &patron;
		}
	}
	if (!patronToBeFetched)
		throw exception("Patron doesn't exist");
	return patronToBeFetched;
}
void Library::checkInOutBook(string ISBN, string username, Chrono::Date date, bool checkOut) {

	try {
		Patron *loaningPatron = this->getPatron(username);
		if (loaningPatron->hasFees()) throw exception("Patron has fee.");
		Book *bookToBeLoaned = this->getBook(ISBN);
		if (bookToBeLoaned->isCheckedOut()) throw exception("Book is checked out.");

		bookToBeLoaned->checkInOutBook(checkOut);
		Transaction transaction(bookToBeLoaned, loaningPatron, date);
		cout << "Book checked out" << endl;
	}
	catch (exception expn) {
		cout << expn.what();
	}

}
vector<string> Library::findPatronsWithFees() {

	vector <string> patronsWithFee;

	for (Patron patron : this->patrons) {
		if (patron.hasFees())
			patronsWithFee.push_back(patron.getUsername());
	}
	return patronsWithFee;
}
