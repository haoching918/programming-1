#include "hw6.h"

intt main()
{
    double x, y, z;
    intt a, b, c, d;

    printf("Please enter the plane: ");
    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4)
    {
        printf("error\n");
        return 1;
    }
    printf("The plane is ");
    getPlane(a, b, c, d);
    printf("Please enter the point: ");
    if (scanf("%lf %lf %lf", &x, &y, &z) != 3)
    {
        printf("error\n");
        return 1;
    }
    project(&x, &y, &z, a, b, c, d);
    return 0;
}