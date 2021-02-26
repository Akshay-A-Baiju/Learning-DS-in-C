//1. Creation of node in C
// Author: Akshay A Baiju
// Date: 24/02/2021

#include<stdio.h>
#include<stdlib.h>
typedef struct node		//Defining structure of node for Singly Linked List
{
	int data;
	struct node *next;
}node;
node *createNode()		//Function for creating a new node	
{
	node *temp;
	temp=(node*)malloc(sizeof(node));		//Dynamic memory allocation for a node at run time
	return temp;
}
int main()
{
	node *head;		//pointer of struct node type to point to the head/start/first node of the linked list
	node *temp=createNode();
	printf("Enter data to store in node : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (head==NULL)
	head=temp;
	printf("Data : %d",temp->data);
	return 0;
}
