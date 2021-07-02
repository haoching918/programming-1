#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t a;
    printf("Please enter an integer:");
    scanf("%d",&a);
    char s[32];
    sprintf(s,"%08x\n",a);
    printf("%d:  %s\n",a,s);
}