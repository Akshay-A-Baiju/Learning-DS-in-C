// 6. Deletion of node from the end of Singly Linked list
// Author: Akshay A Baiju
// Date: 03/03/2021

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

void deleteAtend()
{
	system("cls");
	node *ref=head;
	node *del;
	if (head==NULL)		//if List is empty
		printf("Invalid operation \n");
	else				//if list isn't empty
	{
		if (head->next==NULL)		//only one node in list
		{
			del=head;
			head=NULL;
		}
		else		//length of list>1
		{
			while (ref->next->next!=NULL)		//to move to second last node
				ref=ref->next;
			del=ref->next;						//ref now stores the second last node thus ref->next stores last node
			ref->next=NULL;						//to make second last node as last node, we make next part of it as NULL, thus the link to last node is successfully breaked
		}
		//del now stores the last node address to be deleted/freed
		free(del);		//to free the memory of last node
		printf("Last node successfully deleted \n");
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
		printf("2. to delete node from last position \n");
		printf("3. to display List \n");
		printf("4. to exit \n");
		printf("Enter choice <1/2/3/4> : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();break;
			case 2:deleteAtend();break;
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


