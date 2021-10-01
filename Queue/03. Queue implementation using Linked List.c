//Queue implementation using Linked List
//Author: Akshay A Baiju
//Date: 01/10/21

#include<stdio.h>
#include<stdlib.h>

typedef struct Queue                                      //structure of Queue node
{
	int data;
	struct Queue *next;
}node;

node *front=NULL,*rear=NULL;                              //points to the front node and rear node respectively

void enqueue()
{
	node *newnode = (node*)malloc(sizeof(node));
	if (newnode==NULL)
	{
		printf("OVERFLOW !!!");
		exit(0);
	}
	//if not overflow, then enqueue
	printf("Enter value to enqueue : ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if (front==NULL)	                                      //if queue is empty, set both front and rear as newnode
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}	
}

void dequeue()
{
	if (front==NULL)                                        //if queue is empty
	{
		printf("UNDERFLOW !!!");
		return;
	}
	if (front==rear)					//only 1 element in Queue
	{
		node *p=front;
		front=rear=NULL;
		free(p);
	}
	else
	{
		node *p=front;
		front=front->next;                              //move front to front->next and free the earlier memory
		free(p);
	}
}

void queue_front()
{
	if (front==NULL)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Front element of Queue : %d",front->data);
}

void queue_rear()
{
	if (front==NULL)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Rear element of Queue : %d",rear->data);
}

void queue_count()
{
	int count=0;
  node *p=front;
  while (p!=NULL)                                         //move till end of queue list
  {
    count++;
    p=p->next;
  }
	printf("Count of elements in Queue : %d",count);
}

void display()
{
	if (front==NULL)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("The Queue : ");
	node *p=front;
	while (p!=NULL)                                         //move till end of queue list
	{
		printf("%d -> ",p->data);
		p=p->next;
	}
}

int main()
{
	char cont;
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
			case 1: enqueue();		break;
			case 2: dequeue();		break;
			case 3: queue_front();	break;
			case 4: queue_rear();	break;
			case 5: queue_count();	break;
			case 6: display();		break;
			default: printf("Choose correct choice !!!");
		}
		fflush(stdin);
		printf("\n\nDo you wish to continue <y/n> : ");
		scanf("%c",&cont);		
	}
	while (cont=='y');
	return 0;
}
