#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter no. of elements: ");
	scanf("%d", &n);

	int* arr = calloc(n, sizeof(int));

	printf("Enter data: ");

	for(int i = 0 ; i < n ; i++)
		scanf("%d", arr + i);

	printf("\nForward direction: ");
	for(int i = 0 ; i < n ; i++)
		printf("%d  ", *(arr + i));

	printf("\nBackward direction: ");
	for(int i = n - 1 ; i >= 0 ; i--)
		printf("%d  ", *(arr + i));

	printf("\n");
}