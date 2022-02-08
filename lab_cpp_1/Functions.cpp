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