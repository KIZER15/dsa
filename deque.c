#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 4
int f=-1,r=-1; 
int de_queue[MAXSIZE];
void insert_front(int);
void insert_rear(int);
int deletion_rear();
int deletion_front();
void display();
int main()
{
	int ch,ele,x;
	printf("Enter 1 to insert from front\nEnter 2 to insert from rear\nEnter 3 to delete from front\nEnter 4 to delete from rear\nEnter 5 to display\nEnter 6 to exit\n");
	while(10)
	{
	     printf("Enter your choice\n");
		 scanf("%d",&ch);
		 switch(ch)
		 {
		 	case 1: printf("Enter the element\n");
		 	        scanf("%d",&ele);
		 	        insert_front(ele);
		 	        break;
		 	case 2: printf("Enter the element\n");
		 	        scanf("%d",&ele);
		 	        insert_rear(ele);
		 	        break;
		    case 3: x=deletion_front();
		            if(x=-999)
		            printf("Underflow");
		            else
		            printf("The deleted element from front is %d",x);
		            break;
		    case 4: x=deletion_rear();
		            if(x=-999)
		            printf("Underflow");
		            else
		            printf("The deleted element from rear is %d",x);
		            break;
		    case 5: display();
		    		break;
		    case 6: exit(0);
		    default:printf("Wrong choice\n");
		}
	}
}
void insert_rear(int a)
{ 
	if((f==0 && r==MAXSIZE-1)|| f-r==1)
	     printf("The circular queue is full\n");
    else
	{
	    if(r==-1)
	    f=r=0;
	    else if(r==MAXSIZE-1)
	    r=0;
	    else
	    r++;
	    de_queue[r]=a;
	} 
}
int deletion_front()
{
	int item;
	if(f==-1)
	return -999;
	else
	{
		item=de_queue[f];
	    if(f==r)
	    f=r=-1;
	    else if(f==MAXSIZE-1)
	    f=0;
	    else
	    f++;
	    return item;
	}
}
void insert_front(int val)
{
	if((f==0 && r==MAXSIZE-1)||f==r+1)
	printf("queue is full");
	else
	{
		if (f==-1)
		{
			f=0;
			r=0;
		}
		else if(f==0)
		f=MAXSIZE-1;
		else
		f=f-1;
	}
	de_queue[f]=val;	
}
int deletion_rear()
{
	int item;
	if(r==-1)
	return -999;
	else
	{
		item=de_queue[f];
	    if(f==r)
	    f=r=-1;
	    else if(r==0)
	    r=MAXSIZE-1;
	    else
	    r=r-1;
	    return item;	
    }
}

void display()
{
	int i;
	if(f<=r)
	{
	    for(i=f;i<=r;i++)
	        printf("%d ",de_queue[i]);
	     printf("\n");
    }
	else
	{
		for(i=f;i<=MAXSIZE-1;i++)
		printf("%d ",de_queue[i]); 
		for(i=0;i<=r;i++)
		printf("%d ",de_queue[i]);	
	}
}

