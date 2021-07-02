#include <stdio.h>
#define int_int32_t

int min(int a,int b)
{
    if (a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int main()
{
    int salary,marry,family,memInc,sav_inv,tuition,preChild,disable;
    
    printf("Gross salary:");
    if (scanf("%d", &salary)!=1 || salary<0)
    {
        printf("error\n");
        return 1;
    }
    printf("Married? (0/1):");
    if(scanf(" %d", &marry)!=1 || marry!=(1||0))
    {
        printf("error\n");
        return 1;
    }
    printf("How many people are there in your family:");
    if(scanf(" %d", &family)!=1 || family<0)
    {
        printf("error\n");
        return 1;
    }
    printf("How many people in your family have income:");
    if(scanf(" %d", &memInc)!=1 || memInc>family || memInc<0)
    {
        printf("error\n");
        return 1;
    }
    printf("Special Deduction for Savings and Investment:");
    if(scanf(" %d", &sav_inv)!=1 || sav_inv<0)
    {
        printf("error\n");
        return 1;
    }
    printf("Special Deduction for Tuition:");
    if(scanf(" %d", &tuition)!=1 || tuition<0)
    {
        printf("error\n");
        return 1;
    }
    printf("How many preschool children:");
    if(scanf(" %d", &preChild)!=1 || preChild>family || preChild<0)
    {
        printf("error\n");
        return 1;
    }
    printf("How many disable people:");
    if(scanf(" %d", &disable)!=1 || disable>family || disable<0)
    {
        printf("error\n");
        return 1;
    }
    if (salary/family<=175000)
    {
        printf("exempted from filing taxes\n");
        return 0;
    }
    salary-=88000*family;
    salary-=200000*memInc;
    salary-=min(sav_inv,270000);
    salary-=tuition*25000;
    salary-=preChild*120000 ;
    salary-=disable*200000;
    if (marry==1)
    {
        salary-=240000;
    }

    if (salary<=540000)
    {
        printf("Total tax:%.0f\n", salary*0.05);
    }
    else if (salary<=1210000)
    {
        printf("Total tax:%.0f\n", salary*0.12-37800);
    }
    else if (salary<=2420000)
    {
        printf("Total tax:%.0f\n", salary*0.2-134600);
    }
    else if (salary<=4530000)
    {
        printf("Total tax:%.0f\n", salary*0.3-376600);
    }
    else
    {
        printf("Total tax:%.0f\n", salary*0.3-829600);
    }

    return 0;
}