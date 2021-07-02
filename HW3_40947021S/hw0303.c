#include <stdio.h>
#include <stdlib.h>
#define int_in32_t


int inputCheck(int num)
{
    if (scanf("%d", &num)!=1 )
    {
        printf("error\n");
        exit(0);
    }
    return num;
    
}

int start(int input)
{
    switch (input)
    {
    case 10:
    case 35:
        return 1;
        break;
    
    case 11:
        return 3;
        break;
    
    case 20:
    case 78:
        return 5;
        break;
    
   
    default:
        return 0;
        break;
    }
}

int S1(int input)
{
    switch (input)
    {
    case 19:
        return 2;
        break;
    
    case 12:
    case 36:
        return 6;
    
    default:
        return 1;
        break;
    }
}

int S2(int input)
    {
        switch (input)
        {
        case 43:
            return 2;
        
        case 99:
            return 7; 
        
        default:
            return 0;
            break;
        }
    }
int S3(int input)
{
    return 4;
}

int S4(int input)
{
    return 6;
}

int S5(int input)
{
    switch (input)
    {
    case 1:
        return 4;
    
    case 2:
        return 6;
        break;
    
    default:
        return 0;
        break;
    }
}

int S6(int input)
{
    switch (input)
    {
    case 108:
        return 7;
        break;

    default:
        return 5;
        break;
    }
}

int final()
{
    printf("Final\n");
}
int main()
{
    int state=0;
    int input=0;
    
    while (state!=7)
    {
        switch (state)
        {
        case 0:
            printf("Start\n");
            break;
        
        case 1:
            printf("S1\n");
            break;
        
        case 2:
            printf("S2\n");
            break;
        
        case 3:
            printf("S3\n");
            break;
        
        case 4:
            printf("S4\n");
            break;

        case 5:
            printf("S5\n");
            break;
        
        case 6:
            printf("S6\n");
            break;
        
        default:
            break;
        }

        printf("Please enter an integer:");
        input=inputCheck(input);

        switch (state)
        {
        case 0:
            state=start(input);
            break;
        
        case 1:
            state=S1(input);
            break;
        
        case 2:
            state=S2(input);
            break;
        
        case 3:
            state=S3(input);
            break;
        
        case 4:
            state=S4(input);
            break;
        
        case 5:
            state=S5(input);
            break;
       
        case 6:
            state=S6(input);
            break;
        
        default:
            break;
        }
    }
    final();
    return 0;
}
