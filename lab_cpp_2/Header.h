#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct date;
struct employee;

void input_file(string);
void output_file(string);
void birthday_in_this_month(string);
date get_system_date();
vector<string> split(string, char);