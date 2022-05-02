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
