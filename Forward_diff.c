#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter No of Rows: ");
    scanf("%d", &r);

    c = r + 1;

    float arr[r][c];

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
            printf("%0.2f ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}