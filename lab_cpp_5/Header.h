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
	void setYear(int yr) { year = yr; };
	void setMonth(int mon) { month = mon; };
	void setDay(int d) { day = d; };
	int getYear() { return year; };
	int getMonth() { return month; };
	int getDay() { return day; };
	string getString();
	Date(int day = 1, int month = 1, int year = 1900);
	Date(string);
	friend int getMonthsBetweenDates(Date&, Date&);
};

class BankAccount {
private:
	string bankName;
	int id;
	bool isAvailable;
public:
	BankAccount(vector<string>);
	void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; };
	int getId() { return id; };
	bool getIsAvailable() { return isAvailable; };
	string getBankName() { return bankName; };
	virtual void addBalance(double) = 0;
	virtual void subBalance(double) = 0;
};

class CurrentAccount : public BankAccount {
private:
	Date lastOperationDate;
	double balance;
public:
	CurrentAccount(vector<string>);
	void setLastOperationDate(Date date) { lastOperationDate = date; };
	double getBalance() { return balance; };
	Date getLastOperationDate() { return lastOperationDate; };
	virtual void addBalance(double sum) { balance += sum; };
	virtual void subBalance(double sum) { balance -= sum; };
};

class DepositAccount : public BankAccount {
private:
	Date openingDate;
	int period;
	double balance;
	double rate;
public:
	DepositAccount(vector<string>);
	Date getOpeningDate() { return openingDate; };
	int getPeriod() { return period; };
	double getBalance() { return balance; };
	double getRate() { return rate; };
	virtual void addBalance(double sum) { balance += sum; };
	virtual void subBalance(double sum) { balance -= sum; };
};

void initVectors(int, vector<CurrentAccount>&, vector<DepositAccount>&);
void checkDeposits(int, vector<CurrentAccount>&, vector<DepositAccount>&);
void printAccounts(int, vector<CurrentAccount>&, vector<DepositAccount>&);
Date getSystemDate();
vector<string> split(string, char);
