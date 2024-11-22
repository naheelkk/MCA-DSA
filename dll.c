#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *leftLink;
	struct Node *rightLink;
};
struct Node *header = NULL;
struct Node *createNode(int data)
{
	struct Node *newnode;
	newnode = malloc(sizeof(struct Node));
	newnode -> data = data;
	newnode -> leftLink = NULL;
	newnode -> rightLink = NULL;
	return(newnode);
}

void insertAtFront(int data)
{
	struct Node *newnode;
	if(header == NULL)
	{
		newnode = createNode(data);
		header = newnode;	
	}
	else
	{
		newnode = createNode(data);
		newnode -> rightLink = header;
		header -> leftLink = newnode;
		header = newnode;
					
	}
}

void insertAtEnd(int data)
{
	struct Node *newnode;
	struct Node *ptr = header;
	newnode = createNode(data);
	if(header == NULL)
		header = newnode;
	else
	{
		while(ptr -> rightLink != NULL)
			ptr = ptr -> leftLink;
		ptr -> rightLink = newnode;
		newnode -> leftLink = ptr;	
		
	}
}

void traversal()
{
	struct Node *ptr;
	ptr = header;
	while(ptr != NULL)
	{
		printf("%d\t",ptr -> data);
		ptr = ptr -> rightLink;
	}
	printf("\n");
}

int main()
{
	insertAtFront(10);
	insertAtFront(10654);
	insertAtFront(1450);
	insertAtEnd(11);
	traversal();
}
