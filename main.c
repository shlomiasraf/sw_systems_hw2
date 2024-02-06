#include <stdio.h>
#include "my_mat.h"
int main()
{
    int matrix[S][S];
    char ch;
    scanf(" %c", &ch);
    while (ch != 'D')
    {
        if(ch == 'A')
        {
            for (int i = 0; i < S; i++)
            {        
                for (int j = 0; j < S; j++)
                {
                    int num1;
                    scanf( "%d", &num1);
                    matrix[i][j] = num1;
                }
            }
            neighborMatrix(matrix);
        }
        if (ch == 'B' || ch == 'C')
        {
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
        scanf(" %c", &ch);
    }
    return 0;
}
