#include <random>


int randomInteger()
{
	
	int x, n;
	int isEven = rand() % 2;
	if (isEven == 1)
	{
		n = 1;
	}
	else if (isEven == 0)
	{
		n = -1;
	}
	x = n * (rand() % 10);
	return x;
}

int** addNumbers(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = randomInteger();
		}
	}
	return matrix;
}

int** matrixBuilder(int n)
{
	int** matrix = (int**)malloc((n) * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc((n) * sizeof(int));
	}
	return matrix;
}

void clear(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void printMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int determinant(int** matrix, int n)
{
	int a, b;
	int d = 0;
	int evenSign = 1;
	int** temp = matrixBuilder(n);
	if (sizeof(matrix) == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return matrix[0][0];
	}
	else if (n == 2)
	{
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	}
	else
	{
		for (int x = 0; x < n; x++)
		{
			a = 0;
			for (int i = 1; i < n; i++)
			{
				b = 0;
				for (int j = 0; j < n; j++)
				{
					if (j != x)
					{
						temp[a][b] = matrix[i][j];
						b++;
					}

				}
				a++;

			}
			printMatrix(temp, n - 1);
			d += (evenSign * matrix[0][x] * determinant(temp, n - 1));
			evenSign = -evenSign;
		}
	}
	clear(temp, n);
	return d;
}

void test()
{
	int numbersForTestTwo[3][3] = { 2,3,2,0,6,7,9,2,0 };
	int numbersForTestThree[5][5] = { 0,6,9,-7,-13,14,5,13,-9,2,11,4,-2,0,10,3,4,5,-2,3,-17,2,3,4,11 };
	int** test = matrixBuilder(0);
	int** testOne = matrixBuilder(3);
	int** testTwo = matrixBuilder(3);
	int** testThree = matrixBuilder(5);						
	if (determinant(test, 1) == NULL)
	{
		printf("Matrix determinant: %d\n", determinant(test, 1));
		printf("Test passed!\n");
	}
	else
	{
		printf("fail!\n");
	}
	printMatrix(test, 1);
	for (int i = 0; i < 3; i++)								//по окончании цикла:
	{														//матрица будет выгл€деть так			
		for (int j = 0; j < 3; j++)							//| 1	2	3 |
		{													//| 2	3	4 |
			testOne[i][j] = i + j + 1;						//| 3	4	5 |
		}
	}
	printMatrix(testOne, 3);
	if (determinant(testOne, 3) == 0)
	{
		printf("Matrix determinant: %d\n", determinant(testOne, 3));
		printf("Test passed!\n");
	}
	else
	{
		printf("fail!\n");
	}														//по окончании цикла
	for (int i = 0; i < 3; i++)								//матрица будет выгл€деть так:
	{														//| 2	3	2 |			
		for (int j = 0; j < 3; j++)							//| 0	6	7 |
		{													//| 9	2	0 |
			testTwo[i][j] = numbersForTestTwo[i][j];
		}
	}
	printMatrix(testTwo, 3);
	if (determinant(testTwo, 3) == 53)
	{
		printf("Matrix determinant: %d\n", determinant(testTwo, 3));
		printf("Test passed!\n");
	}
	else
	{
		printf("fail!\n");
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			testThree[i][j] = numbersForTestThree[i][j];
		}
	}
	printMatrix(testThree, 3);
	if (determinant(testThree, 5) == 27828)
	{
		printf("Matrix determinant: %d\n", determinant(testThree, 5));
		printf("Test passed!\n");
	}
	else
	{
		printf("fail!\n");
	}
	clear(testOne, 3);
	clear(testTwo, 3);
}
