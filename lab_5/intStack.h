#define MAX 50
#define true 1
#define false 0

typedef struct
{
	int item[MAX];
	int top;
}stack;

int isEmpty(stack *ps)
{
	if(ps->top == -1)
		return true;
	else
		return false;	
}

void push(stack* ps, int x)
{
	if(ps->top != MAX - 1)
		ps->item[++(ps->top)] = x;
}

int pop(stack* ps)
{
	if(!isEmpty(ps))
		return ps->item[(ps->top)--];
}

int top(stack* ps) 
{ 
	if(!isEmpty(ps))
		return ps->item[ps->top]; 
} 
