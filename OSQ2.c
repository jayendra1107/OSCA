// Ten students (s1,s2,s3,s4,s5,s6,s7,s8,s9,s10) are going to attend an event. There are lots of
// gift shops, they all are going to the gift shops and randomly picking the gifts. After picking
// the gifts they are randomly arriving in the billing counter. The accountant gives the
// preference to that student who has maximum number of gifts. Create a C program to define
// order of billed students?

#include<stdio.h>
#include<conio.h>
int main()
{
	int i, j, swap;
	int student[10],gifts[10],arrival[10];
	for(i=0;i<10;i++)
	{
		printf("\nStiudent %d :- ",i+1);
        student[i]=i;
		printf("\nNumber of Gifts : ");
		scanf("%d",&gifts[i]);
		printf("Arrival Time : ");
		scanf("%d",&arrival[i]);
	}
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(arrival[i]>=arrival[j])
			{
				if(arrival[i]==arrival[j])
				{
					if(gifts[i]<gifts[j])
					{
						swap = arrival[i];
						arrival[i] = arrival[j];
						arrival[j] = swap;
						swap = gifts[i];
						gifts[i] = gifts[j];
						gifts[j] = swap;
						swap = student[i];
						student[i] = student[j];
						student[j] = swap;
					}
				}
			
			}
		}
	}
	printf("\nStudent\tGifts\tArrvial Time");
	for(i=0;i<10;i++)
	{
		printf("\n%d\t\t%d\t\t%d",student[i],gifts[i],arrival[i]);
	}
	printf("\nBilling Order :-");
	for(i=0;i<10;i++)
	{
		printf("\n%d",student[i]);
	}
	return 0;
}