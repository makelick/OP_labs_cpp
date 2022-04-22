#include "Book.h"

Book::Book() {}

Book::Book(string line) {
	vector<string> atributes = split(line, ',');
	author = atributes[0];
	title = atributes[1];
	year = stoi(atributes[2]);
	numberOfPages = stoi(atributes[3]);
};

int Book::getYear() { return year; }

int Book::getNumberOfPages() { return numberOfPages; }

string Book::getInfo() {
	return "Author: " + author + ", title: " + title + ", year: " + to_string(year) + ", number of pages: " + to_string(numberOfPages);
}

Book* createArray(int size) {
	Book* array = new Book[size];
	cout << "Enter information about the books in format [full authors name, title, year, number of pages]:" << endl;
	for (int i = 0; i < size; i++) {
		string str;
		getline(cin, str);
		array[i] = Book(str);
	}
	return array;
}

Book findBooksInRange(Book* array, int size) {
	cout << endl << "Enter the range of years in format [minYear-maxYear]: ";
	string stringRange;
	cin >> stringRange;
	vector<string> range = split(stringRange, '-');
	int minYear = stoi(range[0]);
	int maxYear = stoi(range[1]);
	int maxPages = 0;
	Book bookWithMaxPages;

	cout << endl << "Books published in this range: " << endl;
	for (int i = 0; i < size; i++) {
		int year = array[i].getYear();
		int pages = array[i].getNumberOfPages();
		if (year >= minYear && year <= maxYear) {
			cout << array[i].getInfo() << endl;
			if (pages > maxPages) {
				maxPages = pages;
				bookWithMaxPages = array[i];
			}
		}
	}
	return bookWithMaxPages;
}

vector<string> split(string str, char separator) {
	vector<string> res;
	string slice = "";
	str += " ";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == separator)
		{
			if (slice.length() > 0) {
				res.push_back(slice);
				slice = "";
			}
		}
		else {
			slice += str[i];
		}
	}
	res.push_back(slice);
	return res;
}
