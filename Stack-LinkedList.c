#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node *header = NULL;
struct Node *CreateNode(int data)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->link = NULL;
    return (newnode);
};

void traverse()
{
    struct Node *ptr = header;
    if (ptr == NULL)
        printf("\nEmpty Stack\n");
    else
    {
        printf("\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n");
}

void push(int data)
{
    struct Node *newnode;
    newnode = CreateNode(data);
    newnode->link = header;
    header = newnode;
}

void pop()
{
    struct Node *ptr = header;
    if (ptr == NULL)
    {
        printf("\nEmpty Stack\n");
        return;
    }
    else
    {
        printf("\nPopped item from top\n");
        header = ptr->link;
        free(ptr);
    }
}

int main()
{
    int choice, data;
    while (choice != 4)
    {
        printf("\n1.Push\n2.Pop\n3.Traverse\n4.Exit\n");
        printf("Enter choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Data ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("Exiting");
            return;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return (0);
}
