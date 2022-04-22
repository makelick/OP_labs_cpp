#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Book {
private:
	string author;
	string title;
	int year;
	int numberOfPages;

public:
	Book();
	Book(string);
	int getYear();
	int getNumberOfPages();
	string getInfo();
};

Book* createArray(int);
Book findBooksInRange(Book*, int);
vector<string> split(string, char);