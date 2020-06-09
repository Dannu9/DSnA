#include <stdio.h>
void TailRecursion(int);
void HeadRecursion(int n);

// Simple tail recursion (n->1)
void TailRecursion(int n) {
	if (n>0)
	{
		printf("%d", n);
		TailRecursion(n - 1);
	}
}

// Simple head recursion (1->n)
void HeadRecursion(int n) {
	if (n > 0)
	{		
		HeadRecursion(n - 1);
		printf("%d", n);
	}
}