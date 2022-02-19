#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct employee;
struct date;

void input_file(string);
void output_file(string);
vector<string> split(string, char);