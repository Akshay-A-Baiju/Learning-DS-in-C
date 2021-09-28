//Author: Akshay A Baiju
//Date: 28/09/21

#include<stdio.h>
#include<stdlib.h>
#define MAX 10                        //maximum size of stack array

int tos=-1;			                      //Top of stack, -1 means stack is empty
int *stk;			                        //stack as array

void create()
{
	stk=(int*)malloc(MAX*sizeof(int));  //dynamically allocating memory for Array
	if (stk==NULL)
	{
		printf("Memory allocation failed!!!");
		exit(0);
	}
	int n;
	printf("Enter number of elements to push into Stack : ");
	scanf("%d",&n);
	printf("Enter elements : ");
	for (int i=1;i<=n;i++)
	{
		if (tos==MAX-1)
		{
			printf("STACK OVERFLOW !!!");
			return;
		}
    //else if push to stack is possible
		tos++;
		scanf("%d",&stk[tos]);
	}
}

void push()
{
	if (tos>=MAX-1)
	{
		printf("STACK OVERFLOW !!!");
		return;
	}
  //else if push to stack is possible
	printf("Enter new element to Push into Stack : ");
	scanf("%d",&stk[++tos]);
	printf("Element pushed successfully !!!");
}

void pop()
{
	if (tos<=-1)
	{
		printf("STACK UNDERFLOW !!!");
		return;
	}
  //else if pop element from stack possible
	printf("Element %d poped successfully !!!",stk[tos]);
	tos--;
}

void peek()
{
	if (tos==-1)                        //if stack is empty
	{
		printf("STACK UNDERFLOW !!!");
		return;
	}
  //if stack is not empty
	printf("PEEK element of Stack : %d",stk[tos]);
}

void peep()
{
	if (tos==-1)                        //if stack is empty
	{
		printf("STACK UNDERFLOW !!!");
		return;
	}
  //if stack is not empty
	int pos;
	printf("Enter position to PEEP element in Stack : ");
	scanf("%d",&pos);
	if (pos<=0)
	{
		printf("Invalid peep position !!!");
		return;
	}
	if (tos-pos+1<0)
		printf("Peep position more than current Stack size !!!");
	else
		printf("Peep position %d of Stack : %d",pos,stk[tos-pos+1]);
}

void update()                       //similar to peep, only update the value at peep element
{
	if (tos>=MAX-1)
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
	if (tos-pos+1<0)
		printf("UPDATE position more than current Stack size !!!");
	else
	{
		printf("Enter new updated value : ");
		scanf("%d",&stk[tos-pos+1]);
		printf("Element updated successfully !!!");
	}	
}

void display()
{
	if (tos<=-1)
	{
		printf("Stack is EMPTY !!!\n");
		return;
	}
  //if stack is not empty
	printf("The Stack : ");
	for (int i=tos;i>=0;i--)
		printf("%d -> ",stk[i]);
}

int main()
{
  //Menu driven, user interactive program of all stack operations
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
