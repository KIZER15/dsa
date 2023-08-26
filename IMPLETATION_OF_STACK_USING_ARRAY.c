#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top=-1;
void push(int);
int pop();
void display();
void peek();
void main()
{
	int ch,x,y;
	
	printf("Enter 1 to implement push function\nEnter 2 to implement pop function\nEnter 3 to implement display\nEnter 4 to implement peek function\nEnter 5 to exit\n");
	while(10)
	{
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				  printf("Enter data\n");
				  scanf("%d",&x);
				  push(x);
				  break;
			case 2:
					y=pop();
					if(y==-9999)
					printf("Stack underflow\n");
					else
					printf("The popped item is %d\n",y);
					break;
			case 3: display();
			        break;
			case 4: peek();
			        break;        
		    case 5: exit(0);
			default: printf("Wrong choice entered\n");		 
		}
	}
}
void push(int x)
{
	
	if(top==MAXSIZE-1)
	{
		printf("Overflow\n");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}
int pop ()
{
	int item;
	if(top==-1)
	return -9999;
	else
	{
		item=stack[top];
		top--;
		return item;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
	for(i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
    }
}
void peek()
{
	if(top==-1)
	{
		printf("The stack is empty\n");
	}
	else
	printf("The topmost element is %d\n",stack[top]);
}

