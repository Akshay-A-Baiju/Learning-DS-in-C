// 2. Insertion of Node and display list
// Author: Akshay A Baiju
// Date: 26/09/2021

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node					   //structure of node
{
	int data;
	struct node *next;
}node;

node *createNode()					   //dynamic allocation of memory for a new node created
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if (temp==NULL)
	{
		printf("Memory allocation failed!!!");
		exit(0);
	}
	return temp;
}

node *head=NULL;					     //global pointer variable to store address of first node(initially NULL)

void insert()
{
	system("cls");
	node *temp=createNode();
	printf("Enter data into node : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (head==NULL)					     //to store the address of first node into head pointer
		head=temp;
	else
	{
		node *ref=head;				    //reference pointer is used to traverse the linked list
		while (ref->next!=NULL)		//to move reference to point last node
			ref=ref->next;
		ref->next=temp;				    //to store address of newly created node at the next address of last node of Linked List, this automatically connects the last node to the newly created node
	}
}

void display()
{
	system("cls");
	if (head==NULL)
	printf("List is currently empty \n");
	else
	{
		node *ref=head;
		while(ref!=NULL)	
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
		printf("2. to display List \n");
		printf("3. to exit \n");
		printf("Enter choice <1/2/3> : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();	break;
			case 2: display();	break;
			case 3: p=1;		break;
			default:printf("Enter a valid choice !!!");
		}
		printf("\nPress enter to continue...");
		getch();
	}
	while (p==0);
	return 0;
}
