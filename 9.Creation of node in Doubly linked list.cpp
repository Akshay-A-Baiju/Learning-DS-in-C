//9. Creation of node in Doubly linked list
// Author: Akshay A Baiju
// Date: 09/03/2021

#include<stdio.h>
#include<stdlib.h>
typedef struct node												//Defining structure of node for Doubly Linked List
{
	int data;
	struct node *prev;
	struct node *next;
}node;

node *createNode()												//Function for creating a new node	
{
	node *temp;
	temp=(node*)malloc(sizeof(node));							//Dynamic memory allocation for a node at run time
	return temp;
}

int main()
{
	node *head=NULL;
	node *temp=createNode();
	printf("Enter data into Node of Doubly Linked list : ");	//pointer of struct node type to point to the head/start/first node of the Doubly linked list
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;
	if (head==NULL)
	head=temp;
	printf("Data : %d",temp->data);
	return 0;
}
