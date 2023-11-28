#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"


int main()
{
	srand(time(NULL));
	test();
	int n = 1;
	printf("To exit type 0.\n");
	printf("Enter matrix size: ");
	while (n != 0) 
	{
		scanf_s("%d", &n);
		printf("\n%d x %d quadratic matrix:\n\n", n, n);
		int** matrix = matrixBuilder(n);
		matrix = addNumbers(matrix, n);
		printMatrix(matrix, n);

		printf("Matrix determinant: %d\n", determinant(matrix, n));

		clear(matrix, n);
	}
	return 0;
}