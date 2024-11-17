#include<stdio.h>
#include<stdlib.h>
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
	newnode -> data = data;
	newnode -> link = NULL;
	return(newnode);
}

void traversal()
{
	struct Node *ptr;
	ptr = header;
	while(ptr != NULL)
	{
		printf("%d\t",ptr -> data);
		ptr = ptr -> link;
	}
	printf("\n");
}

void insertAtFront(int data)
{
	struct Node *newnode;
	newnode = CreateNode(data);
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}
}

void insertAtEnd(int data)
{
	struct Node *newnode;
	newnode = CreateNode(data);

	if(header == NULL)
		header = newnode;
	else
	{	struct Node*ptr = header;
		while(ptr -> link != NULL)

		ptr = ptr -> link;
		ptr -> link = newnode;
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
	if(header == NULL)
		printf("List is Empty\n");
	else
	{
		header = header -> link;
		free(ptr);
	}
}

void deleteAtEnd()
{
	if(header == NULL)
		printf("List is Empty");
	else
	{
		struct Node *ptr1 = header;
		struct Node *ptr2;
		while(ptr1 -> link != NULL)
		{
			ptr2 = ptr1;
			ptr1 = ptr1 -> link;
		}
		ptr2 -> link = NULL;
		free(ptr1);
	}
}
void deleteAtAny(int key)
{
    if(header == NULL)
        printf("List is empty");
   struct Node *ptr1 = header, *ptr2 = NULL;
   if(ptr1 -> data == key)
   {
       header = ptr1 -> link;
       free(ptr1);
       return;
   }
   while(ptr1 != NULL & ptr1 -> data != key)
   {
       ptr2 = ptr1;
       ptr1 = ptr1 -> link
       ;
   }
   if(ptr1 == NULL)
        printf("Key not found");
    ptr2 -> link = ptr1 -> link;
   free(ptr1);
}

int main()
{
	struct Node*node;
	insertAtFront(10);
	insertAtFront(20);
	insertAtFront(90);
	insertAtEnd(100);
	traversal();
	deleteAtFront();
	traversal();
	deleteAtEnd();
	traversal();
	deleteAtAny(90);
	traversal();

	return(0);
}
