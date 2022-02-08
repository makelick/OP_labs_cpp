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