// 11. Insertion of node at beginning of Doubly Linked List
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

void insertAtBeginning()
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
		head->prev=temp;										//to make the prev pointer of current head to store address of new node
		temp->next=head;										//to make the next pointer of new node to store the address of head, thus successfully links the new node in front of head
		head=temp;												//finally make the new node as the head pointer of the list
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
		printf("2. To insert data at beginning of Dloubly Linked list \n");
		printf("3. To display the Doubly Linked list \n");
		printf("4. To exit \n");
		printf("Enter choice <1/2/3/4> : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:insert();break;
			case 2:insertAtBeginning();break;
			case 3:display();break;
			case 4:p=1;break;
			default: printf("Enter correct choice!!! \n");
		}
		printf(" \n\nPress any key to continue...");
		getch();
	}
	while (p==0);
	return 0;
}
