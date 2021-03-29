//All Single Linked List operations
// Author: Akshay A Baiju
// Date: 29/03/2021

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *createNode()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}

node *head=NULL;

void insert()
{
	system("cls");
	node *temp=createNode();
	printf("Enter value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (head==NULL)
	head=temp;
	else
	{
		node *ref=head;
		while (ref->next!=NULL)
		ref=ref->next;
		ref->next=temp;
	}
}

void traverse()
{
	system("cls");
	if (head==NULL)
	printf("The List is empty!!! \n");
	else
	{
		node *ref=head;
		while (ref!=NULL)
		{
			printf("%d->",ref->data);
			ref=ref->next;
		}
	}
}

void length()
{
	system("cls");
	int l=0;
	node *ref=head;
	while (ref!=NULL)
	{
		l++;
		ref=ref->next;
	}
	printf("The length of list is : %d",l);
}

void insertAtBeginning()
{
	system("cls");
	node *temp=createNode();
	printf("Enter value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (head==NULL)
	head=temp;
	else
	{
		temp->next=head;
		head=temp;
	}
}

void insertAtAny()
{
	int pos,count=1;
	system("cls");
	printf("Enter position to insert node : ");
	scanf("%d",&pos);
	node *temp=createNode();
	printf("Enter value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (pos<=0 || (pos>count && head==NULL))
	printf("Invalid operation!!! \n");
	else if (pos==1)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		node *ref=head,*prev;
		while (ref!=NULL && count<pos)
		{
			prev=ref;
			ref=ref->next;
			count++;
		}
		if (count<pos)
		printf("Invalid operation!!! \n");
		else
		{
			prev->next=temp;
			temp->next=ref;			
		}
	}
}

void deleteFromEnd()
{
	system("cls");
	node *del;
	if (head==NULL)
	printf("Invalid operation!!! \n");
	else
	{
		if (head->next==NULL)
		{
			del=head;
			head=NULL;		
		}
		else
		{
			node *ref=head;
			while (ref->next->next!=NULL)
			ref=ref->next;
			del=ref->next;
			ref->next=NULL;		
		}
		printf("Successfully deleted from end \n");
	}
	free(del);
}

void deleteFromBeginning()
{
	system("cls");
	node *del;
	if (head==NULL)
	printf("Invalid operation!!! \n");
	else
	{
		if (head->next==NULL)
		{
			del=head;
			head==NULL;
		}
		else
		{
			del=head;
			head=head->next;
		}
		printf("Successfully deleted from beginning \n");
	}
	free(del);
}

void deleteAtAny()
{
	system("cls");
	int pos,count=1;
	node *del;
	printf("Enter position to delete : ");
	scanf("%d",&pos);
	if (pos<=0 || (pos>=count && head==NULL))
	printf("Invalid operation!!! \n");
	else if (pos==1 && head!=NULL)
	{
		del=head;
		head=head->next;
	}
	else
	{
		node *temp=head,*prev;
		while (temp->next!=NULL && count<pos)
		{
			prev=temp;
			temp=temp->next;
			count++;
		}
		if (count<pos)
		printf("Invalid operation!!! \n");
		else
		{
			prev->next=temp->next;
			del=temp;
		}
	}
	free(del);
}

void ins()
{
	system("cls");
	int choice;
	printf("1. to insert at end \n");
	printf("2. to insert at beginning \n");
	printf("3. to insert at any position \n");
	printf("Enter choice <1/2/3> : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:insert();break;
		case 2:insertAtBeginning();break;
		case 3:insertAtAny();break;
		default: printf("Enter correct choice \n");
	}
}

void del()
{
	system("cls");
	int choice;
	printf("1. to delete at end \n");
	printf("2. to delete at beginning \n");
	printf("3. to delete at any position \n");
	printf("Enter choice <1/2/3> : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:deleteFromEnd();break;
		case 2:deleteFromBeginning();break;
		case 3:deleteAtAny();break;
		default: printf("Enter correct choice \n");
	}
}

int main()
{
	int choice,p=0;
	do
	{
		system("cls");
		printf("1. to insert Node \n");
		printf("2. to delete Node \n");
		printf("3. to print List \n");
		printf("4. to printf length of list \n");
		printf("5. to exit \n");
		printf("Enter choice <1/2/3/4/5> : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:ins();break;
			case 2:del();break;
			case 3:traverse();break;
			case 4:length();break;
			case 5:p=1;break;
			default: printf("Enter correct choice!!! \n");
		}
		printf("\n\nEnter any key to continue... \n");
		getch();
	}
	while (p!=1);
	return 0;
}
