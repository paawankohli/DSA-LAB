#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include "charStack.h"

//                          		 :::: infix expression to postfix ::::

int isOperand(char ch) 		// function to check if character is operand 
{ 
	return (ch >= 'a' && ch <= 'z');
} 

int prec(char ch) 			// return precedence of a given operator  
{ 
	if (ch == '+' || ch == '-')
		return 1; 

	if (ch == '*' || ch == '/')
		return 2; 

	if (ch == '^')
		return 3;  
	
	return -1; 
} 

int infixToPostfix(char* exp, char* ans) 
{ 
	int i, k = 0; 

	stack s;

	for (i = 0 ; exp[i] != '\0' ; i++) 
	{ 
	
		if (isOperand(exp[i]))  	// if operand, add it to output. 
			ans[k++] = exp[i]; 
		
		else if (exp[i] == '(')   	// if ( push to stack
			push(&s, exp[i]); 
		
		else if (exp[i] == ')') 	// if ), pop and output from the stack until an ( is encountered
		{ 
			while (!isEmpty(&s) && top(&s) != '(') 
				ans[k++] = pop(&s); 
			
			pop(&s);  // pop ( 
		} 
		
		else  			// if an operator is encountered then pop all operators of higher precedence
		{ 
			while ( !isEmpty(&s) && prec(exp[i]) <= prec(top(&s)) ) 
				ans[k++] = pop(&s); 
			
			push(&s, exp[i]); 
		} 
	} 

	while (!isEmpty(&s)) 			// pop all the operators from the stack 
		ans[k++] = pop(&s); 

	ans[k- 1] = '\0';  
} 

int main() 
{ 
	char exp[100], ans[100];
	scanf("%s", exp);	
	
	infixToPostfix(exp, ans);

	printf("%s \n", ans); 
} 