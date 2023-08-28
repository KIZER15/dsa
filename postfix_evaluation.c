#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void push(int);
int pop();
int selector(char);
char p[25];int a,b,c,d,e,top=-1;
int main()
{
	char ele,x1,x2;int i,num1,num2;
	printf("Enter the postfix expression\n");
	gets(p);
	printf("Enter the values of the terms in the expression\n");
	scanf("%d%d%d",&a,&b,&c);
	for(i=0;p[i]!='\0';i++)
	{
		ele=p[i];
		if(isalpha(ele))
		push(ele);
		else
		{
			x1=pop();
			num1=selector(x1);
			x2=pop();
			num2=selector(x2);
			switch(ele)
			{
				case '^' : push(pow(num2,num1));
				           break;
			    case '*' : push(num2*num1);
			               break;
			    case '/' : push(num2/num1);
			               break;
			    case '+' : push(num2+num1);
			               break;
			    case '-' : push(num2-num1);
			               break;
			}
		}
	}
	printf("The result after evaluation of the expression is %d",p[top]);
}
void push(int x)
{
	p[++top]=x;
}
int pop()
{
	return p[top--];
}
int selector(char x)
{
	switch(x)
	{
		case 'a' : return a;
		            break;
	    case 'b' : return b;
		            break;
	    case 'c' : return c;
		            break;
		case 'd' : return d;
		            break;
	}
}
