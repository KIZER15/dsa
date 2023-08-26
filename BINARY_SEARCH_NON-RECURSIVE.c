#include<stdio.h>
#include<stdlib.h>
void main()
{
	int arr[50];
	int lb=0,ub,mid,i,key,n;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Insert the data elemnts in the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("Enter the key element\n");
	scanf("%d",&key);
	ub=n-1;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(key==arr[mid])
		{
		printf("The element found at position %d\n",mid+1);
		exit(0);
	    }
		else
		{
			if(key>arr[mid])
			lb=mid+1;
			else
			ub=mid-1;
		}
	}
	printf("The element is not found\n");
	
}
