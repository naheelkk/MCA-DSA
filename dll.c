#include <stdio.h>
#include <stdlib.h>

struct Node // creating double linkedlist
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
        newnode->Rlink = header; // right link points to old header
        header = newnode;        // updating header, newnode will become new header
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
        while (ptr->Rlink != NULL) // traversing until right link is null(end)
        {
            ptr = ptr->Rlink;
            pos++;
        }
        pos = pos + 1;
        ptr->Rlink = newnode; // ptr was at end, now ptr's right link points to newnode ->newnode is at the end now
        newnode->Llink = ptr;
        printf("Inserted at Position %d\n", pos);
    }
}

void insertAtAny_secondMethod(int data, int key)
{
    struct Node *newnode = CreateNode(data);
    struct Node *ptr = header;
    if (header == NULL)
        header = newnode;
    else
    {
        // traverse until key is found or ptr is null
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
        // updating links / connecting newnode to the linkedlist
        newnode->Rlink = ptr->Rlink;
        ptr->Rlink = newnode;

        if (ptr->Rlink != NULL)
        {
            ptr->Rlink->Llink = newnode; // updating next node's leftlink by pointing it towards newnode.
        }
        ptr->Rlink = newnode;
    }
}

void insertAtAny(int data, int pos)
{
    // this function would check for the desired position and insert at that position
    struct Node *newnode = CreateNode(data);
    struct Node *ptr = header, *prev;
    int currentPos = 1;
    if (pos == 1)
    {
        newnode->Rlink = header;
        header = newnode;
    }
    else if (pos == 0)
    {
        printf("Node Starts at 1");
    }
    else
    {
        while (ptr != NULL && currentPos < pos)
        {
            prev = ptr;
            ptr = ptr->Rlink;
            currentPos++;
        }
        if (currentPos == pos)
        {
            newnode->Llink = prev;
            newnode->Rlink = ptr;
            prev->Rlink = newnode;
            if (ptr != NULL)
                ptr->Llink = newnode;
        }
        else
        {
            printf("Position not found\n");
            free(newnode);
        }
    }
}

void deleteAtFront()
{
    // deleting header node and makes the next node as header
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
    // traverse to end, delete last node, makes previous's Rlink as null
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
        printf("Deleted At %d", pos);
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
    if (ptr->data == key) // case when key is at head
    {
        header = ptr->Rlink;
        if (header != NULL)
            header->Llink = NULL;
        free(ptr);
        printf("Deleted %d\n", key);
        return;
    }
    // traversing to find key
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
    // key is found, update links to remove
    prev->Rlink = ptr->Rlink;
    if (ptr->Rlink != NULL) // if key is not at the end of the list
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
            insertAtAny_secondMethod(data, key);
            // printf("Data inserted at Position %d", key);
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
            // printf("Deleted key %d", key);
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
