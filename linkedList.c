#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*link;
};
struct Node*header=NULL;
struct Node*CreateNode(int data)
{
	struct Node*newnode;
	newnode=malloc(sizeof(struct Node));
	newnode -> data=data;
	newnode -> link=NULL;
	return(newnode);
};

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

void traverseList()
int main()
{
	struct Node*node;
	insertAtFront(10);
	insertAtFront(20);
	return(0);
}
