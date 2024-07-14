#include <stdio.h>

int r, c;
float h;

void calcForwardDifference(float arr[r][c])
{
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < r; i++)
        {
            if (j == 0)
            {
                printf("Enter x: ");
                scanf("%f", &arr[i][j]);
            }

            else
            {
                printf("Enter y: ");
                scanf("%f", &arr[i][j]);
            }
        }
        printf("\n");
    }

    for (int j = 1; j < c - 1; j++)
    {
        for (int i = 0; i < r - j; i++)
        {
            arr[i][j + 1] = arr[i + 1][j] - arr[i][j];
        }
    }

    printf("\n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c - i; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}

float calc_u(int n, float x0, float x)
{
    float u = (x - x0) / h;
    float u_product = 1;
    for (int i = 0; i < n; i++)
    {
        u_product = u_product * (u - i);
    }

    return u_product;
}

int fact(int n)
{
    int fact = 1;
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = n; i > 1; i--)
        {
            fact = fact * i;
        }

        return fact;
    }
}

float forwardInterpolation(float arr[r][c], float x)
{
    float sum = arr[0][1];
    for (int i = 1; i < c - 1; i++)
    {
        sum = sum + (calc_u(i, arr[0][0], x) * arr[0][i + 1]) / fact(i);
    }

    return sum;
}

int main()
{
    float x;
    printf("Enter the no of arbitrary values of x: ");
    scanf("%d", &r);
    c = r + 1;
    float arr[r][c];

    calcForwardDifference(arr);

    h = arr[1][0] - arr[0][0];

    printf("Enter x: ");
    scanf("%f", &x);

    printf("%f\n", forwardInterpolation(arr, x));

    return 0;
}