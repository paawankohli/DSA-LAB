#include <stdio.h>
#include <string.h>

int checkPalin(char *start, char *end)
{
	if (start >= end)
		return 1;

	if (*start != *end)
		return 0;

	return checkPalin(start + 1, end - 1);
}


int main()
{
	char a[50] = "";

	printf("Enter string:\n");
	scanf("%s", a);
	
	int bool = checkPalin(a, a + strlen(a) - 1);

	if(bool)
		printf("Palindrome! \n");
	else
		printf("Not Palindrome! \n");
}