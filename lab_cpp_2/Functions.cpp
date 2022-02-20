#include "Header.h"

struct date {
	int day;
	int month;
	int year;

	void save(string line) {
		vector<string> dmy = split(line, '.');
		day = stoi(dmy[0]);
		month = stoi(dmy[1]);
		year = stoi(dmy[2]);
	}

	string get_format() {
		return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
	}
};

struct employee {
	char surname[50];
	date birthday;
	date start_career;

	void print() {
		cout << "Surname: " << surname << endl;
		cout << "Birthday: " << birthday.get_format() << endl;
		cout << "Start career: " << start_career.get_format() << endl;
	}
};


void input_file(string file_path)
{
	ofstream fileout;
	fileout.open(file_path);

	if (!fileout.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		string line;
		employee person;
		cout << "Enter information about the employeers in format [surname dd.mm.yyyy dd.mm.yyyy] (send empty line to finish):\n";
		getline(cin, line);
		while (!line.empty()) {
			vector<string> words = split(line, ' ');
			strcpy(person.surname, words[0].c_str());
			person.birthday.save(words[1]);
			person.start_career.save(words[2]);
			fileout.write((char*)&person, sizeof(employee));
			getline(cin, line);
		}
	}

	fileout.close();
}

void output_file(string file_path)
{
	ifstream filein;
	filein.open(file_path);

	if (!filein.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		employee person;
		while (filein.read((char*)&person, sizeof(employee)))
		{
			person.print();
		}
	}
	filein.close();
}

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
