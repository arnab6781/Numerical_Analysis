#include <stdio.h>

int r, c;

void getArr(float arr[r][c])
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
    }
}

void table(float arr[r][c], float x)
{
    for (int i = 0; i < r; i++)
    {
        arr[i][2] = x - arr[i][0];
    }

    for (int i = 0; i < r; i++)
    {
        int product = 1;
        for (int j = 0; j < r; j++)
        {
            if (j != i)
            {
                product = product * (arr[i][0] - arr[j][0]);
            }
        }

        arr[i][3] = product;
    }

    for (int i = 0; i < r; i++)
    {
        arr[i][4] = arr[i][2] * arr[i][3];
        arr[i][5] = arr[i][1] / arr[i][4];
    }
}

void printTable(float arr[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}

float interpolation(float arr[r][c], float x)
{
    float product1 = 1;
    for (int i = 0; i < r; i++)
    {
        product1 = product1 * arr[i][2];
    }

    float sum = 0;
    for (int i = 0; i < r; i++)
    {
        sum = sum + arr[i][5];
    }

    return product1 * sum;
}
int main()
{
    float x;
    printf("Enter no of arbitrary values of x: ");
    scanf("%d", &r);

    c = 6;

    float arr[r][c];

    getArr(arr);
    printf("Enter desired x: ");
    scanf("%f", &x);

    table(arr, x);
    printTable(arr);
    printf("\nf(%f) = %f\n", x, interpolation(arr, x));

    return 0;
}