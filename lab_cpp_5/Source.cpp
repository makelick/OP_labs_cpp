#include "Header.h"

BankAccount::BankAccount(vector<string> attributes) {
	bankName = attributes[0];
	id = stoi(attributes[1]);
	isAvailable = true;
}

CurrentAccount::CurrentAccount(vector<string> attributes) : BankAccount(attributes) {
	balance = stod(attributes[2]);
	lastOperationDate = Date();
}

DepositAccount::DepositAccount(vector<string> attributes) : BankAccount(attributes) {
	balance = stod(attributes[2]);
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

Date::Date(int day, int month, int year) {
	this->year = year;
	this->month = month;
	this->day = day;
}

string Date::getString() {
	string strDay = to_string(day);
	string strMonth = to_string(month);
	if (day < 10) {
		strDay = '0' + to_string(day);
	}
	if (month < 10) {
		strMonth = '0' + to_string(month);
	}
	return strDay + '.' + strMonth + '.' + to_string(year);
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
		vector<string> attributes;
		getline(cin, str);
		attributes = split(str, ',');
		currents.push_back(CurrentAccount(attributes));
		getline(cin, str);
		attributes = split(str, ',');
		deposits.push_back(DepositAccount(attributes));
	}
}

void checkDeposits(int size, vector<CurrentAccount>& currents, vector<DepositAccount>& deposits) {
	Date now = getSystemDate();
	for (int i = 0; i < size; i++)
	{
		Date openDate = deposits[i].getOpeningDate();
		int completedMonth = getMonthsBetweenDates(now, openDate);
		int percents;

		if (completedMonth >= deposits[i].getPeriod())
		{
			percents = deposits[i].getPeriod() * (int)(deposits[i].getBalance() * deposits[i].getRate());
			currents[i].addBalance(deposits[i].getBalance());
			deposits[i].subBalance(deposits[i].getBalance());
			deposits[i].setIsAvailable(false);
			openDate.setMonth(openDate.getMonth() + deposits[i].getPeriod());
		}
		else 
		{
			percents = completedMonth * (int)(deposits[i].getBalance() * deposits[i].getRate());
			openDate.setMonth(openDate.getMonth() + completedMonth);
		}
		while (openDate.getMonth() > 12)
		{
			openDate.setYear(openDate.getYear() + 1);
			openDate.setMonth(openDate.getMonth() - 12);
		}
		currents[i].addBalance(percents);
		currents[i].setLastOperationDate(openDate);
	}
}

void printAccounts(int size, vector<CurrentAccount>& currents, vector<DepositAccount>& deposits) {
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		CurrentAccount c = currents[i];
		DepositAccount d = deposits[i];
		Date lastOp = c.getLastOperationDate();
		string status = d.getIsAvailable() ? "Available" : "Unavailable";

		cout << "Pair " << i + 1 << ": " << endl;

		cout << "id:" << c.getId() 
			<< ", bank name: " << c.getBankName() 
			<< ", date of last operation: " << lastOp.getString() 
			<< ", balance: " << c.getBalance() << endl;

		cout << "status: " << status 
			<< ", id:" << d.getId()
			<< ", bank name: " << d.getBankName()
			<< ", balance: " << d.getBalance() << endl;
	}
}

Date getSystemDate()
{
	struct tm currentTime;
	time_t t = time(NULL);
	localtime_s(&currentTime, &t);

	return 	Date(currentTime.tm_mday, currentTime.tm_mon + 1, currentTime.tm_year + 1900);
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