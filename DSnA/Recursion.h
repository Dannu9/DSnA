#include <stdio.h>

// Simple tail recursion (n->1)
void TailRecursion(int n) {
	if (n>0)
	{
		printf("%d\n", n);
		TailRecursion(n - 1);
	}
}

// Simple head recursion (1->n)
void HeadRecursion(int n) {
	if (n > 0)
	{		
		HeadRecursion(n - 1);
		printf("%d\n", n);
	}
}

// Summation / Triangual recursion (1+2..+n). 
int TriangualRecursion(int n) 
{
	if (n>0)
	{
		return TriangualRecursion(n - 1) + n;
	}
	return 0;
}

// Power of two recursion. n*n
int PowerOfTwoRecursion(int n) {

	static int x = 0;
	if (n > 0)
	{
		x++;
		return PowerOfTwoRecursion(n - 1) + x;
	}
	return 0;
}