#include "Header.h"

struct employee {

	struct date {
		int day;
		int month;
		int year;

		bool save(string line) {
			vector<string> dmy = split(line, '.');
			day = stoi(dmy[0]);
			month = stoi(dmy[1]);
			year = stoi(dmy[2]);
			if (day > 31 || month > 12) {
				cout << "Entered invalid date" << endl;
				return 0;
			}
			return 1;
		}

		string get_format() {
			string str_day = to_string(day);
			string str_month = to_string(month);
			if (day < 10) {
				str_day = '0' + to_string(day);
			}
			if (month < 10) {
				str_month = '0' + to_string(month);
			}
			return str_day + '.' + str_month + '.' + to_string(year);
		}
	};

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
			if (words.size() < 3) {
				cout << "Invalid input" << endl;
			}
			else {
				strcpy_s(person.surname, words[0].c_str());
				if (person.birthday.save(words[1]) && (person.start_career.save(words[2]))) {
					fileout.write((char*)&person, sizeof(employee));
				}
			}
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
