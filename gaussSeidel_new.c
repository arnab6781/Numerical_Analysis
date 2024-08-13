#include <stdio.h>
#include <math.h>

int n;
int check_termination(float result[100][n], int r)
{
    int key = 0;
    for (int i = 0; i < n; i++)
    {
        if ((fabs(result[r][i] - result[r - 1][i])) <= 0.00005)
        {
            key++;
        }
    }

    if (key == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("Enter no of equations: ");
    scanf("%d", &n);

    float arr[n][n + 1];
    float arr2[n][n + 1];

    for (int r = 0; r < n; r++)
    {
        printf("Enter coefficients of %d equation: ", r + 1);
        for (int c = 0; c < n + 1; c++)
        {
            scanf("%f", &arr[r][c]);
        }
        // Rearranging
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum = sum + fabs(arr[r][j]);
                }
            }
            // placing in the appropiate row of new array 
            if (fabs(arr[r][i]) >= sum)
            {
                for (int k = 0; k < n + 1; k++)
                {
                    arr2[i][k] = arr[r][k];
                }
            }
        }
    }
    printf("\nOriginal array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nRearranged array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr2[i][j]);
        }
        printf("\n");
    }

    float result[100][n];

    for (int i = 0; i < n; i++)
    {
        result[0][i] = 0;
    }

    int r = 1;
    while (1)
    {

        for (int c = 0; c < n; c++)
        {
            float sub = arr[c][n];
            for (int i = 0; i < n; i++)
            {
                if (i != c)
                {
                    if (i > c)
                    {
                        sub = sub - arr2[c][i] * result[r - 1][i];  
                    }
                    else
                    {
                        sub = sub - arr2[c][i] * result[r][i];
                    }
                }
            }

            result[r][c] = 1 / arr2[c][c] * sub;
        }
        int a = check_termination(result, r);
        if (a == 1)
        {
            break;
        }

        r++;
    }

    printf("\nAns....\n");
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
