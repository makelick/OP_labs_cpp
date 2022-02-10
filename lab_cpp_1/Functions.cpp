#include "Header.h"

void input_file(string name)
{
	ofstream fileout;
	fileout.open(name);

	if (!fileout.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		string line;
		cout << "Enter text (send empty line to finish):\n";
		getline(cin, line);
		while (!line.empty()) {
			fileout << line << "\n";
			getline(cin, line);
		}
	}

	fileout.close();
}

void output_file(string name)
{
	ifstream filein;
	filein.open(name);

	if (!filein.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		string line;
		while (!filein.eof()) {
			getline(filein, line);
			cout << line << "\n";
		}
	}

	filein.close();
}

void create_second_file(string filein_name, string fileout_name)
{
	ifstream filein;
	ofstream fileout;
	filein.open(filein_name);
	fileout.open(fileout_name);

	if (!filein.is_open() || !fileout.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		string line;
		while (!filein.eof()) {
			getline(filein, line);
			if (!line.empty()) {
				vector<string> words = split(line);
				int number_of_words = count_same_words(words);
				fileout << number_of_words << " " << line << "\n";
			}
		}
	}

	filein.close();
	fileout.close();
}

vector<string> split(string str)
{
	vector<string> res;
	string slice = "";
	str += " ";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == ',' || str[i] == ';')
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
	return res;
}

int count_same_words(vector<string> words)
{
	int max_count = 0;

	for (int i = 0; i < words.size(); i++)
	{
		if (count(words.begin(), words.end(), words[i]) > max_count) {
			max_count = count(words.begin(), words.end(), words[i]);
		}
	}

	return max_count;
}
