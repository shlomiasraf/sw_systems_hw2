#include <stdio.h>
#include "my_mat.h"
#define W 20
#define N 5
//return the bigger number.
int max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    return num2;
}
//return the maximum profit.
int knapSack(int weights[N], int values[N] ,int selected_bool[N])
{

    int matrix[N+1][W+1]= {0};
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < W+1; j++)
        {
            if(j < weights[i-1])
            {
                matrix[i][j] = matrix[i-1][j];
            }
            else
            {
                matrix[i][j] = max(matrix[i-1][j], values[i-1] + matrix[i-1][j-weights[i-1]]);
            }
        }
    }
    int j = W;
    int i = N-1;
    int maxProfit = 0;
    while(i >= 0 && j > 0)
    {
        if(matrix[i][j] < values[i] + matrix[i][j-weights[i]])
        {
            selected_bool[i] = 1;
            j = j-weights[i];
            maxProfit += values[i];
        }
        i--;
    }
    return maxProfit;
}
//gets input from the user and prints the max profit and the selected items.
int main()
{
    int selected_bool[N] = {0};
    char items[N];
    int values[N];
    int weights[N];
    for(int i=0;i <N; i++)
    {
            char item; 
            int weight, value;
            scanf(" %c", &item);
            scanf("%d", &value);
            scanf("%d", &weight);
            items[i] = item;
            values[i] = value;
            weights[i] = weight;
    }    
    printf("Maximum profit: ");
    printf("%d",knapSack(weights,values,selected_bool));
    printf("\nSelected items:");
    for(int i = 0; i < N; i++)
    {
        if(selected_bool[i] == 1)
        {
            printf(" %c",items[i]);
        }
    }
    return 0;
}