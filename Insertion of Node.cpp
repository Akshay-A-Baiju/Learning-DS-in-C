//1. Insertion of Node using C
//Author: Akshay A Baiju
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

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

node *head=NULL;	//global pointer variable to store address of first node(initially NULL)

void insert()
{
	system("cls");
	node *temp=createNode();
	cout<<"Enter data into node : ";
	cin>>temp->data;
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

void display()
{
	system("cls");
	if (head==NULL)
	cout<<"List is currently empty"<<endl;
	else
	{
		node *ref=head;
		cout<<ref->data<<"->";
		while(ref->next!=NULL)	
		{
			ref=ref->next;
			cout<<ref->data<<"->";
		}	
		cout<<endl;
	}
}

int main()
{
	int choice,p=0;
	char ch;
	do
	{
		system("cls");
		cout<<"1. to insert a node to List"<<endl;
		cout<<"2. to display List"<<endl;
		cout<<"3. to exit"<<endl;
		cout<<"Enter choice <1/2/3> : ";
		cin>>choice;
		switch(choice)
		{
			case 1:insert();break;
			case 2:display();break;
			case 3:p=1;break;
			default:cout<<"Enter a valid choice !!!";
		}
		cout<<"Press enter to continue...";
		getch();
	}
	while (p==0);
	return 0;
}
