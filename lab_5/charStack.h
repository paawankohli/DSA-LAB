#define MAX 50
#define true 1
#define false 0

typedef struct
{
	char item[MAX];
	int top;
}stack;

int isEmpty(stack *ps)
{
	if(ps->top == -1)
		return true;
	else
		return false;	
}

void push(stack* ps, char x)
{
	if(ps->top != MAX - 1)
		ps->item[++(ps->top)] = x;
}

char pop(stack* ps)
{
	if(!isEmpty(ps))
		return ps->item[(ps->top)--];
}

char top(stack* ps) 
{ 
	if(!isEmpty(ps))
		return ps->item[ps->top]; 
}