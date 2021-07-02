#include <stdio.h>
#define int_int32_t
#include <stdlib.h>
int main()
{
	int startYear,startMonth,startDay,endYear,endMonth,endDay;

	printf("Date Format: YYYY/MM/DD\n");
	printf("Start Date:");
	if (scanf("%d/%d/%d",&startYear,&startMonth,&startDay)!=3)
	{
		printf("error\n");
		return 1;
	}
	printf("End Date:");
	if (scanf(" %d/%d/%d",&endYear,&endMonth,&endDay)!=3)
	{
		printf("error\n");
		return 1;
	}
	
	//初步排除錯誤
	if ((startYear<1 || endYear<1) || (startYear>9999 || endYear>9999))
	{
		printf("error\n");
		return 1;
	}
	else if ((startMonth<1 || endMonth<1) || (startMonth>12 || endMonth>12))
	{
		printf("error\n");
		return 1;
	}
	else if ((startDay<1 || endDay<1) || (startDay>31 || endDay>31))
	{
		printf("error\n");
		return 1;
	}

	//判斷閏年
	int leapYear1;
	int leapYear2;
	if ((startYear%4==0 && startYear%100!=0) || startYear%400==0)
	{
		leapYear1=1;
	}	
	else
	{
		leapYear1=0;
	}
	
	if ((endYear%4==0 && endYear%100!=0) || endYear%400==0)
	{
		leapYear2=1;
	}
	else
	{
		leapYear2=0;
	}

	//30,31
	if (startMonth==4 || startMonth==6 || startMonth==9 || startMonth==11)
	{
		if (startDay>30)
		{
			printf("error\n");
			return 1;
		}
	}
	if (endMonth==4 || endMonth==6 || endMonth==9 || endMonth==11)
	{
		if (endDay>30)
		{
			printf("error\n");
			return 1;
		}
	}
	
	//2/28
	if (leapYear1==0 || leapYear2==0)
	{
		if (startMonth==2 || endMonth==2)
		{
			if (startDay>28 || endDay>28)
			{
				printf("error\n");
				return 1;
			}
		}
	}
	else if(leapYear1==1 || leapYear2==1)
	{
		if (startMonth==2 || endMonth==2)
		{
			if (startDay>29 || endDay>29)
			{
				printf("error\n");
				return 1;
			}
		}
	}

	//start計算
	int duration1=0;
	int leapcount1=0;

	for (int i = 1; i < startYear; i++)
	{
		if ((i%4==0 && i%100!=0) || i%400==0)
		{
			leapcount1++;
		}
	}
	duration1=duration1+365*(startYear-1)+leapcount1;
	if (leapYear1==1)
	{
		for (int i = 1; i < startMonth; i++)
		{
			if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10)
			{
				duration1+=31;
			}
			else if (i==4 || i==6 || i==9 || i==11)
			{
				duration1+=30;
			}
			else if (i==2)
			{
				duration1+=29;
			}
		}
	}
	else
	{
		for (int i = 1; i <startMonth; i++)
		{
			if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10)
			{
				duration1+=31;
			}
			else if (i==4 || i==6 || i==9 || i==11)
			{
				duration1+=30;
			}
			else if (i==2)
			{
				duration1+=28;
			}
		}
	}
	duration1+=startDay;
	
	//end計算
	int duration2=0;
	int leapcount2=0;
	for (int i = 1; i < endYear; i++)
	{
		if ((i%4==0 && i%100!=0) || i%400==0)
		{
			leapcount2++;
		}
	}
	duration2+=365*(endYear-1)+leapcount2;
	if (leapYear2==1)
	{
		for (int i = 1; i <endMonth; i++)
		{
			if (i==1 || i==3 || i==5 || i==7 ||i==8 || i==10)
			{
				duration2+=31;
			}
			else if (i==4 ||i==6 || i==9 || i==11)
			{
				duration2+=30;
			}
			else if (i==2)
			{
				duration2+=29;
			}
		}
	}
	else
	{
		for (int i = 1; i <endMonth; i++)
		{
			if (i==1 || i==3 || i==5 || i==7 ||i==8 || i==10)
			{
				duration2+=31;
			}
			else if (i==4 ||i==6 || i==9 || i==11)
			{
				duration2+=30;
			}
			else if (i==2)
			{
				duration2+=28;
			}
		}
	}
	duration2+=endDay;

	int diffrence=0;
	diffrence=abs(duration1-duration2);
	printf("Duration: %d Day(s)\n",diffrence);
	
	


	
	
	


	
	
	
	


}