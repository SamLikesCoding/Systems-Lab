#include<stdio.h>
#include<unistd.h>
#define clear() printf("\033[H\033[J")

struct process
{
	int pid,wait,burst,turn;
};

void FCFS_Calc(struct process p[],int total_proc)
{
	int i,j;
	printf("Scheduling : [");
	for(i=0;i<total_proc;i++)
	{
		sleep(1.5);
		printf("##");
		p[i].pid=i;
		if(i==0)
		{
			p[0].wait=0;
		}
		p[i].wait=0;
		for(j=0;j<i;j++)
		{
			p[i].wait+=p[j].burst;
		}
	}	
	
	for(i=0;i<total_proc;i++)
	{
		p[i].turn=p[i].wait+p[i].burst;
	}


	printf("] \nScheduling Done!!\n");
}

float avg_wait_calc(struct process p1[],int proc_lim1)
{
	int rep;
	float a_wait;

	for(rep=0;rep<proc_lim1;rep++)
	{
		a_wait+=p1[rep].wait;
	}

	return  a_wait/proc_lim1;
}

float avg_turn_calc(struct process p2[],int proc_lim2)
{ 
        int rep;
        float a_turn;

        for(rep=0;rep<proc_lim2;rep++)
        { 
                a_turn+=p2[rep].wait;
        }

        return  a_turn/proc_lim2;
}


void main()
{
	clear();

	struct process proc[30];
	int k,process_limit;
	float avg_wait,avg_turn;
	printf("\n Enter no of process : ");
	scanf("%d",&process_limit);
	for(k=0;k<process_limit;k++)
	{
	 printf("\nEnter execution time of P%d :",k);
	 scanf("%d",&proc[k].burst);
	}

	FCFS_Calc(&proc,process_limit);
	avg_wait=avg_wait_calc(&proc,process_limit);
	avg_turn=avg_turn_calc(&proc,process_limit);

	printf("\n =======================================================\n");
	printf("| Process ID | Wait time | Burst Time | Turnaround Time |");
	printf("\n =======================================================");

	for(k=0;k<process_limit;k++)
	{
	 printf("\n| P%d          |   %02d     |      %02d     |       %02d       |",proc[k].pid,proc[k].wait,proc[k].burst,proc[k].turn);
	}
	printf("\n =======================================================\n");

	printf("\n Average Wait time : %.2f",avg_wait);
	printf("\n Average Turnaround time : %.2f\n",avg_turn);
}
