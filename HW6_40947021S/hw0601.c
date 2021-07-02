#include "hw6.h"

intt main()
{
	int64_t integer = 0;
	intt position = 0;
	intt change = 0;
	printf("Please input an integer: ");
	if (scanf("%ld", &integer) != 1  )
	{
		printf("error\n");
		return 1;
	}
	int64_t *ptr_integer = &integer;
	while (1)
	{    
		printf("The Integer: %ld\n", integer);
		byte_position(ptr_integer);
		printf("Please enter the position (1-8, 0: End): ");
		if (scanf("%d", &position) != 1 || (position < 0 || position > 8))
		{
			printf("error\n");
			return 1;
		}

		if (position == 0)
		{
			return 0;
		}

		printf("Please enter the new value (0-255): ");
		if (scanf("%d", &change) != 1 || (change > 255 || change < 0))
		{
			printf("error\n");
			return 1;
		}
		valueChage(ptr_integer, position, change);
	}	
	return 0;
}