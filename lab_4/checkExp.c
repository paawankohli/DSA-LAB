#include <stdio.h>
#include <stdlib.h>
#include "stack_operations.h"

void main()
{
	char exp[25], c, d;
	int i = 0;
	
	stack s;
	s.top = -1;

	printf("\nEnter Expression: ");
	scanf("%s", exp);

	while((c = exp[i++]) != '\0')
	{
		if ( c == '(')
			push(&s, c);
		
		else if ( c == ')')
		{
			d = pop(&s);
			if ( d != '(')
			{
				printf("Invalid");
				break;
			}
		}
	}

	if(empty(&s))
		printf("\nBalanced\n");
	else
		printf("\nNot Balanced\n");		
}