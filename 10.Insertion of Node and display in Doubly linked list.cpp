// 10. Insertion of node and display in Doubly Linked List
// Author: Akshay A Baiju
// Date: 12/03/2021

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node												//structure of node in Doubly Linked List
{
	int data;
	struct node *prev;
	struct node *next;
}node;

node *createNode()												//dynamic allocation of memory for a new node created at run time
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}

node *head=NULL;												//global pointer variable to store address of first node(initially NULL)

void insert()
{
	system("cls");
	node *temp=createNode();
	printf("Enter data in Doubly Linked list : ");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;
	if (head==NULL)												//to store the address of first node into head pointer
		head=temp;
	else
	{
		node *ref=head;											//reference pointer is used to traverse the Doubly linked list, initially pointing first node
		while (ref->next!=NULL)									//to move reference to point last node
			ref=ref->next;
		temp->prev=ref;											//stores the address of last node to the prev part of newly created node
		ref->next=temp;											//to store address of newly created node at the next address of last node of Linked List
	}
}

void display()
{
	system("cls");
	if (head==NULL)
		printf("List is empty!!! \n");
	else
	{
		node *ref=head;
		while (ref!=NULL)										//to move untill last node
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
	do
	{
		system("cls");
		printf("1. To insert data in Doubly Linked list \n");
		printf("2. To display the Doubly Linked lis \n");
		printf("3. To exit \n");
		printf("Enter choice <1/2/3> : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:insert();break;
			case 2:display();break;
			case 3:p=1;break;
			default: printf("Enter correct choice!!! \n");
		}
		printf(" \n\nPress any key to continue...");
		getch();
	}
	while (p==0);
	return 0;
}
