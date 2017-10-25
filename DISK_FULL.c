/*

	Disk Scheduling Algorithms
	Created by : Sarath Peter
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
  system("clear");
	int ch,m,n,x,start,i,j,POS,choice,min,a[15],count;
	count=0;
	printf("Enter number of cylinders :");
	scanf("%d",&m);
	printf("Number of Request");
	scanf("%d",&n);
	printf("Current POSition :");
	scanf("%d",&start);
	printf("Request :");
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		if(a[i]>=m)
			{
			printf("Invalid input !!");
			scanf("%d",&a[i]);
			}
		}
	do
	{
	printf("MENU\n 1.FCFS\n 2.SCAN\n 3.C-SCAN\n");
	printf("Enter your choice :");
	scanf("%d",&choice);
	count=0;
	x=start;
	switch(ch)
		{
		case 1:printf("FCFS");
			printf("Order is :");
			for(i=0;i<n;i++)
				{
				x-=a[i];
				if(x<0)
					x=-x;
				count=count+x;
				x=a[i];
				printf("%d",x);
				printf("Total head movement :%d ",count);
				}
				break;
		case 2:printf("SCAN");
			printf("Order is :");
			count=POS=0;
			for(i=0;i<n;i++)
				for(j=0;j<n-i-1;j++)
					{
					if(a[j]>a[j+1])
						{
						x=a[j];
						a[j]=a[j+1];
						a[j+1]=x;
			
						}
					}
			for(i=0;i<n;i++)
				if(a[i]<start)
				POS=POS+1;
			for(i=0;i<POS;i++)
				for(j=0;j<POS-i-1;j++)
					{
					if(a[j]<a[j+1])
						{
						x=a[j];
						a[j]=a[j+1];
						a[j+1]=x;
						}
					}
			x=start;
			printf("%d",x);
			for(i=0;i<POS;i++)
				{
				count+=abs(a[i],x);
				x=a[i];
				printf("%d",x);
				
				}
			count+=abs(x,0);
			x=0;
			printf("%d",x);
			for(i=0;i<POS;i++)
				{
				count+=abs(a[i],x);
				x=a[i];
				printf("%d",x);
				}
				
			printf("Total head movement :%d ",count);
			break;
		case 3:printf("C-SCAN");
			printf("Order is:");
			count=0;
			POS=0;
			for(i=0;i<n;i++)
				for(j=0;j<n-i-1;j++)
					{
					if(a[j]>a[j+1])
						{
						x=a[j];
						a[j]=a[j+1];
						a[j+1]=x;
						}
					}
			for(i=0;i<n;i++)
				if(a[i]<start)
					POS=POS+1;
			x=start;
			for(i=0;i<n;i++)
				{
				count+=abs(x,a[i]);
				x=a[i];
				printf("%d",x);
			
				}
			count+=abs(m-1,x);
			x=0;
			printf("%d %d",m-1,0);
			for(i=0;i<POS;i++)
				{
				count+=abs(x,a[i]);
				x=a[i];
				printf("%d",x);
				
				}
			printf("Total head movement :",count);
			break;
		printf("Do you want to continue ! (1 To continue)");
		scanf("%d",&ch);
		
		}

	}
	while(ch=1);	
	return 0;
}
