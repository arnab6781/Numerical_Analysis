#include <stdio.h>
#include <math.h>

#define f(x) log10(x)

int n;
float h;

float calc_value(float arr[n + 1][2], float h)
{
    float sum1 = arr[0][1] + arr[n][1];

    float even_sum = 0;
    float odd_sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even_sum = even_sum + arr[i][1];
        }
        else
        {
            odd_sum = odd_sum + arr[i][1];
        }
    }

    //printf("%f %f %f\n", sum1, even_sum, odd_sum);

    float result = h / 3 * (sum1 + 2 * even_sum + 4 * odd_sum);

    return result;
}

int main()
{
    float a, b;
    printf("Enter lower and upper limit: ");
    scanf("%f %f", &a, &b);

    printf("Enter no of intervals: ");
    scanf("%d", &n);

    h = (b - a) / n;

    //printf("%f\n", h);

    float arr[n + 1][2];

    float x = a;
    for (int i = 0; i < n + 1; i++)
    {
        arr[i][0] = x; // x

        arr[i][1] = f(arr[i][0]); // y

        x = x + h;
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%0.8f ", arr[i][j]);
        }

        printf("\n");
    }

    printf("Ans: %0.8f\n", calc_value(arr, h));

    return 0;
}