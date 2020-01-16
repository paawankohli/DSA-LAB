#include <stdio.h>
#include <string.h>

int move(int n, char s, char d, char a)
{
	//move n -1 plates from source to aux
	//move 1 plate from source to source to destin
	//move n - 1 plates from aux to destin using

	if (n == 1)
	{
		printf("Move disk from %c to %c \n", s, d);
		return 1;
	}

	else

	{
		int n1  = move(n - 1, s, a, d);
	
		int n2 = 1; //move 1 disk-
		printf("Move disk from %c to %c \n", s, d);

		int n3 = move(n - 1, a, d, s);

		return n1 + n2 + n3;
	}
}


int main()
{
	int plates;
	char source = 'A', destin = 'C', aux = 'B';

	printf("Enter number of plates on A:");
	scanf("%d", &plates);

	printf("No. of moves: %d \n", move(plates, source, destin, aux));

	
}