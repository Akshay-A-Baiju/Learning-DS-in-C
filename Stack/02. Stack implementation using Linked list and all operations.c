//Author: Akshay A Baiju
//Date: 28/09/21

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack                            //structure of Stack
{
	int data;
	struct Stack *next;
}node;

node *tos=NULL;			                            //points to Top of Stack, initially NULL

void create()
{
	int n;
	printf("Enter number of elements to push into Stack : ");
	scanf("%d",&n);
	printf("Enter elements : ");
	for (int i=1;i<=n;i++)
	{
		node *p=(node*)malloc(sizeof(node));        //dynamic allocation of node
		if (p==NULL)
		{
			printf("Memory allocation failed!!!");
			exit(0);
		}
		scanf("%d",&p->data);
		
		if (i==1)
		{
			tos=p;
			tos->next=NULL;
		}
		else
		{
			p->next=tos;
			tos=p;
		}		
	}	
}

void push()
{
	node *p=(node*)malloc(sizeof(node));           //dynamic allocation of node
	if (p==NULL)
	{
		printf("STACK OVERFLOW !!!");
		return;
	}
	printf("Enter new element to Push into Stack : ");
	scanf("%d",&p->data);
  //insert new node as top of stack
	p->next=tos;
	tos=p;
	printf("Element pushed successfully !!!");
}

void pop()
{
	if (tos==NULL)
	{
		printf("STACK UNDERFLOW !!!");
		return;
	}
  //delete first node of list
	node *p=tos;
	tos=tos->next;
	free(p);
	printf("Element poped successfully !!!");
}

void peek()
{
	if (tos==NULL)
	{
		printf("STACK UNDERFLOW !!!");
		return;
	}
  //value of head of list
	printf("PEEK element of Stack : %d",tos->data);
}

void peep()
{
	if (tos==NULL)
	{
		printf("STACK UNDERFLOW !!!");
		return;
	}
	int pos;
	printf("Enter position to PEEP element in Stack : ");
	scanf("%d",&pos);
	if (pos<=0)
	{
		printf("Invalid peep position !!!");
		return;
	}
	int count=1;
	node *p=tos;
	while (count<pos && p!=NULL)
	{
		p=p->next;
		count++;
	}
	if (p==NULL)
		printf("Peep position more than current Stack size !!!");
	else
		printf("Peep position %d of Stack : %d",pos,p->data);
}

void update()                                   //similar to peep, here update value of peep element
{
	if (tos==NULL)
	{
		printf("STACK UNDERFLOW !!!");
		return;
	}
	int pos;
	printf("Enter position to UPDATE element in Stack : ");
	scanf("%d",&pos);
	if (pos<=0)
	{
		printf("Invalid UPDATE position !!!");
		return;
	}
	int count=1;
	node *p=tos;
	while (count<pos && p!=NULL)
	{
		p=p->next;
		count++;
	}
	if (p==NULL)
		printf("UPDATE position more than current Stack size !!!");
	else
	{
		printf("Enter new updated value : ");
		scanf("%d",&p->data);
		printf("Element at %d updated successfully !!!",pos);
	}	
}

void display()
{
	node *p=tos;
	if (p==NULL)
	{
		printf("Stack is EMPTY !!!\n");
		return;
	}
	while (p!=NULL)
	{
		printf("%d -> ",p->data);
		p=p->next;
	}
}

int main()
{
  //Menu-driven, user interactive program on all stack operations
	int choice;
	char ch;
	printf("1. CREATE Stack\n");
	printf("2. PUSH element to Stack\n");
	printf("3. POP element from Stack\n");
	printf("4. PEEK element from Stack\n");
	printf("5. PEEP element from Stack\n");
	printf("6. UPDATE element in Stack\n");
	printf("7. DISPLAY Stack\n");
	do
	{
		printf("\nEnter choice <1/2/3/4/5/6/7> : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1: create(); break;
			case 2: push(); break;
			case 3: pop(); break;
			case 4: peek(); break;
			case 5: peep(); break;
			case 6: update(); break;
			case 7: display(); break;
			default: printf("Enter correct choice !!!\n");			
		}
		fflush(stdin);
		printf("\n\nDo you wish to continue <y/n> : ");
		scanf("%c",&ch);
	}
	while (ch=='y');	
}
