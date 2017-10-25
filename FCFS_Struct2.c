#include<stdio.h>
#include<unistd.h>
#define clear() printf("\033[H\033[J")

struct process
{
	int pid,ar,wait,serve,burst,turn;
};

void FCFS_Calc(struct process p[],int total_proc)
{
	int i,total_burst;
	printf("Scheduling : [");
	p[0].serve=0;
// Waiting time	
	for(i=0;i<total_proc;i++)
	{
	 printf("##");
	 sleep(1.5);
	 p[i].pid=i;
	 if(p[i].wait==0)
         {
          p[i].wait=0;
         }

	 p[i+1].serve=p[i].serve+p[i].burst;
	 p[i].wait=p[i].serve-p[i].ar;

// Turnaround time
	 p[i].turn=p[i].burst+p[i].wait;

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
	clear();
	for(k=0;k<process_limit;k++)
	{
	 printf("\n Enter execution time of P%d : ",k);
         scanf("%d",&proc[k].burst);
	 printf("\n Enter Arrival time of P%d: ",k);
	 scanf("%d",&proc[k].ar);
	 printf("\n Enter service time of P%d : ",k);
	 scanf("%d",&proc[k].serve);
	 clear();
	}

	clear();
	//process_sort(&proc,process_limit);
	sleep(1.5);
	FCFS_Calc(&proc,process_limit);
	avg_wait=avg_wait_calc(&proc,process_limit);
	avg_turn=avg_turn_calc(&proc,process_limit);

	printf("\n =======================================================================\n");
	printf("| Process ID | Arrival Time | Wait time  | Burst Time | Turnaround Time |");
	printf("\n =======================================================================");

	for(k=0;k<process_limit;k++)
	{
	 printf("\n| P%d         |     %02d       |     %02d     |      %02d     |       %02d       |",proc[k].pid,proc[k].ar,proc[k].wait,proc[k].burst,proc[k].turn);
	}
	printf("\n =======================================================================\n");

	printf("\n Average Wait time : %.2f",avg_wait);
	printf("\n Average Turnaround time : %.2f\n",avg_turn);
}
