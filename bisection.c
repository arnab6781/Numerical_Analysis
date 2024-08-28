#include <stdio.h>
#include <math.h>

#define f(x) pow(x, 3) - 9 * x + 1

int main()
{
    float arr[100][4];

    float an, bn;
    printf("Enter lower limit and upper limit of interval: ");
    scanf("%f %f", &an, &bn);

    if (f(an) < 0)
    {
        arr[0][0] = an;
        arr[0][1] = bn;
    }
    else
    {
        arr[0][1] = an;
        arr[0][0] = bn;
    }
    arr[0][2] = (arr[0][0] + arr[0][1]) / 2;

    arr[0][3] = f(arr[0][2]);

    int i = 1;
    while (1)
    {

        if (arr[i - 1][3] < 0)
        {
            arr[i][0] = arr[i - 1][2];
            arr[i][1] = arr[i - 1][1];
        }
        else
        {
            arr[i][0] = arr[i - 1][0];
            arr[i][1] = arr[i - 1][2];
        }

        arr[i][2] = (arr[i][0] + arr[i][1]) / 2;

        arr[i][3] = f(arr[i][2]);

        if (fabs(arr[i][2] - arr[i - 1][2]) < 0.005)
        {
            break;
        }

        i++;
    }

    for (int r = 0; r < i + 1; r++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f ", arr[r][j]);
        }

        printf("\n");
    }
}