#include "stdafx.h"
#include "Library.h"
#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <ctype.h>
using namespace std;

 void Library::addBook(string const &ISBN, string const &title, string const &author, Genre genre) {
	try {
		Book newBook(ISBN, title, author, genre);
		cout << "ISBN of new book is: " << newBook.getISBN() << endl;
		this->books.push_back(newBook);

	}
	catch (exception e){
		cout << e.what() << endl;
	}
}
void Library::addPatron(Patron newPatron) {
	this->patrons.push_back(newPatron);
}
void Library::checkInOutBook(string ISBN, bool checkOut) {

	for (Book book : this->books) {
		if (book.getISBN() == ISBN) {
			book.checkInOutBook(checkOut);
		}
		else {
			cout << "Can't find book." << endl;
		}
	}

}
vector<Patron> Library::findPatronsWithFees() {

	vector <Patron> patronsWithFee;

	for (Patron patron : this->patrons) {
		if (patron.hasFees())
			patronsWithFee.push_back(patron);
	}
	return patronsWithFee;
}


Book::Book(string const &ISBN, string const &title, string const &author, Genre genre) {
		if (validateISBNinput(ISBN)) {
			this->ISBN = ISBN;
			this->title = title;
			this->author = author;
		}
		else {
			cout << "Invalid ISBN" << endl;
			throw exception();
			//this->~Book();
		}
	}
Book::~Book() {};
bool Book::operator==(Book otherBook) {
	
	return (this->ISBN == otherBook.getISBN()) ? true : false;
}
void Book::checkInOutBook(bool checkOut) {
	this->checkedOut = checkOut;
}
bool Book::isCheckedOut() {
	return this->checkedOut;
}
void Book::printInfo() {

}
string Book::getISBN() {
	return this->ISBN;
}
bool Book::validateISBNinput(string const &ISBN) {
	cout << ISBN << endl;
	
	if (ISBN.length() != 4) return false;
	for (int i = 0; i < 3; i++)
		if (!isdigit(ISBN.at(i))) return false;
	if (!isdigit(ISBN.at(3)) && !isalpha(ISBN.at(3))) return false;
	
	return true;
}


Patron::Patron(string firstName, string lastName, int cardNumber) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->cardNumber = cardNumber;
}
void Patron::printInfo() {

}
bool Patron::hasFees() {
	return (this->amountOfFees > 0) ? true : false;
}
void Patron::addFee() {
	this->amountOfFees++;
}

