#include<stdio.h>
#include<ctype.h>
#include<string.h>
int preceed(char);
void push(char);
char pop();
char stck[100];
int top=-1;
void main()
{
	char inf[100],post[100],ch;
	int i=0,j=0;
    printf("Enter the infix expression\n");
	gets(inf);
	push('(');
	while(inf[i]!='\0')
	{
		if(isalpha(inf[i]))
		{
			post[j++]=inf[i];
		}
		else if(inf[i]=='(')
		{
			push(inf[i]);
		}
		else if(inf[i]==')')
		{
			ch=pop();
			while(ch!='(')
			{
				post[j++]=ch;
				ch=pop();
			}
		}
		else
		{
			while(preceed(inf[i])<=preceed(stck[top]))
			{
			 	post[j++]=pop();
			}
			push(inf[i]);	
		}
		i++;
	}
	post[j]='\0';
	printf(post);
	
}
int preceed(char c)
{
	int x;
	if(c=='(')
	x=100;
	if(c=='^')
	x=500;
	if(c=='*'||c=='%'|| c=='/')
	x=400;
	if(c=='+'|| c=='-')
	x=300;
	return x;
}
void push(char x)
{
	stck[++top]=x;
}
char pop()
{
	return stck[top--];
}
