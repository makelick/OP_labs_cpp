#include "Header.h"

struct date {
	int day;
	int month;
	int year;

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
		cout << "Surname: " << surname << "\t\t";
		cout << "Birthday: " << birthday.get_format() << "\t\t";
		cout << "Start career: " << start_career.get_format() << endl;
	}
};


void input_file(string file_path)
{
	cout << "Choose input mode:" << endl << "1) append info in the file" << endl << "2) create new file" << endl;
	string input_mode;
	getline(cin, input_mode);
	
	ofstream fileout;
	while (true) {
		if (!input_mode.compare("1"))
		{
			fileout.open(file_path, ios::app);
			break;
		}
		else if (!input_mode.compare("2"))
		{
			fileout.open(file_path);
			break;
		}
		else {
			cout << "Invalid input mode";
		}
	}

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
			strcpy_s(person.surname, words[0].c_str());
			if (person.birthday.save(words[1]) && (person.start_career.save(words[2]))) {
				fileout.write((char*)&person, sizeof(employee));
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

void birthday_in_this_month(string file_path)
{
	ifstream filein;
	filein.open(file_path);

	if (!filein.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		employee person;
		date sys_date = get_system_date();
		while (filein.read((char*)&person, sizeof(employee)))
		{
			int work_expirience = get_years_between_dates(person.start_career, sys_date);
			if (person.birthday.month == sys_date.month && work_expirience >= 5)
			{
				person.print();
			}

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
		employee person;
		date sys_date = get_system_date();
		while (filein.read((char*)&person, sizeof(employee)))
		{
			int start_career_age = get_years_between_dates(person.birthday, person.start_career);
			int work_expirience = get_years_between_dates(person.start_career, sys_date);
			if (start_career_age <= 25 && work_expirience >= 10)
			{
				fileout.write((char*)&person, sizeof(employee));
			}
		}
	}

	filein.close();
	fileout.close();
}

template <typename T1, typename T2>
int get_years_between_dates(T1 start_date, T2 end_date)
{
	int years = end_date.year - start_date.year;
	if (start_date.month > end_date.month || (start_date.month == end_date.month && start_date.day > end_date.day))
	{
		years -= 1;
	}
	return years;
}

date get_system_date()
{
	date res;
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	res.day = aTime->tm_mday;
	res.month = aTime->tm_mon + 1;
	res.year = aTime->tm_year + 1900;

	return res;
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
