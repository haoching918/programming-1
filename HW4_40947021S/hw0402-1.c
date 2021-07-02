
#include"header.h"

intt main()
{
    intt disk_num;
    intt control;
    printf("Please enter the disk number (2-20):");
    if (scanf("%d", &disk_num) != 1 || disk_num < 2 || disk_num > 20)
    {
        printf("error\n");
        return 1;
    }
    
    control = even_or_odd(disk_num);
    hanoi(disk_num, control);
}