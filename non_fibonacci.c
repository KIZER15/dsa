#include<stdio.h>
int recur_fib(int);
int main()
{
     int n,i=0,j,count=1,t1,t2;
	 printf("Enter the number of terms\n");
	 scanf("%d",&n);
	 printf("The non fibonacci series is \n");
	 while(count<=n)
	 {
	 	t1=recur_fib(i);
	 	t2=recur_fib(i+1);
	 	for(j=t1+1;j<t2 && count<=n;j++)
	 	{
	 		printf(" %d ",j);
	 		count++;
		}
	    i++;
	}
}
int recur_fib(int x)
{
	if(x==0)
	return 0;
	else if(x==1)
	return 1;
	else
	return recur_fib(x-1)+recur_fib(x-2);
}