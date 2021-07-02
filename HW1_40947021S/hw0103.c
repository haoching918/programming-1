#include <stdio.h>
#include <stdint.h>

int main()
{
     float g;
     float t;
    printf("Please enter the acceleration due to gravity:");
    scanf("%f",&g);
    printf("Please enter the time (s):");
    scanf("%f",&t);
    printf("Final velocity: %f m/s\n",g*t);
    printf("The altitude: %f m\n",g*t*t/2);
}