#include <stdio.h>
#define int_int32_t

int main()
{
    double a=0,b=0,c=0, s, t;
    printf("Please enter a quadratic polynomial (ax^2+bx+c):");
    if(scanf("%lf,%lf,%lf", &a,&b,&c)!=3)
    {
        printf("error\n");
        return 1;
    }
    
    
    printf("The polynomial is ");
    if (a!=0)
    {
        if (a==1)
        {
            printf("x^2");
        }
        else
        {
            printf("%lfx^2", a);
        }
        
    }
    if (b!=0)
    {
        if (a==0)
        {
            if (b==1)
            {
                printf("x");
            }
            else
            {
                printf("%lfx", b);
            }
        }
        else
        {
            if (b==1)
            {
                printf("+x");
            }
            else if (b>0)
            {
                printf("+%lfx", b);
            }
            else
            {
                printf("%lfx", b);
            }
        }
        
    }
    if (c!=0)
    {
        if (a==0 && b==0)
        {  
            printf("%lf\n", c);
        }
        else
        {
            if (c>0)
            {
                printf("+%lf\n", c);
            }
            else
            {
                printf("%lf\n", c);
            }
            
        }
        
    }
    printf("Please enter the interval [s,t]:");
    if(scanf("%lf,%lf", &s, &t)!=2 || s >= t)
    {
        printf("error\n");
        return 1;
    }
    double integral = ((1.0/3.0)*a*t*t*t+(1/2)*b*t*t+c*t)-((1.0/3.0)*a*s*s*s+(1/2)*b*s*s+c*s);
    printf("The integral: %lf\n", integral);
    
    
    for (int n=2; n<65537; n=n*2)
    {
        double RiemannSum=0;
        double width=(t-s)/n;
        for (int i = 0; i < n; i++)
        {
            double xValue=s+width*i;
            RiemannSum+=(a*xValue*xValue+b*xValue+c)*width;
        }
        printf("The Riemann sum of n=%d: %lf\n", n, RiemannSum);
    }
    return 0;
}