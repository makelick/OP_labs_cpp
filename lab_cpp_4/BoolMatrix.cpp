#include "BoolMatrix.h"

int BoolMatrix::getRows() { return rows; };

int BoolMatrix::getCols() { return cols; };

bool** BoolMatrix::getMatrix() { return matrix; };

BoolMatrix::BoolMatrix(int rws, int cls) {
    rows = rws;
    cols = cls;
    matrix = new bool* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new bool[cols];
    }

    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
};

BoolMatrix::BoolMatrix(int rws, int cls, bool** matr) {
    rows = rws;
    cols = cls;
    matrix = new bool* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new bool[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = matr[i][j];
        }
    }
};

BoolMatrix::BoolMatrix(BoolMatrix& other) {
    rows = other.rows;
    cols = other.cols;
    matrix = new bool* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new bool[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
};

BoolMatrix::~BoolMatrix() {
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
};