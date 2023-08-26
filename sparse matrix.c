#include<stdio.h>
void main()
{
	int arr[30][30],sparse[40][40],c,r,i,j,zero=0,non_zero,t=0,s=1;
	printf("Enter the no. of rows\n");
	scanf("%d",&r);
	printf("Enter the no. of columns\n");
	scanf("%d",&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		scanf("%d",&arr[i][j]);
		if(arr[i][j]==0)
		zero++;
	    }
	}
	printf("The matrix is\n");
	for(i=0;i<r;i++)
	{
	for(j=0;j<c;j++)
	printf(" %d ",arr[i][j]);
	printf("\n");
	}
	non_zero=r*c-zero;
	if(zero>non_zero)
	{
		printf("Its a sparse matrix\n");
		sparse[0][0]=r,sparse[0][1]=c,sparse[0][2]=non_zero;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(arr[i][j]!=0)
				{
					sparse[s][0]=i;
					sparse[s][1]=j;
					sparse[s][2]=arr[i][j];
					s++;
				}
				
			}
		}
	for(i=0;i<non_zero+1;i++)
	{
	for(j=0;j<3;j++)
	printf(" %d ",sparse[i][j]);
	printf("\n");
	}	
	}
	else
	printf("Not a sparse matrix\n");	
}
