#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter no of equations: ");
    scanf("%d", &n);

    float arr[n][n + 1];

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficients of %d equation: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    printf("Enter constant values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][n]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    // rearranging
    for (int i = 0; i < n-1; i++)
    {
        float sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                sum = sum + abs(arr[i][j]);
            }
        }
        
        /* Swapping current rows with subsequents rows */
        int r = i + 1;
        while (abs(arr[i][i]) < sum)
        {
            for (int k = 0; k < n + 1; k++)
            {
                float temp = arr[i][k];        
                arr[i][k] = arr[r][k];
                arr[r][k] = temp;
            }
            r++;
        }
    }

    printf("Rearranged array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
