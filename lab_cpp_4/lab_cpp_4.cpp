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

    BoolMatrix matrix3(matrix1);
    
    deleteMatrix(mtr, rows);
    return 0;
}