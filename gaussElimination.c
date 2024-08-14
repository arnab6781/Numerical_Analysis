#include <stdio.h>
int n;

int main()
{
    printf("Enter no of equations: ");
    scanf("%d", &n);

    float arr[n][n + 1];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the elements of %d row of augmented matrix: ", (i + 1));
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    for (int r = 0; r < n; r++)
    {
        float pivot = arr[r][r];
        for (int i = r + 1; i < n; i++)
        {
            float temp = arr[i][r];
            for (int j = 0; j < n + 1; j++)
            {
                arr[i][j] = (-(pivot / temp) * arr[i][j]) + arr[r][j];
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    float x[n];

    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        float value = arr[i][n];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                value = value - arr[i][j] * x[j];
            }
        }

        x[i] = value / arr[i][i];
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("x%d = %f\n", i, x[i]);
    }

    return 0;
}