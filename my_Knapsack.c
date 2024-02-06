#include <stdio.h>
#include "my_mat.h"
#define W 20
#define N 5
int max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    return num2;
}
void knapSack(int weights[N], int values[N] ,int selected_bool[N])
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
    while(i >= 0 && j > 0)
    {
        if(matrix[i][j] < values[i] + matrix[i][j-weights[i]])
        {
            selected_bool[i] = 1;
            j = j-weights[i];
        }
        i--;
    }
}
int main()
{
    int selected_bool[N] = {0};
    char items[] = {"ABCDE"};
    int weights[N];
    int values[N];
    for(int i=0;i <N*2; i++)
    {
        if(i < N)
        {
            int value;
            scanf("%d", &value);
            values[i] = value;
        }
        else
        {
            int weight;
            scanf("%d", &weight);
            weights[i-N] = weight;
        }
    }
    
    knapSack(weights,values,selected_bool);
    int maxProfit = 0;
    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        if(selected_bool[i] == 1)
        {
            maxProfit += values[i];
            counter++;
        }
    }
    printf("%d\n", maxProfit);
    int counter2 = 0;
    for(int i = 0; i < N; i++)
    {
        if(selected_bool[i] == 1)
        {
            if(counter2 == counter-1)
            {
                printf("%c\n", items[i]);
            }
            else
            {
                printf("%c,", items[i]);
                counter2++;
            }
        }
    }
    return 0;
}