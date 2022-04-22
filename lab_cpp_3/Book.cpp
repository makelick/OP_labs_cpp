#include "Book.h"

Book::Book() {};
Book::Book(string line) {
	vector<string> atributes = split(line, ',');
	author = atributes[0];
	title = atributes[1];
	year = stoi(atributes[2]);
	numberOfPages = stoi(atributes[3]);
};

vector<string> split(string str, char separator)
{
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
