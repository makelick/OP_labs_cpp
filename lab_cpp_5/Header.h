#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int day = 1, int month = 1, int year = 1900);
	Date(string);
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	void setYear(int year) { this->year = year; }
	void setMonth(int month) { this->month = month; }
	void setDay(int day) { this->day = day; }
	friend int getMonthsBetweenDates(Date&, Date&);
};

class BankAccount {
private:
	string bankName;
	int id;
	bool isAvailable;
public:
	BankAccount() {};
	BankAccount(vector<string>);
	virtual void addBalance(int) = 0;
	virtual void subBalance(int) = 0;
};

class CurrentAccount : public BankAccount {
private:
	Date lastOperationDate;
	int balance;
public:
	CurrentAccount(vector<string>);
	virtual void addBalance(int sum) { balance += sum; };
	virtual void subBalance(int sum) { balance -= sum; };
};

class DepositAccount : public BankAccount {
private:
	Date openingDate;
	int period;
	int balance;
	double rate;
public:
	DepositAccount(vector<string>);
	virtual void addBalance(int sum) { balance += sum; };
	virtual void subBalance(int sum) { balance -= sum; };
};

void initVectors(int, vector<CurrentAccount>&, vector<DepositAccount>&);
Date getSystemDate();
vector<string> split(string, char);
