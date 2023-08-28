#include<stdio.h>
#include<ctype.h>
#include<string.h>
int preceed(char);
void push(char);
char pop();
char stck[100];
int top=-1;
int main()
{
	char inf[100],post[100],ch,rev[100],prefix[100];
	int i=0,j=0;
    printf("Enter the infix expression\n");
	gets(inf);
	strcpy(rev,strrev(inf));
	strcat(rev,")");
	push('(');
	while(rev[i]!='\0')
	{
		if(isalpha(rev[i]))
		{
			post[j++]=rev[i];
		}
		else if(rev[i]=='(')
		{
			push(rev[i]);
		}
		else if(rev[i]==')')
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
			while(preceed(rev[i])<=preceed(stck[top]))
			{
			 	post[j++]=pop();
			}
			push(rev[i]);	
		}
		i++;
	}
	post[j]='\0';
	strcpy(prefix,strrev(post));
	printf("%s\n",prefix);
	
	
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
