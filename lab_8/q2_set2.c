#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodeptr;

typedef struct node
{
	int data;
	nodeptr link;
}node;

//with header

void add(nodeptr head,int x)
{
	nodeptr temp=malloc(sizeof(node));
	nodeptr t;

	temp->data=x;
	temp->link=NULL;

	for(t=head;t->link;t=t->link);
		t->link=temp;
}

void init(nodeptr* head)
{
	nodeptr temp=malloc(sizeof(node));
	temp->data=-1;
	temp->link=NULL;
	
	*head=temp;
}

nodeptr set_union(nodeptr a,nodeptr b)
{
	int i,flag=1;
	nodeptr c,at,bt;
	init(&c);
	
	at=a->link;
	bt=b->link;
	
	for(;at;at=at->link)
		add(c,at->data);
	
	for(;bt;bt=bt->link)
	{
		for(at=a->link;at;at=at->link)
			if(bt->data==at->data)
			{
				flag=0;
				break;
			}

		if(flag)
			add(c,bt->data);
		
		flag=1;
	}
	return c;
}

nodeptr intersection(nodeptr a,nodeptr b)
{
	nodeptr c,at;
	at=a->link;

	init(&c);

	for(b=b->link;b;b=b->link)
	{
		for(;at;at=at->link)
			if(b->data==at->data)
			{
				add(c,b->data);
				break;
			}
		
		at=a->link;
	}
	return c;
}

void display(nodeptr a)
{
	printf("\n");
	a=a->link;

	for(;a;a=a->link)
		printf("\t%d",a->data);
}

int main()
{
	nodeptr a,b,u,in;
	int n,m,i,t;

	init(&a);
	init(&b);

	printf("\nEnter number elements of first set");
	scanf("%d",&n);

	printf("\nEnter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		add(a,t);
	}
	
	printf("\nEnter number elements of second set");
	scanf("%d",&m);

	printf("\nEnter elements");
	for(i=0;i<m;i++)
	{
		scanf("%d",&t);
		add(b,t);
	}

	display(a);
	display(b);
	
	u=set_union(a,b);
	in=intersection(a,b);
	
	display(u);
	display(in);

}