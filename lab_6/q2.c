#include<stdio.h>
#define MAX 6

typedef struct 
{
	int front1,front2;
	int rear1,rear2;
	int arr[MAX];
}twoQ;


void enque1(twoQ* pq)
{
	int item;

	if(pq->rear1 < pq->rear2 - 1)
	{
		printf("\nenter the item:");
		scanf("%d",&item);

		if(pq->front1 == -1)
			pq->front1 = 0;

		pq->rear1++;
		pq->arr[pq->rear1] = item;
	}

	else
		printf("\noverflow 1st queue.\n\n");
}

void enque2(twoQ* pq)
{
	int item;

	if(pq->rear1 < pq->rear2 - 1)
	{
		printf("\nenter the item:");
		scanf("%d",&item);

		if(pq->front2 == MAX)
			pq->front2 = MAX - 1;
		
		pq->rear2--;
		pq->arr[pq->rear2] = item;
	}

	else
		printf("\noverflow 2nd queue.\n\n");

}

void deque1(twoQ* pq)
{
	if(pq->front1 > pq->rear1)
	{
		printf("\nEmpty\n\n");
		return;
	}

	int item = pq->arr[pq->front1];
	
	pq->front1++;
	printf("\n%d dequed\n\n",item);

}

void deque2(twoQ* pq)
{
	if(pq->front1 > pq->rear1)
	{
		printf("\nEmpty\n\n");
		return;
	}

	int item = pq->arr[pq->front2];

	pq->front2--;;
	printf("\n%d dequed\n\n",item);
}

int main()
{
	twoQ q;
	int ch;

	q.front1 = -1;
	q.front2 = MAX;
	q.rear1 = -1;
	q.rear2 = MAX;

	do
    {
        printf("\n1. enque1 \n2. enque2\n3. deque1\n4. deque2\n0. Exit");
        printf("\nEnter Choice 0-3? : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:	enque1(&q);
                	break;

            case 2:	enque2(&q);
                	break;

            case 3:	deque1(&q);
                	break;

      		case 4:	deque2(&q);
      				break;
        }

    }while (ch != 0);

	return 0;
}

