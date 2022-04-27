#include "Header.h"

BankAccount::BankAccount(vector<string> attributes) {
	bankName = attributes[0];
	id = stoi(attributes[1]);
	isAvailable = true;
}

CurrentAccount::CurrentAccount(vector<string> attributes) {
	balance = stoi(attributes[2]);
	lastOperationDate = Date();
}

DepositAccount::DepositAccount(vector<string> attributes) {
	balance = stoi(attributes[2]);
	rate = stod(attributes[3]);
	openingDate = Date(attributes[4]);
	period = stoi(attributes[5]);
}

Date::Date(string str) {
	vector<string> temp = split(str, '.');
	day = stoi(temp[0]);
	month = stoi(temp[1]);
	year = stoi(temp[2]);
}

Date::Date(int year = 1900, int month = 1, int day = 1) {
	this->year = year;
	this->month = month;
	this->day = day;
}

int getMonthsBetweenDates(Date& date1, Date& date2) {
	return ((date1.year - date2.year) * 12) + date1.month - date2.month;
}

void initVectors(int size, vector<CurrentAccount>& currents, vector<DepositAccount>& deposits) {
	cout << "Enter info about accounts in format" << endl;
	cout << "For current account: [bank name, id, balance]" << endl;
	cout << "For deposit account: [bank name, id, balance, rate, dd.mm.yyyy, period]" << endl;
	cout << "and again..." << endl;

	for (int i = 0; i < size; i++)
	{
		string str;
		getline(cin, str);
		vector<string> attributes = split(str, ',');
		currents.push_back(CurrentAccount(attributes));
		getline(cin, str);
		vector<string> attributes = split(str, ',');
		deposits.push_back(DepositAccount(attributes));
	}
}

vector<string> split(string str, char separator) {
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