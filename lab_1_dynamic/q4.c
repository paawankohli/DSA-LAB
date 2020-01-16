#include<stdio.h>
#include<stdlib.h>

int add(int *arr, int size)
{
	int sum = 0;

	for(int i = 0 ; i < size ; i++)
		sum += arr[i];

	return sum;
}

int main()
{
	int n;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	int *a = calloc(n, sizeof(int));

	printf("Enter elements: ");
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);

	printf("Sum = %d", add(a, n));

}