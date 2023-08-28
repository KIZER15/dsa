#include <stdio.h>
#include <stdlib.h>
void display();
void insert_beginning();
void insert_end();
void create_list();
void insert_pos();
void insert_before_val();
void insert_after_val();
void delete_beginning();
// void delete_end();
void delete_before_val();
void delete_after_val();
void delete_at_pos();
// void reverse();

typedef struct link
{
	int data;
	struct link *next;
} list;
list *start = NULL;

void main()
{
	int ch;
	printf("Enter 1 to create list\nEnter 2 to insert at the begining\nEnter 3 to insert at the end\nEnter 4 to display\nEnter 5 to insert at a given position\nEnter 6 to enter before a given value\nEnter 7 to insert after a given value\nEnter 8 to delete from the beginning\nEnter 9 to delete from the end\nEnter 10 to delete after a value\nEnter 11 to delete before value\nEnter 12 to delete at position\nEnter 13 to reverse the list\nEnter 14 to exit");
	while (1)
	{
		printf("Enter the choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			create_list();
			break;
		case 2:
			insert_beginning();
			break;
		case 3:
			insert_end();
			break;
		case 4:
			display();
			break;
		case 5:
			insert_pos();
			break;
		case 6:
			insert_before_val();
			break;
		case 7:
			insert_after_val();
			break;
		case 8:
			delete_beginning();
			break;
		// case 9:
		// 	delete_end();
		case 10:
			delete_after_val();
			break;
		case 11:
			delete_before_val();
			break;
		// case 12:
		// 	delete_at_pos();
		// 	break;
		// case 13:
		// 	reverse();
		// 	break;
		case 14:
			exit(0);
		default:
			printf("Wrong choice entered\n");
			break;
		}
	}
}

void insert_end()
{

	list *new_node, *temp;
	temp = start;
	new_node = (list *)calloc(1, sizeof(list));
	printf("Entered new node data\n");
	scanf("%d", &new_node->data); // dont mess with scanf by using space
	new_node->next = NULL;
	if (start == NULL)
	{
		start = new_node;
	}
	else
	{
		temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
void create_list()
{
	char ch;
	do
	{
		insert_end();
		printf("do you continue the insertion operation\n");
		scanf(" %c", &ch);
	} while (ch == 'Y' || ch == 'y');
}
void display()
{
	list *temp;
	if (start == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		temp = start;
		while (temp != NULL)
		{
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}
void insert_beginning()
{
	list *new_node;
	new_node = (list *)calloc(1, sizeof(list));
	printf("Entered new node data\n");
	scanf(" %d", &new_node->data);
	new_node->next = NULL;
	if (start == NULL)
		start = new_node;
	else
	{
		new_node->next = start;
		start = new_node;
	}
}
void insert_pos()
{
	list *new_node;
	int pos, count = 0, p;
	printf("Enter the position for insertion\n");
	scanf(" %d", &pos);
	list *temp;
	temp = start;
	while (temp != NULL)
	{
		count = count + 1;
		temp = temp->next;
	}
	if (pos == 1 && count >= 0)
		insert_beginning();

	else if (pos == count + 1 && count > 0)
		insert_end();

	else if (pos <= count && pos > 1)
	{
		p = 1;
		new_node = (list *)calloc(1, sizeof(list));
		printf("Entered new node data\n");
		scanf(" %d", &new_node->data);
		new_node->next = NULL;
		temp = start;
		while (p < (pos - 1))
		{
			temp = temp->next;
			p = p + 1;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	else
	{
		printf("Insertion failed\n");
	}
}
void insert_before_val()
{
	int x;
	list *new_node, *temp, *t, *p;
	printf("Enter the value before which the node to be inserted\n");
	scanf("%d", &x);
	new_node = (list *)calloc(1, sizeof(list));
	printf("Entered new node data\n");
	scanf("%d", &new_node->data);
	new_node->next = NULL;
	temp = start;
	while (temp != NULL)
	{
		if (temp->data != x)
		{
			t = temp;
			temp = temp->next;
		}
		else
			break;
	}
	if (temp == NULL)
		printf("The element not found\n");
	else
	{
		new_node->next = t->next;
		t->next = new_node;
	}
}

void insert_after_val()
{
	int x;
	list *new_node, *temp, *t;
	printf("Enter the value after which the node to be inserted\n");
	scanf("%d", &x);
	new_node = (list *)calloc(1, sizeof(list));
	printf("Entered new node data\n");
	scanf(" %d", &new_node->data);
	new_node->next = NULL;
	temp = start;
	while (temp != NULL)
	{
		if (temp->data != x)
			temp = temp->next;
		else
			break;
	}
	if (temp == NULL)
		printf("The element not found\n");
	else
	{
		new_node->next = temp->next;
		temp->next = new_node;
	}
}

void delete_beginning()
{
	if (start == NULL)
		printf("The list is empty\n");
	else
	{
		list *temp;
		temp = start;
		start = temp->next;
		free(temp);
	}
}
void delete_after_val()
{
	int val;
	list *temp, *t;
	printf("Enter the value after which the node to be deleted\n");
	scanf("%d", &val);
	temp = start;
	while (temp->data != val && temp != NULL)
	{
		t = temp;
		temp = temp->next;
		if (temp == NULL)
			printf("The element not found\n");
		else if (temp->next == NULL)
			printf("The deletion not possible\n");
		else
		{
			t = temp->next;
			temp->next = t->next;
			free(t);
		}
	}
}

void delete_before_val()
{
	int val;
	list *temp,*t1,*t2;
	temp=t1=t2=start;
	printf("Enter the value after which the node to be deleted\n");
	scanf("%d", &val);
	
	if(start==NULL)
	printf("The list is empty\n");
	else
	{
		while(temp->data !=val)
		{
			t1=temp;
	        t2=t1;
			temp=temp->next;
		}
		t2->next=temp;
		free(t1);
	}

}