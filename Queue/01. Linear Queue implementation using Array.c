//Linear Queue implementation using Arrays and all stack operations
//Author: Akshay A Baiju
//Date: 01/10/21

#include<stdio.h>
#include<stdlib.h>
#define MAX 10                                                    //MAX capacity of queue array

int *queue;                                                       //queue array
int size=0;                                                       //current size of queue array, initially 0

void create_queue()
{
	queue=(int*)malloc(MAX*sizeof(int));                            //dynamic memory allocation of queue array
	if (queue==NULL)
	{
		printf("Queue memory allocation failed !!!");
		exit(0);
	}
}

void enqueue()
{
	if (size>=MAX)
	{
		printf("OVERFLOW !!!");
		return;
	}
	//not overflow, then enqueue
	int val;
	printf("Enter value to enqueue : ");
	scanf("%d",&val);
	queue[size]=val;
	size++;
}

void dequeue()
{
	if (size==0)
	{
		printf("UNDERFLOW !!!");
		return;
	}
	//not underflow, then dequeue
	for (int i=0;i<size-1;i++)
		queue[i]=queue[i+1];
	size--;
}

void queue_front()
{
	if (size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Front element of Queue : %d",queue[0]);
}

void queue_rear()
{
	if (size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Rear element of Queue : %d",queue[size-1]);	
}

void queue_count()
{
	printf("The count of elements in Queue : %d",size);
}

void display()
{
	if (size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("The Queue : ");
	for (int i=0;i<size;i++)
		printf("%d -> ",queue[i]);
}

int main()
{
	char cont;
	create_queue();
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Front of Queue\n");
	printf("4. Rear of Queue\n");
	printf("5. Count of elements in queue\n");
	printf("6. Display queue elements\n");
	do 
	{
		int ch;
		printf("\nEnter choice <1/2/3/4/5/6> : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();		  break;
			case 2: dequeue();		  break;
			case 3: queue_front();	break;
			case 4: queue_rear();	  break;
			case 5: queue_count();	break;
			case 6: display();		  break;
			default: printf("Choose correct choice !!!");
		}
		fflush(stdin);
		printf("\n\nDo you wish to continue <y/n> : ");
		scanf("%c",&cont);		
	}
	while (cont=='y');
	return 0;
}
