#include "hw5.h"

intt main()
{
    printf("Please enter the point number: ");
    intt pnum = 0;
    if (scanf("%d", &pnum) != 1 || pnum < 1)
    {
        printf("error\n");
        return 1;
    }
 
    double px[pnum];
    intt px_size = sizeof(px)/8;
    double py[pnum]; 
    intt py_size = sizeof(py)/8;
    for (intt i = 0; i < pnum; i++)
    {
        printf("Please enter Point %d: ", i + 1);
        if (scanf(" %lf %lf", &px[i], &py[i]) != 2 )
        {
            printf("error\n");
            return 1;
        }        
    }
    double xAverage = getAverage(px, px_size);
    double yAverage = getAverage(py, py_size);

    double Sxy = 0.0;
    double Sxx = 0.0;
    for (intt i = 1; i <= pnum; i++)
    {
        Sxy += (px[i-1] - xAverage) * (py[i-1] - yAverage);
        Sxx += (px[i-1] - xAverage) * (px[i-1] - xAverage);
    }
    double m = Sxy / Sxx;
    printf("Regression Equation: y = %lf x + %lf\n", m, -(m * xAverage) + yAverage);
 
    return 0;
}