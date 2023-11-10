#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define num 3
int randomInteger(int n) 
{ 
    
    int x;
    x = rand() % n;
    return x;
}

int determinant(int matrix[num][num], int n)
{
    int d = 0;
    int a = 0;
    int b = 0; 
    int evenSign = 1;
    int temp[num][num];
    if(n == 1)
    {
        d = matrix[0][0];
    }
    else if (n == 2) 
    {
        d = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
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
            printf("\n");
            printf("%d + ", d);
            d += (evenSign * matrix[0][x] * determinant(temp,n - 1));
            evenSign = -evenSign;
            printf("%d * %d * %d = %d\n",evenSign,matrix[0][x],determinant(temp,n-1),d);
            
            printf("\n");
            for (int column = 0; column < n - 1; column++)
            {
                for (int row = 0; row < n - 1; row++)
                {
                    printf("%d ", temp[column][row]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
    }
    
    return d;
}


int main()
{
    srand(time(NULL));
    int matrix[num][num];
    for (int column = 0; column <num;column++) 
    {
        for (int row = 0; row < num; row++) 
        {
            matrix[column][row] = randomInteger(10);
        }
    }
    for (int column = 0; column < num; column++)
    {
        for (int row = 0; row < num; row++)
        {
            printf("%d\t", matrix[column][row]);
        }
        printf("\n\n");
    }

    printf("%d",determinant(matrix, num));
    return 0;
}
