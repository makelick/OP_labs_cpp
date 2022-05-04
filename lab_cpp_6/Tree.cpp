#include "Tree.h"

void addElement(Branch*& branch, double element) {
	if (!branch) {
		branch = new Branch;
		branch->leftBranch = NULL;
		branch->rightBranch = NULL;
		branch->data = element;
		return;
	}

	if (element >= branch->data) {
		addElement(branch->rightBranch, element);
	}
	else {
		addElement(branch->leftBranch, element);
	}
}

void printTree(Branch* branch, int tabs) {
	if (!branch) {
		return;
	}
	printTree(branch->rightBranch, ++tabs);

	for (int i = 1; i < tabs; i++) {
		cout << "\t";
	}
	cout << branch->data << endl;

	printTree(branch->leftBranch, tabs);
}

void swapMaxAndMin(Branch*& branch) {
	if (!branch) {
		return;
	}
	double max = getMax(branch);
	double min = getMin(branch);
	setOnMaxPos(branch, min);
	setOnMinPos(branch, max);
	
}

double getMin(Branch* branch) {
	if (branch->leftBranch != NULL) {
		return getMin(branch->leftBranch);
	}
	else {
		return branch->data;
	}
}

double getMax(Branch* branch) {
	if (branch->rightBranch != NULL) {
		return getMax(branch->rightBranch);
	}
	else {
		return branch->data;
	}
}

void setOnMaxPos(Branch*& branch, double val) {
	if (branch->rightBranch != NULL) {
		setOnMaxPos(branch->rightBranch, val);
	}
	else {
		branch->data = val;
		return;
	}
}

void setOnMinPos(Branch*& branch, double val) {
	if (branch->leftBranch != NULL) {
		setOnMinPos(branch->leftBranch, val);
	}
	else {
		branch->data = val;
		return;
	}
}
