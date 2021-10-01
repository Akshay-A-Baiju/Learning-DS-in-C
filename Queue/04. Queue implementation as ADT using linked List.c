//Queue implementation as ADT using Linked List and all operations
//Author: Akshay A Baiju
//Date: 01/10/21

#include<stdio.h>
#include<stdlib.h>

typedef struct qnode                                          //structure of Queue node
{
	int data;
	struct qnode *next;
}qnode;

typedef struct Queue                                          //structure of Queue -> Queue as ADT
{
	qnode *front;
	qnode *rear;
	int size;
}queue;

queue *q;

void create_queue()                                           //dynamic allocate memory for queue and initialize the values of front, rear, size
{
	q=(queue*)malloc(sizeof(queue));
	if (q==NULL)
	{
		printf("Memory allocation failed !!!");
		exit(0);
	}
	q->front=NULL;
	q->rear=NULL;
	q->size=0;
}

void enqueue()
{
	qnode *newnode = (qnode*)malloc(sizeof(qnode));             //dynamic allocate memory for a new Queue list node
	if (newnode==NULL)
	{
		printf("OVERFLOW !!!");
		exit(0);
	}
	//if not overflow, then enqueue
	printf("Enter value to enqueue : ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if (q->front==NULL)	                                        //if queue is empty
	{
		q->front=newnode;
		q->rear=newnode;
		q->size=1;
	}
	else
	{
		q->rear->next=newnode;
		q->rear=newnode;
		q->size++;
	}	
}

void dequeue()
{
	if (q->size==0)
	{
		printf("UNDERFLOW !!!");
		return;
	}
	if (q->front==q->rear)	                                    // or (q->size==1) , i.e. if only 1 element present in Queue list
	{
		qnode *p=q->front;
		q->front=NULL;
		q->rear=NULL;
		q->size--;
		free(p);
	}
	else
	{
		qnode *p=q->front;
		q->front=q->front->next;
		q->size--;
		free(p);
	}
}

void queue_front()
{
	if (q->size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Front element of Queue : %d",q->front->data);
}

void queue_rear()
{
	if (q->size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("Rear element of Queue : %d",q->rear->data);
}

void queue_count()
{
	printf("Count of elements in Queue : %d",q->size);
}

void display()
{
	if (q->size==0)
	{
		printf("Queue is empty !!!");
		return;
	}
	printf("The Queue : ");
	qnode *p=q->front;
	while (p!=NULL)
	{
		printf("%d -> ",p->data);
		p=p->next;
	}
}

int main()
{
	create_queue();
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
