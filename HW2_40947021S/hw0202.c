#include<stdio.h>
#define int_int32_t

int main()
{
	float x1,x2,x3,x4,y1,y2,y3,y4,m1,m2;
	
	printf("Please enter the first line:");
	if (scanf("(%f,%f),(%f,%f)", &x1,&y1,&x2,&y2)!=4)
	{
		printf("error.\n");
		return 1;
	}
	printf("Please enter the second line:");
	if (scanf(" (%f,%f),(%f,%f)", &x3,&y3,&x4,&y4)!=4)
	{
		printf("error.\n");
		return 1;
	}

	printf("%f,%f\n", x1-x2,y1-y2);
	if (((x1-x2)==0 && (y1-y2)==0) || ((x3-x4)==0 && (y3-y4)==0))
	{
		printf("intersection does not exist\n");
		return 0;
	}
	
	//水平線之情況
	if ( (y1-y2)==0 || (y3-y4)==0 )
	{
		if ((y1-y2)==0 && (x3-x4)==0)
		{
			printf("Intersection: (%f,%f)\n", x3,y1);
			return 0;
		}
		else if (((y3-y4)==0) && ((x1-x2)==0))
		{
			printf("Intersection: (%f,%f)\n", x1,y3);
			return 0;
		}
		else
		{
			printf("intersection does not exist\n");
			return 0;
		}
	}
	printf("g\n");
	//兩點相同之情況
	printf("%f,%f\n", x1-x2,y1-y2);
	if (((x1-x2)==0 && (y1-y2)==0) || ((x3-x4)==0 && (y3-y4)==0))
	{
		printf("intersection does not exist\n");
		return 0;
	}
	printf("%d\n", 3);
	m1=(x1-x2)/(y1-y2);
	m2=(x3-x4)/(y3-y4);
	
	if (m1==m2)
	{
		printf("intersection does not exist\n");
		return 0;
	}
	else
	{
		float X= ((x1 * y2 - y1 * x2) * (x3 - x4) - (x3 * y4 - y3 * x4) * (x1 - x2)) /
    (((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));
		float Y= ((x1 * y2 - y1 * x2) * (y3 - y4) - (x3 * y4 - y3 * x4) * (y1 - y2)) /
    (((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));
		printf("Intersection: (%.2f,%.2f)\n", X,Y);
		return 0;
	}
}