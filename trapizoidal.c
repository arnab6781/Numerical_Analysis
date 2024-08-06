#include <stdio.h>
#include <math.h>

#define f(x) log10(x)

float h;
int n;

float trapizoidal(float arr[n + 1][2], float h)
{
    float sum1 = arr[0][1] + arr[n][1];

    float sum2 = 0;

    for (int i = 1; i < n; i++)
    {
        sum2 = sum2 + arr[i][1];
    }

    float result = (h / 2) * (sum1 + 2 * (sum2));

    return result;
}

int main()
{

    float a, b;
    printf("Enter lower and upper limit: ");
    scanf("%f %f", &a, &b);

    printf("Enter no of intervals: ");
    scanf("%d", &n);

    h = (b - a) /  n;

    float arr[n + 1][2];

    float x = a;
    for (int i = 0; i < n + 1; i++)
    {
        arr[i][0] = x; // x

        arr[i][1] = f(arr[i][0]); // y

        x = x + h;
    }

    printf("Ans: %0.8f\n", trapizoidal(arr, h));

    return 0;
}