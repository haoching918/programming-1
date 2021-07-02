#include "hw5.h"
#include "test2.h"

intt main()
{
    printf("The matrix is\n");
    for (intt i = 0; i < 4; i++)
    {
        for (intt j = 0; j < 4; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }

    intt det = 0;
    det = arr_det(matrix);
    printf("The determinant is %d.\n", det);

    return 0;
}