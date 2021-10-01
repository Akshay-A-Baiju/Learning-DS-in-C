//Circular Queue implementation using Arrays and all Queue operations
//Author: Akshay A Baiju
//Date: 01/10/21

#include<stdio.h>
#include<stdlib.h>
#define MAX 10                                                //MAX capacity of queue array

int *queue;                                                   //queue array
int front,size;                                               //stores the front index and size of queue array respectively, hence can be calculated easily as rear=(front+size-1)%MAX

void create_queue()
{
	queue=(int*)malloc(MAX*sizeof(int));
	if (queue==NULL)
	{
		printf("Queue memory allocation failed !!!");
		exit(0);
	}
}

int getRear()                                                 //calculate index of rear element
{
	int rear=(front+size-1)%MAX;
	return rear;
}

void enqueue()
{
	if (size==MAX)
	{
		printf("OVERFLOW !!!");
		return;
	}
	//not overflow, then enqueue
	int val;
	printf("Enter value to enqueue : ");
	scanf("%d",&val);
	int rear=getRear();
	rear=(rear+1)%MAX;
	queue[rear]=val;                                            //enqueue new element to rear+1
	size++;                                                     //update size of Queue array
}

void dequeue()
{
	if (size==0)
	{
		printf("UNDERFLOW !!!");
		return;
	}
	//not underflow, then dequeue
	front=(front+1)%MAX;                                        //move front by 1 pos, thus earlier front is dequeued
	size--;                                                     //update size of Queue array
}

void queue_front()
{
	if (size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Front element of Queue : %d",queue[front]);
}

void queue_rear()
{
	int rear=getRear();
	if (size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Rear element of Queue : %d",queue[rear]);	
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
	for (int i=front;i<front+size;i++)
	{
		int ind=i%MAX;
		printf("%d -> ",queue[ind]);
	}
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
