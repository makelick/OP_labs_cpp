#pragma once
#include <iostream>
#include <stack>

using namespace std;

struct Branch {
	double data;
	Branch* leftBranch;
	Branch* rightBranch;
};

class Tree {
private:
	Branch* root;

	double getMax(Branch*);
	double getMin(Branch*);
	void setOnMaxPos(Branch*&, double);
	void setOnMinPos(Branch*&, double);
public:
	Tree();
	Branch*& getRoot() { return root; }
	void addElement(Branch*& , double);
	void printTree(Branch*, int);
	void swapMaxAndMin(Branch*&);
};
