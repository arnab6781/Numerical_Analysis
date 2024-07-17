/*
    Newton's Forward Interpolation and Backward Interpolation

*/


#include <stdio.h>

int r, c;
float h;

void get_arr(float arr[r][c])
{
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < r; i++)
        {
            if (j == 0)
            {
                printf("Enter x%d: ", i);
                scanf("%f", &arr[i][j]);
            }

            else
            {
                printf("Enter y%d: ", i);
                scanf("%f", &arr[i][j]);
            }
        }
        printf("\n");
    }
}
void forwardDifferenceTable(float arr[r][c])
{

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

void backwardDifferenceTable(float arr[r][c])
{

    for (int j = 1; j < c - 1; j++)
    {
        for (int i = j; i < r; i++)
        {
            arr[i][j + 1] = arr[i][j] - arr[i - 1][j];
        }
    }

    printf("\n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= (i + 1); j++)
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

float calc_v(int n, float xn, float x)
{
    float v = (x - xn) / h;
    float v_product = 1;
    for (int i = 0; i < n; i++)
    {
        v_product = v_product * (v + i);
    }

    return v_product;
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

float backwardInterpolation(float arr[r][c], float x)
{
    float sum = arr[r - 1][1];
    for (int i = 1; i < c - 1; i++)
    {
        sum = sum + (calc_v(i, arr[r - 1][0], x) * arr[r - 1][i + 1]) / fact(i);
    }

    return sum;
}

int main()
{
    int choice;
    float x;
    printf("Enter the no of arbitrary values of x: ");
    scanf("%d", &r);
    c = r + 1;
    float arr[r][c];

    get_arr(arr);

    h = arr[1][0] - arr[0][0];

    printf("Press 1 for Forward Interpolation and 2 for Backward Interpolation: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        forwardDifferenceTable(arr);

        do
        {
            printf("\nEnter x(Enter 999 to exit): ");
            scanf("%f", &x);
            if (x == 999)
            {
                printf("Exiting\n");
            }
            else
            {
                printf("\nf(%f) = %f\n", x, forwardInterpolation(arr, x));
            }

        } while (x != 999);
    }
    else
    {
        backwardDifferenceTable(arr);

        do
        {
            printf("\nEnter x(Enter 999 to exit): ");
            scanf("%f", &x);
            if (x == 999)
            {
                printf("Exiting\n");
            }
            else
            {
                printf("\nf(%f) = %f\n", x, backwardInterpolation(arr, x));
            }

        } while (x != 999);
    }

    return 0;
}