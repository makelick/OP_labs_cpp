#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BoolMatrix {
private:
	int rows;
	int cols;
	bool** matrix;
public:
	BoolMatrix(int, int);
	BoolMatrix(int, int, bool**);
	BoolMatrix(BoolMatrix&);
	~BoolMatrix();
	int getRows();
	int getCols();
	bool** getMatrix();
};