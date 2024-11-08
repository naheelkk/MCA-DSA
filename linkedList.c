#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*link;
};
struct Node*header = NULL;
struct Node*CreateNode(int data)
{
	struct Node*newnode;
	newnode=malloc(sizeof(struct Node));
	newnode -> data = data;
	newnode -> link = NULL;
	return(newnode);
}

void traversal()
{
	struct Node*ptr;
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
	struct Node*newnode;
	newnode=CreateNode(data);
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
	struct Node*newnode;
	newnode=CreateNode(data);

	if(header == NULL)
		header = newnode;
	else
	{	struct Node*ptr = header;		
		while(ptr -> link != NULL)
		ptr = ptr -> link;
		ptr -> link = newnode;
	}
}

int main()
{
	struct Node*node;
	insertAtFront(10);
	insertAtFront(20);
	insertAtFront(90);
	insertAtEnd(100);
	traversal();

	return(0);
}
