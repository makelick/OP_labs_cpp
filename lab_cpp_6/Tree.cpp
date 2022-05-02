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
