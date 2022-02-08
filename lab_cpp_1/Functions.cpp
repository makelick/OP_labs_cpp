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
		do {
			getline(cin, line);
			fileout << line << "\n";
		} while (!line.empty());
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
			vector<string> words = split(line);
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