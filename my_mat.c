#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>
int min(int num1,int num2)
{
    if(num1<num2)
    {
        return num1;
    }
    return num2;
}
void neighborMatrix(int matrix[S][S])
{
    for(int k = 0; k < S; k++)
    {
        for(int i = 0; i < S; i++)
        {
            for (int j = 0; j < S; j++)
            {
                if(i!=j)
                {
                    if(matrix[i][j] != 0)
                    {
                        if(matrix[i][k] != 0 && matrix[k][j] != 0)
                        {
                            matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                        }
                    }
                    else if(matrix[i][k] != 0 && matrix[k][j] != 0)
                    {
                        matrix[i][j] = matrix[i][k]+ matrix[k][j];
                    }
                }
            }
            
        }
    }
}
void checkRoute(int matrix[S][S],int i, int j)
{
    if(matrix[i][j] != 0)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
void theRoute(int matrix[S][S],int i, int j)
{
    if(matrix[i][j] != 0)
    {
        printf("%d\n",matrix[i][j]);
    }
    else
    {
        printf("-1\n");
    }
}
