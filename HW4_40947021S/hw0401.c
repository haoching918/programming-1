
#include "header.h"


intt main()
{
    intt integer = 0;
    printf("Please enter an integer: ");
    if (scanf("%d", &integer) != 1 || integer > 3000 || integer < 1)
    {
        printf("error\n");
        return 1;
    }
    romanTransfer(integer);
    
    return 0;
}

