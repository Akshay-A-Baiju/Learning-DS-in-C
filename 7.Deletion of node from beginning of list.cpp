// 7. Deletion of node from the beginning of Singly Linked list
// Author: Akshay A Baiju
// Date: 04/03/2021

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node				//structure of node
{
	int data;
	struct node *next;
}node;

node *createNode()				//dynamic allocation of memory for a new node created
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}

node *head=NULL;				//global pointer variable to store address of first node(initially NULL)

void insert()
{
	system("cls");
	node *temp=createNode();	
	printf("Enter data into node : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (head==NULL)				//to store the address of first node into head pointer
	head=temp;
	else
	{
		node *ref=head;			//reference pointer is used to traverse the linked list, initially pointing first node
		while (ref->next!=NULL)		//to move reference to point last node
			ref=ref->next;
		ref->next=temp;			//to store address of newly created node at the next address of last node of Linked List, this automatically connects the last node to the newly created node
	}
}

void deleteAtbeginning()
{
	system("cls");
	node *ref=head;
	node *del;
	if (head==NULL)				//if List is empty
		printf("Invalid operation \n");
	else if (head->next==NULL)		//if only 1 node in list
	{
		del=head;
		head=NULL;
		printf("Successfully deleted the only node in list \n");
		free(del);
	}
	else					//if length of node>1
	{
		del=head;
		head=head->next;
		printf("Successfully deleted first node of list \n");
		free(del);
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
		printf("2. to delete node from beginning \n");
		printf("3. to display List \n");
		printf("4. to exit \n");
		printf("Enter choice <1/2/3/4> : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();break;
			case 2:deleteAtbeginning();break;
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


