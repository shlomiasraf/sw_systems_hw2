#include <stdio.h>
#include "my_mat.h"
int main()
{
    int matrix[S][S];
    char ch;
    scanf("%c", &ch);
    while (ch != 'D')
    {
        if(ch == 'A')
        {
            initMatrix(matrix);
            neighborMatrix(matrix);
        }
        if (ch == 'B' || ch == 'C')
        {
            int i,j;
            scanf("%d %d", &i, &j);
            if(ch == 'B')
            {
                checkRoute(matrix,i,j);
            }   
            if(ch == 'C')
            {
                theRoute(matrix,i,j);
            }
            
        }
        scanf("%c", &ch);
    }
    return 0;
}