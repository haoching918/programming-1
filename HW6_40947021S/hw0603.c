#include "hw6.h"

intt main()
{
    double x, y, theta;
    printf("Please enter a point: ");
    if (scanf("%lf %lf", &x, &y) != 2)
    {
        printf("error\n");
        return 1;
    }
    printf("Please enter theta (0-360): ");
    if (scanf("%lf", &theta) != 1 || (theta < 0 || theta > 360))
    {
        printf("error\n");
        return 1;
    }
    rotate(&x, &y, theta);
    printf("%lf %lf\n", x, y);

    return 0;
}