#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>

#define SIZE 5
sem_t empty,full,sema;
int buffer[SIZE];
int count=0;

void * producer()
{
	while(1)
	{
		sleep(rand()%2);
		sem_wait(&empty);
		sem_wait(&sema);
		printf("Producer producing\n");
		buffer[count%5]=count;
		printf("Produced at %d\n",count%5);

		count++;
		
		sem_post(&full);
		sem_post(&sema);
		
		if(count>=5)
			{
			printf("Buffer is full\n");
			//sleep(rand()%2);
			}

		//else
		//	{
		//	printf("");
		//	}
	}
}

void * consumer()

{
	while(1)
	{	sleep(rand()%2);
		sem_wait(&full);
		sem_wait(&sema);
		count--;
		printf("Consumed from %d\n",count%5);
		
		sem_post(&empty);
		sem_post(&sema);
		//sleep(rand()%3);
		if(count==0)
		{
			printf("Buffer is empty\n");
		}
		//else
		//{
		        //sleep(2);
		//}
	}
}

void main()

{
//printf("hi");
int i=0;
sem_init(&empty,0,SIZE);
sem_init(&full,0,0);
sem_init(&sema,0,1);
pthread_t p,c;

//while(1)
//{
pthread_create(&p,0,producer,0);
pthread_create(&c,0,consumer,0);
pthread_join(p,NULL);
pthread_join(c,NULL);
//}
}
