
#include "header.h"



intt main()
{
    double k = 0;
    printf("k-th order Taylor polynomial for e\n");
    printf("Please enter k: ");
    if (scanf("%lf", &k) != 1 || k < 1)
    {
        printf("error\n");
        return 1;
    }

    double ans = get_ans(k);
    
    printf("%lf\n", ans);
    return 0;
}