#include "BoolMatrix.h"

BoolMatrix::BoolMatrix(int rws, int cls) {
    rows = rws;
    cols = cls;
    matrix = initMatrix(rws, cls);
}

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
}

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
}

BoolMatrix::~BoolMatrix() {
    deleteMatrix(matrix, rows);
}

int BoolMatrix::getRows() { return rows; }

int BoolMatrix::getCols() { return cols; }

bool** BoolMatrix::getMatrix() { return matrix; }

int BoolMatrix::countTrue() {
    int res = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j]) 
            {
                res++;
            }
        }
    }
    return res;
}

void BoolMatrix::printMatrix() {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

BoolMatrix& BoolMatrix::operator~() {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = !matrix[i][j];
        }
    }
    return *this;
}

BoolMatrix& BoolMatrix::operator|(BoolMatrix& other) {
    BoolMatrix& res = *this;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            res.matrix[i][j] = matrix[i][j] | other.matrix[i][j];
        }
    }
    return res;
}

bool** initMatrix(int rows, int cols) {
    bool** matrix = new bool* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new bool[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}

void deleteMatrix(bool** mtr, int rows) {
    for (int i = 0; i < rows; i++)
    {
        delete[] mtr[i];
    }
    delete[] mtr;
}