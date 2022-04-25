#include "BoolMatrix.h"

int main()
{
    srand(time(NULL));
    int rows;
    int cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    BoolMatrix matrix1(rows, cols);
    cout << "First matrix: " << endl;
    matrix1.printMatrix();

    bool** mtr = initMatrix(rows, cols);
    BoolMatrix matrix2(rows, cols, mtr);
    cout << "Second matrix: " << endl;
    matrix2.printMatrix();

    BoolMatrix matrix3 = matrix1 | matrix2;
    cout << "Third matrix (matrix1 | matrix2): " << endl;
    matrix3.printMatrix();

    matrix3 = ~matrix3;
    cout << "Third matrix (~matrix3): " << endl;
    matrix3.printMatrix();

    cout << "Number of 1 in matrix is " << matrix3.countTrue() << endl;

    deleteMatrix(mtr, rows);
    return 0;
}