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
    newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->link = NULL;
    return (newnode);
}

void traversal()
{
    struct Node *ptr;
    ptr = header;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void insertAtFront(int data)
{
    struct Node *newnode;
    newnode = CreateNode(data);
    if (header == NULL)
    {
        header = newnode;
    }
    else
    {
        newnode->link = header;
        header = newnode;
    }
}

void insertAtEnd(int data)
{
    struct Node *newnode;
    newnode = CreateNode(data);

    if (header == NULL)
        header = newnode;
    else
    {
        struct Node *ptr = header;
        while (ptr->link != NULL)

            ptr = ptr->link;
        ptr->link = newnode;
    }
}

void insertAtAny(int data, int position)
{
    struct Node *newnode, *ptr, *prev;
    newnode = CreateNode(data);
    if (position == 0)
    {
        newnode->link = header;
        header = newnode;
        return;
    }
    ptr = header;
    int currentPos = 0;
    while (ptr != NULL && currentPos < position)
    {
        prev = ptr;
        ptr = ptr->link;
        currentPos++;
    }
    if (ptr == NULL && currentPos != position)
    {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->link = ptr;
    prev->link = newnode;
}

void deleteAtFront()
{
    struct Node *ptr = header;
    if (header == NULL)
        printf("List is Empty\n");
    else
    {
        header = header->link;
        free(ptr);
    }
}

void deleteAtEnd()
{
    if (header == NULL)
        printf("List is Empty");
    else
    {
        struct Node *ptr1 = header;
        struct Node *ptr2;
        while (ptr1->link != NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->link;
        }
        ptr2->link = NULL;
        free(ptr1);
    }
}
void deleteAtAny(int key)
{
    if (header == NULL)
        printf("List is empty");
    struct Node *ptr1 = header, *ptr2 = NULL;
    if (ptr1->data == key)
    {
        header = ptr1->link;
        free(ptr1);
        return;
    }
    while (ptr1 != NULL & ptr1->data != key)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->link;
    }
    if (ptr1 == NULL)
        printf("Key not found");
    ptr2->link = ptr1->link;
    free(ptr1);
}
void search(int key)
{
    struct Node *ptr = header;
    int position = 0;
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                printf("\nPosition is %d\n", position + 1);
                return;
            }
            ptr = ptr->link;
            position++;
        }
        printf("Key not found\n");
    }
}

int main()
{
    int choice, data, key;
    while (choice != 9)
    {
        printf("1.Insert at Front\n2.Insert at End\n3.Insert at Any\n4.Delete at End\n5.Delete at First\n6.Delete at Any\n7.Traverse\n8.Search\n9.Exit\n");
        printf("Enter Choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data");
            scanf("%d", &data);
            insertAtFront(data);
            break;
        case 2:
            printf("Enter data");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter position");
            int pos;
            scanf("%d", &pos);
            printf("Enter data");
            scanf("%d", &data);
            insertAtAny(data, pos);
            break;
        case 4:
            deleteAtEnd();
            printf("Success");
            break;
        case 5:
            deleteAtFront();
            printf("Success");
            break;
        case 6:
            traversal();
            printf("What do you want to delete");
            scanf("%d", &pos);
            deleteAtAny(pos);
            break;
        case 7:
            traversal();
            break;
        case 8:
            printf("Enter a key to search");
            scanf("%d", &key);
            search(key);
            break;
        case 9:
            return 0;
        default:
            printf("Wrong Choice");
            break;
        }
    }
    struct Node *node;
    return 0;
}
