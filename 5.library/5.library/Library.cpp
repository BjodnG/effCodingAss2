#include <vector>
#include <string>
#include <ctime>
#include <iostream>
using namespace std;

class Library {
public:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;

	void addBook(Book newBook) {
		this->books.push_back(newBook);
	}
	void addPatron(Patron newPatron) {
		this->patrons.push_back(newPatron);
	}
	void checkInOutBook(string ISBN, bool checkOut) {

		for (Book book : this->books) {
			if (book.getISBN() == ISBN) {
				book.checkInOutBook(checkOut);
			}
			else {
				cout << "Can't find book." << endl;
			}
		}

	}
	vector<Patron> findPatronsWithFees() {

		vector <Patron> patronsWithFee;

		for (Patron patron : this->patrons) {
			if (patron.hasFees())
				patronsWithFee.push_back(patron);
		}
		return patronsWithFee;
	}

};

class Book {
private:
	string ISBN;
	string title;
	string author;
	//ctime date;
	bool checkedOut = false;
	Genre genre;

public:
	Book(string const &ISBN, string const &title, string const &author, Genre genre) {
		this->ISBN = ISBN;
		this->title = title;
		this->author = author;
	}
	void checkInOutBook(bool checkOut) {
		this->checkedOut = checkOut;
	}
	bool getCheckedOut() {
		return this->checkedOut;
	}

	void printInfo();
	string getISBN() {
		return this->ISBN;
	}

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
	int amountOfFees = 0;

public:
	Patron(string firstName, string lastName, int cardNumber) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->cardNumber = cardNumber;
	}
	void printInfo();
	bool hasFees() {
		return (this->amountOfFees > 0) ? true : false;
	}
	void addFee() {
		this->amountOfFees++;
	}

};

struct Transaction {
	Book book;
	Patron patron;
	// DATE	
};