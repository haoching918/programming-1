#include"header.h"

intt main()
{
    intt disk_num = 0;
    printf("Please enter the disk number (2-20):");
    if (scanf("%d", &disk_num) != 1 || disk_num < 2 || disk_num > 20)
    {
        printf("error\n");
        return 1;
    }
    intt control = even_or_odd(disk_num);
    disk_num = pow(2,disk_num) - 1;
    intt k = disk_num - 1;
    hanoi_recursion(disk_num, control, k);
    

    return 0;
}