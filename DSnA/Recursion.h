#include <stdio.h>

void TailRecursion(int n);
void HeadRecursion(int n);
int TriangualRecursion(int n);
int PowerOfTwoRecursion(int n);
void TreeRecursion(int n);
void IndirectRecusrionB(int n);
void IndirectRecusrionC(int n);
void IndirectRecusrionA(int n);
int NestedRecursion(int n);

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

// Summation / Triangual recursion 
int TriangualRecursion(int n) 
{
	if (n == 0)
	{
		return 0;
	}
	else 
	{
		return TriangualRecursion(n - 1) + n;
	}
}

// Factorial recursion
int FactorialRecursion(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return FactorialRecursion(n - 1) * n;
	}
}

// Power of two recursion, n*n (Static)
int PowerOfTwoRecursion(int n) {
	static int x = 0;
	if (n > 0)
	{
		x++;
		return PowerOfTwoRecursion(n - 1) + x;
	}
	return 0;
}

// Tree recursion 
void TreeRecursion(int n) {
	if (n>0)
	{
		printf("%d", n);
		TreeRecursion(n - 1);
		TreeRecursion(n - 1);
	}
}

//Indirect recursion A
void IndirectRecusrionA(int n) {
	if (n > 0)
	{
		printf("\nA:%d", n);
		IndirectRecusrionB(n - 3);
	}
}

//Indirect recursion B
void IndirectRecusrionB(int n) {
	if (n > 0)
	{
		printf("\nB:%d", n);
		IndirectRecusrionC(n/2);
	}
}

//Indirect recursion C
void IndirectRecusrionC(int n) {
	if (n > 0)
	{
		printf("\nC:%d", n);
		IndirectRecusrionA(n-1);
	}
}

// Nested recursion
int NestedRecursion(int n) 
{
	if (n>100)
	{
		return n - 10;
	}
	return NestedRecursion(NestedRecursion(n + 11));
}

