#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

linkedlist_traversal(node *ptr)
{
    while(ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr=ptr->next;
    }

}

void main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));

    head ->data = 12;
    head ->next=second;

    second ->data = 12;
    second ->next=third;

    third ->data = 12;
    third->next=fourth;

    fourth ->data = 12;
    fourth ->next=NULL;

    linkedlist_traversal(head);


}
