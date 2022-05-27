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

	void addElementRecursion(Branch*&, double);
	void printTreeRecursion(Branch*, int);
	double getMax(Branch*);
	double getMin(Branch*);
	void setOnMaxPos(Branch*&, double);
	void setOnMinPos(Branch*&, double);
public:
	Tree();
	void addElement(double);
	void printTree();
	void swapMaxAndMin();
};
