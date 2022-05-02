#pragma once
#include <iostream>

using namespace std;

struct Branch {
	double data;
	Branch* leftBranch;
	Branch* rightBranch;
};

void addElement(Branch*&, double);
void printTree(Branch*, int);