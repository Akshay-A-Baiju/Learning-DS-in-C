// 5. Insertion of node at any position
// Author: Akshay A Baiju
// Date: 02/03/2021

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node		//structure of node
{
	int data;
	struct node *next;
}node;

node *createNode()		//dynamic allocation of memory for a new node created
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}

node *head=NULL;		//global pointer variable to store address of first node(initially NULL)

void insert()
{
	system("cls");
	node *temp=createNode();	
	printf("Enter data into node : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (head==NULL)		//to store the address of first node into head pointer
	head=temp;
	else
	{
		node *ref=head;		//reference pointer is used to traverse the linked list, initially pointing first node
		while (ref->next!=NULL)		//to move reference to point last node
			ref=ref->next;
		ref->next=temp;		//to store address of newly created node at the next address of last node of Linked List, this automatically connects the last node to the newly created node
	}
}

void insertAtanyPosition()
{
	system("cls");
	node *temp=createNode();	
	int pos;
	printf("Enter position where you want to insert node : ");
	scanf("%d",&pos);
	printf("Enter data you want to enter : ");
	scanf("%d",&temp->data);
	temp->next=NULL;		
	int count=1;		//count is used to move the index from 1 (as in List indexing starts from 1)
	node *ref=head;		//ref pointer is used to move through the list (it points to the current active node)
	node *prev=NULL;	//to store the address of the previous of the active node
	if (pos<=0 || (pos>count && head==NULL))	//if your head is null it means your list es empty
	{											//let's say if you are trying to insert at 4th position but your head is empty.so it'll break the condition
		printf("Invalid operation \n");
	}
	else if (pos==1)		//to insert at first position
	{
		temp->next=head;
		head=temp;		
	}
	else 					//to insert at any position from second including last
	{
		while (ref!=NULL && count<pos)		//ref->next=NULL is not used as in that case we cannot insert node at last 
		{
			prev=ref;
			ref=ref->next;
			count++;
		}
		if (pos>count)		//if entered position of insertion is greater than the length of List
			printf("Invalid operation \n");
		else 
		{
			prev->next=temp;	//store the prev->next address from ref to temp
			temp->next=ref;		//and then linking temp->next from NULL to ref, ths a new node is successfully inserted between prev and ref
		}		
	}	
}

void display()
{
	system("cls");
	if (head==NULL)
	printf("The List is currently empty");
	else
	{
		node *ref=head;
		while (ref!=NULL)		//to move until last node
		{
			printf("%d->",ref->data);
			ref=ref->next;
		}
		printf("\n");
	}
}

int main()
{
	int choice,p=0;
	char ch;
	do
	{
		system("cls");
		printf("1. to insert a node to List \n");
		printf("2. to insert node at any position \n");
		printf("3. to display List \n");
		printf("4. to exit \n");
		printf("Enter choice <1/2/3/4> : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();break;
			case 2:insertAtanyPosition();break;
			case 3:display();break;
			case 4:p=1;break;
			default:printf("Enter a valid choice !!!");
		}
		printf("\nPress enter to continue...");
		getch();
	}
	while (p==0);
	return 0;
}


