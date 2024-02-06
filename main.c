#include <stdio.h>
#include "my_mat.h"
int main()
{
    int matrix[S][S];
    char ch;
<<<<<<< HEAD
    scanf( " %c", &ch);
=======
    scanf(" %c", &ch);
>>>>>>> 4f759973e101e1f40cc49e5f651c1f33b0687df7
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
<<<<<<< HEAD
        scanf( " %c", &ch);
=======
        scanf(" %c", &ch);
>>>>>>> 4f759973e101e1f40cc49e5f651c1f33b0687df7
    }
    return 0;
}
