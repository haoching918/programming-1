#include "hw5.h"
#include "test.h"

int main()
{
    //int32_t array[10] = { 0,1,2,3,4,5,6,7,8,9 };  int32_t array_size = 10;

    printf("Before:\n");
    printArray(array, array_size);

    printf("After:\n");

    intt odd_num = 0;
    intt even_num = 0;
    for (intt i = 0; i < array_size; i++)
    {
        if (array[i] % 2 == 0)
        {
            even_num++;
        }
        else
        {
            odd_num++;
        }
         
    }
    
    intt even_arr[even_num];
    intt odd_arr[odd_num];
    intt even_count = 0;
    intt odd_count = 0;

    for (intt i = 0; i < array_size; i++)
    {
        if (array[i] % 2 == 0)
        {
            even_arr[even_count] = array[i];
            even_count++;
        }
        else
        {
            odd_arr[odd_count] = array[i];
            odd_count++;
        }
        
    }

    sort_increase(odd_arr, sizeof(odd_arr) / 4);
    sort_decrease(even_arr, sizeof(even_arr) / 4);


    intt result[array_size];
    for (intt i = 0; i < sizeof(odd_arr) / 4; i++)
    {
        result[i] = odd_arr[i];
    }
    
    for (intt i = sizeof(odd_arr) / 4; i < array_size; i++)
    {
        result[i] = even_arr[i - sizeof(odd_arr) / 4];
    }
    
    printArray(result, array_size);
    
    return 0;
}