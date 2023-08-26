#include<stdio.h>
void Toh(int,char,char,char);
int main()
{
	 int n;
	 printf("Enter the number of discs\n");
	 scanf("%d",&n);
	 Toh(n,'A','B','C');
 }
void Toh(int n,char source,char aux,char dest)
{
	if(n==1)
	{
		printf("Disc moved from %c to %c\n",source,dest);
		return;
	}
	else
	{
		Toh(n-1,source,dest,aux);
		Toh(1,source,aux,dest);
		Toh(n-1,aux,source,dest);
	}
}
