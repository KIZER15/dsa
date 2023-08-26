#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 7
int f=-1;
int r=-1;
int queue[MAXSIZE];
void insert(int);
int delete();
void display();
void main()
{
	int ch,x,y,a=5;
	
	printf("Enter 1 to insert value\nEnter 2 to delete \nEnter 3 to display\nEnter 4 to exit\n");
	while(4)
	{
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
				case 1:  printf("Enter data\n");
					     scanf("%d",&x);
					     insert(x);
					     break;
			    
				case 2:  y=delete();
						 if(y==-9999)
						 printf("no element present in the queue\n");
						 else
						 printf("The deleted item is %d\n",y);
						 break; 
				
				case 3:  display();
				         break;
			    case 4:  exit(0);
			    default: printf("Entered wrong choice\n");
	    }
    }
}
    void insert(int x)
    {
    	if(r==MAXSIZE-1)
    	printf("The queue is full");
    	else 
    	{
		if (f==-1 || r==-1)
    	f=r=0;
    	else
    	r=r+1;
        }
        queue[r]=x;
    }
    
    int delete()
    {
    	int item;
    	if(f==-1)
    	{
    		return -9999;	
		}
		else
		{
			if(f==r)
		    {
		    item=queue[f];
			f=-1;
			return item;
			}
			else
			{
			item=queue[f];
			f=f+1;
			return item;
		    }
		}
	}
	
	
	void display()
	{
		
		int i;
		if(f==-1 || r==-1)
		printf("Queue is empty\n");
		else
		{
		for(i=f;i<=r;i++)
		printf("%d ",queue[i]);
	    }
		
		printf("\n");
	}
    	

