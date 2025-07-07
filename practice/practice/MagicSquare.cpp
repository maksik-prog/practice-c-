#include "MagicSquare.h"
#include <sstream>
#include <ostream>
#include <iostream>
#include <sstream>

using namespace std;

int** MagicSquare::createMatrix(int n)
{
    int** matrix = new int* [n];  
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];  
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1;
        }
    }
    return matrix;
}

void MagicSquare::printMatrix(int** matrix, int n)
{
    std::ostringstream oss;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void MagicSquare::deleteMatrix(int** matrix, int n)
{
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];  
    }
    delete[] matrix;
}
