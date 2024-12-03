#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node *header = NULL;
struct Node *CreateNode(int data)
{
struct Node *newnode;
newnode = (struct Node *) malloc(sizeof(struct Node));
newnode -> data = data;
newnode -> link = NULL;
return(newnode);
};
void push(int data)
{
    struct Node *newnode;
    struct Node *ptr = header;
    newnode = CreateNode(data);
    if(header == NULL)
    {
        header = newnode;
    }
    else
    {
        while(ptr -> link != NULL)
        {
            ptr = ptr -> link;
        }
        ptr->link = newnode;
    }

}

void pop()
{
    struct Node *ptr = header;
    if(header == NULL)
    {
        printf("Empty List");
        return;
    }
    else
    {
        header = ptr -> link;
        free(ptr);
    }

}

void traverse()
{
    struct Node *ptr = header;
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }
}


int main()
{
    printf("Hello world!\n");
    push(10);
    push(20);
    push(40);
    traverse();
    pop();
    printf("\n");
    traverse();
    return 0;
}
