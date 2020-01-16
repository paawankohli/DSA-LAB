#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node
{
	int data;
	nptr next;
}node;

nptr createNode(int x)
{
	nptr temp = (nptr)malloc(sizeof(node));
	temp -> data = x;
	temp -> next = NULL;

	return temp;
}

nptr insert(nptr head, int x)
{
	if (head == NULL)
	{
		nptr newNode = createNode(x);
		newNode -> next = newNode;
		return newNode;
	}

	nptr curr = head;
	while(curr -> next != head)
		curr = curr -> next;

	curr -> next = createNode(x);
	curr -> next -> next = head;

	return head;
}

void display(nptr head)
{
	nptr curr = head;

	while(curr -> next != head)
	{
		printf("%d --> ", curr -> data);
		curr = curr -> next;
	}

	printf("%d\n", curr -> data);
}

int main()
{
	nptr head = NULL;

	printf("1. Insert 2. Display 0. Exit\n");
	int ch, ele;

	do
	{
		printf("Command: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: 
					printf("Element: ");
					scanf("%d", &ele);
					head = insert(head, ele);
					break;

			case 2:	display(head);
					break;
		}

	}while(ch != 0);
}