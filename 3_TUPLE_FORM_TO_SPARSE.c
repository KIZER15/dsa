#include<stdio.h>
void main()
{
	int tulip[30][30],sparse[40][40],r,i,j,l=1,non_zero;
	printf("Enter the no. of rows\n");
	scanf("%d",&r);
	printf("Enter the data elements\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<3;j++)
		{
		scanf("%d",&tulip[i][j]);
	    }
	}
	printf("The 3-tuple-form matrix is\n");
	for(i=0;i<r;i++)
	{
	    for(j=0;j<3;j++)
	      printf(" %d ",tulip[i][j]);
	    printf("\n");
	}
	for(i=0;i<tulip[0][0];i++)
	{
		for(j=0;j<tulip[0][1];j++)
		{
			sparse[i][j]=0;
		}
	}
	non_zero=tulip[0][2];
	while(l<=non_zero)
	{
		i=tulip[l][0],j=tulip[l][1];
		sparse[i][j]=tulip[l][2];
		l++;
	}
	printf("The sparse matrix is\n");
	for(i=0;i<tulip[0][0];i++)
	{
		for(j=0;j<tulip[0][1];j++)
		{
			printf(" %d ",sparse[i][j]);
		}
		printf("\n");
	}
}
	
