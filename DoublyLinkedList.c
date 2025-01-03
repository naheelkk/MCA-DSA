#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *Rlink;
    struct Node *Llink;
};
struct Node *header = NULL;
struct Node *CreateNode(int data)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->Rlink = NULL;
    newnode->Llink = NULL;
    return (newnode);
};
void insertAtFront(int data)
{
    struct Node *newnode;
    if (header == NULL)
    {
        newnode = CreateNode(data);
        header = newnode;
    }
    else
    {
        newnode = CreateNode(data);
        newnode->Llink = NULL;
        newnode->Rlink = header;
        header = newnode;
    }
}
void insertAtEnd(int data)
{
    struct Node *newnode = CreateNode(data);
    int pos = 1;
    struct Node *ptr = header;
    if (header == NULL)
        header = newnode;
    else
    {
        while (ptr->Rlink != NULL)
        {
            ptr = ptr->Rlink;
            pos++;
        }
        pos = pos + 1;
        ptr->Rlink = newnode;
        newnode->Llink = ptr;
        printf("Inserted at Position %d\n", pos);
    }
}

void insertAtAny(int data, int key)
{
    struct Node *newnode = CreateNode(data);
    struct Node *ptr = header;
    if (header == NULL)
        header = newnode;
    else
    {
        while (ptr != NULL && ptr->data != key)
        {
            ptr = ptr->Rlink;
        }
        if (ptr == NULL)
        {
            printf("Key not found in the list \n");
            free(newnode);
            return;
        }
        newnode->Rlink = ptr->Rlink;
        ptr->Rlink = newnode;
        if (ptr->Rlink != NULL)
        {
            ptr->Rlink->Llink = newnode;
        }
        ptr->Rlink = newnode;
    }
}
void deleteAtFront()
{
    struct Node *ptr = header;
    if (header == NULL)
        printf("Empty List\n");
    else
    {
        header = header->Rlink;
        if (header != NULL)
            header->Llink = NULL;
        free(ptr);
        printf("\nDeleted at Position 1\n");
    }
}

void deleteAtEnd()
{
    struct Node *prev, *ptr = header;
    int pos = 1;
    if (header == NULL)
        printf("Empty List\n");
    else
    {
        while (ptr->Rlink != NULL)
        {
            prev = ptr;
            ptr = ptr->Rlink;
            pos++;
        }
        // pos = pos + 1;
        prev->Rlink = NULL;
        free(ptr);
        printf("Deleted At Node %d", pos);
    }
}

void deleteAtAny(int key)
{
    struct Node *prev = NULL, *ptr = header;
    if (header == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if (ptr->data == key)
    {
        header = ptr->Rlink;
        if (header != NULL)
            header->Llink = NULL;
        free(ptr);
        printf("Deleted %d\n", key);
        return;
    }
    while (ptr != NULL && ptr->data != key)
    {
        prev = ptr;
        ptr = ptr->Rlink;
    }
    if (ptr == NULL)
    {
        printf("Key Not Found\n");
        return;
    }
    prev->Rlink = ptr->Rlink;
    if (ptr->Rlink != NULL)
        ptr->Rlink->Llink = prev;
    free(ptr);
    printf("Deleted key %d.\n", key);
}
void search(int key)
{
    struct Node *ptr = header;
    int pos = 1;
    if (header == NULL)
        printf("List is Empty\n");
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                printf("Position is %d\n", pos);
                return;
            }
            else
            {
                ptr = ptr->Rlink;
                pos++;
            }
        }
        printf("Key Not found\n");
    }
}
void traversal()
{
    struct Node *ptr;
    ptr = header;
    if (header == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->Rlink;
    }
    printf("\n");
}

int main()
{
    int choice, data, key;
    while (choice != 9)
    {
        printf("\n1.Insert at Front\n2.Insert at End\n3.Insert at Any\n4.Delete at End\n5.Delete at First\n6.Delete at Any\n7.Traverse\n8.Search\n9.Exit\n");
        printf("Enter Choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data");
            scanf("%d", &data);
            insertAtFront(data);
            printf("\nData Inserted At Position 1\n");
            break;
        case 2:
            printf("Enter data");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter where do you want to add data");
            scanf("%d", &key);
            printf("Enter data");
            scanf("%d", &data);
            insertAtAny(data, key);
            break;
        case 4:
            deleteAtEnd();
            break;
        case 5:
            deleteAtFront();
            break;
        case 6:
            // traversal();
            printf("What element you want to delete\n");
            scanf("%d", &key);
            deleteAtAny(key);
            break;
        case 7:
            traversal();
            break;
        case 8:
            traversal();
            printf("Enter key to search");
            scanf("%d", &key);
            search(key);
            break;
        case 9:
            return 0;
        default:
            printf("Wrong Choice");
        }
    }
    return 0;
}
