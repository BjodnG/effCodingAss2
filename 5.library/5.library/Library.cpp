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
	bool checkedOut;
	Genre genre;

public:
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
	int amountOfFees;

public:
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