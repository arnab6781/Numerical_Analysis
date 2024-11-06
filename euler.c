#include <stdio.h>
#include <math.h>

#define f(x, y) (pow(x, 3)+y)        

int main()
{
    float initial_x, initial_y;

    printf("Enter x0 and y0: ");
    scanf("%f %f", &initial_x, &initial_y);

    float h;
    printf("Enter h: ");
    scanf("%f", &h);

    float required_x, required_y;
    printf("Enter required x: ");
    scanf("%f", &required_x);

    while (initial_x != required_x)
    {
        required_y = initial_y + h * f(initial_x, initial_y);

        initial_x = initial_x + h;
        initial_y = required_y;
    }


    printf("%f\n", required_y);

    return 0;
}
