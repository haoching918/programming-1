#include <stdio.h>
#define int_in32_t
#include <math.h>

int main()
{
    printf("SIP Plan\n");
    printf("Annually payment:");

    int annuallyPay=0;
    if (scanf("%d", &annuallyPay)!=1 || annuallyPay<0)
    {
        printf("error\n");
        return 1;
    }
    double insuranceFee[5];
    printf("Insurance fee in the first five years (0 is assumed afterwards): ");
    if(scanf("%lf,%lf,%lf,%lf,%lf", &insuranceFee[0], &insuranceFee[1], &insuranceFee[2], &insuranceFee[3], &insuranceFee[4])!=5 || 
    insuranceFee[0]>100 || insuranceFee[0]<0 || insuranceFee[1]>100 || 
    insuranceFee[1]<0 || insuranceFee[2]>100 || insuranceFee[2]<0 || 
    insuranceFee[3]>100 || insuranceFee[3]<0 || insuranceFee[4]>100 || 
    insuranceFee[4]<0)
    {
        printf("error\n");
        return 1;
    }

    double insuranceFeeOff=0;
    printf("Insurance fee off: ");
    if (scanf("%lf", &insuranceFeeOff)!=1 || insuranceFeeOff<0 || insuranceFeeOff>100)
    {
        printf("error\n");
        return 1;
    }

    int monProcessFee=0;
    printf("Monthly insurance processing fee:");
    if (scanf("%d", &monProcessFee)!=1 || monProcessFee<0)
    {
        printf("error\n");
        return 1;
    }

    int age=0;
    printf("Age:");
    if (scanf("%d", &age)!=1 || age<1)
    {
        printf("error\n");
        return 1;
    }

    int yearPay=0;
    printf("How many years of payment:");
    if (scanf("%d", &yearPay)!=1 || yearPay<5)
    {
        printf("error\n");
        return 1;
    }

    double investRate=0;
    printf("Expected annual return on investment rate:");
    if (scanf("%lf", &investRate)!=1 || investRate<0 || investRate>100)
    {
        printf("error\n");
        return 1;
    }
    
    printf("------------------------------\n");
    printf("Your Payment and Account Value Table\n");
    
    double monthlyInvestRate = 1.0 + investRate * 0.01 / 12.0;
    int x=0;
    double cashSurrenderValue=0; 
    int insuranceCost=0;
    int firstYear=age;
    double rate = 0;
    int insuranceValue = 0;
    int annuallyPayCount=0;
    for (age ; age <= 100; age++)
    {
        if (age <= firstYear+4)
        {
            rate=1-insuranceFee[x]/100+insuranceFeeOff/100;
        }
        else
        {
            rate = 1;
        }
        
        if (age>firstYear+(yearPay-1))
        {
            annuallyPay=0;
        }
        
        if (age<20)
        {
            insuranceCost=2000;
        }
        else
        {
            insuranceCost=100 * (age - 20) + 2000;
        }
        x++;

        insuranceValue = annuallyPay * rate -insuranceCost;
        cashSurrenderValue += insuranceValue;
        
        for (int i = 1; i <= 12; i++)
        {
            if (age==firstYear && i==1)
            {
                cashSurrenderValue = cashSurrenderValue;
            }
            else
            {
                cashSurrenderValue = ( cashSurrenderValue - 100 ) * monthlyInvestRate;
            }
        }
        annuallyPayCount += annuallyPay;
        printf("%d: %d,%lf\n", age, annuallyPayCount, cashSurrenderValue);
        
    }
    return 0;
}