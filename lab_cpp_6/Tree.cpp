#include "Tree.h"

Tree::Tree() {
	root = NULL;
}

void Tree::addElement(double element) {
	this->addElementRecursion(root, element);
}

void Tree::addElementRecursion(Branch*& branch, double element) {
	if (!branch) {
		branch = new Branch;
		branch->leftBranch = NULL;
		branch->rightBranch = NULL;
		branch->data = element;
		return;
	}

	if (element >= branch->data) {
		addElementRecursion(branch->rightBranch, element);
	}
	else {
		addElementRecursion(branch->leftBranch, element);
	}
}

void Tree::printTree() {
	this->printTreeRecursion(root, 0);
}

void Tree::printTreeRecursion(Branch* branch, int tabs) {
	if (!branch) {
		return;
	}
	printTreeRecursion(branch->rightBranch, ++tabs);

	for (int i = 1; i < tabs; i++) {
		cout << "\t";
	}
	cout << branch->data << endl;

	this->printTreeRecursion(branch->leftBranch, tabs);
}

void Tree::swapMaxAndMin() {
	if (!root) {
		return;
	}
	double max = getMax(root);
	double min = getMin(root);
	setOnMaxPos(root, min);
	setOnMinPos(root, max);
	
}

double Tree::getMin(Branch* branch) {
	if (branch->leftBranch != NULL) {
		return getMin(branch->leftBranch);
	}
	else {
		return branch->data;
	}
}

double Tree::getMax(Branch* branch) {
	if (branch->rightBranch != NULL) {
		return getMax(branch->rightBranch);
	}
	else {
		return branch->data;
	}
}

void Tree::setOnMaxPos(Branch*& branch, double val) {
	if (branch->rightBranch != NULL) {
		setOnMaxPos(branch->rightBranch, val);
	}
	else {
		branch->data = val;
		return;
	}
}

void Tree::setOnMinPos(Branch*& branch, double val) {
	if (branch->leftBranch != NULL) {
		setOnMinPos(branch->leftBranch, val);
	}
	else {
		branch->data = val;
		return;
	}
}
