#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <random>

int randomInteger();

int** addNumbers(int** matrix, int n);

int** matrixBuilder(int n);

void clear(int** matrix, int n);

void printMatrix(int** matrix, int n);

int determinant(int** matrix, int n);

void test();
#endif

