#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3
int f = -1;
int r = -1;
int cqueue[MAXSIZE];
void insert(int); // circular queue
int delete();
void display();
void main()
{
	int ch, x, y;

	printf("Enter 1 to insert value\nEnter 2 to delete value\nEnter 3 to display\nEnter 4 to exit\n");
	while (10)
	{
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter data\n");
			scanf("%d", &x);
			insert(x);
			break;

		case 2:
			y = delete ();
			if (y == -9999)
				printf("no element present in the queue\n");
			else
				printf("The deleted item is %d\n", y);
			break;

		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Entered wrong choice\n");
		}
	}
}
void insert(int x)
{
	if ((f == 0 && r == MAXSIZE - 1) || (f == r + 1))
		printf("The queue is full\n");
	else
	{

		if (r == -1)
		{
			f = 0;
			r = 0;
		}
		else if (r == MAXSIZE - 1)
			r = 0;
		else
			r = r + 1;

		cqueue[r] = x;
	}
}
int delete()
{
	int item;
	if (f == -1)
		return -9999;
	else
	{
		item = cqueue[f];
		if (f == r)
		{

			f = r = -1;
		}
		else if (f == MAXSIZE - 1)
		{

			f = 0;
		}

		else
		{

			f = f + 1;
		}
		return item;
	}
}
void display()
{
	int i;
	if (f <= r)
	{
		for (i = f; i <= r; i++)
			printf("%d ", cqueue[i]);
		printf("\n");
	}
	else
	{
		for (i = f; i <= MAXSIZE - 1; i++)
			printf("%d ", cqueue[i]);
		for (i = 0; i <= r; i++)
			printf("%d ", cqueue[i]);
	}
}
