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
};

vector<string> split(string, char);