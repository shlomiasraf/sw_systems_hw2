#include <stdio.h>
#include "my_mat.h"
int main()
{
    int matrix[S][S];
    char ch;
    scanf( "%c", &ch);
    while (ch != 'D')
    {
        if(ch == 'A')
        {
            printf("enter the matrix values: \n");
            for (int i = 0; i < S; i++)
            {        
                for (int j = 0; j < S; j++)
                {
                    int num1;
                    scanf( "%d", &num1);
                    matrix[i][j] = num1;
                }
            }
            printf("finish \n");
            neighborMatrix(matrix);
        }
        if (ch == 'B' || ch == 'C')
        {
            printf("enter i,j values: \n");
            int i,j;
            scanf( "%d %d", &i, &j);
            if(ch == 'B')
            {
                checkRoute(matrix,i,j);
            }   
            if(ch == 'C')
            {
                theRoute(matrix,i,j);
            }
            
        }
        scanf( "%c", &ch);
    }
    return 0;
}