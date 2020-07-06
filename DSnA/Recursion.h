#include <stdio.h>

void TailRecursion(int n);
void HeadRecursion(int n);
int TriangualRecursion(int n);
int FactorialRecursion(int n);
int PowerOfTwoRecursion(int n);
int PowerRecursion(int m, int n);
void TreeRecursion(int n);
void IndirectRecusrionB(int n);
void IndirectRecusrionC(int n);
void IndirectRecusrionA(int n);
int NestedRecursion(int n);
double TaylorSeriesRecursion(int x, int n);
double TaylorSeriesRecursionHornersRule(int x, int n);
double TaylorSeriesGeometricSeries(int x, int n);
double TaylorSeriesCosSeries(double x, int n);
double TaylorSeriesSinSeries(double x, int n);
int FibonacciRecursio(int n);

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

// Power of two recursion, n*n (static)
int PowerOfTwoRecursion(int n) {
	static int x = 0;
	if (n > 0)
	{
		x++;
		return PowerOfTwoRecursion(n - 1) + x;
	}
	return 0;
}

// Power recursion, m is base and n is power
int PowerRecursion(int m, int n) {
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return PowerRecursion(m, n - 1) * m;
	}
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

// Talyor series recursion, x is power and n is count of iterations
// Calculation is e^x and n gives more accurasy to calculation.
// Time = O(n^2)
double TaylorSeriesRecursion(int x, int n)
{
	static double pow = 1, fac = 1;
	double result;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		result = TaylorSeriesRecursion(x, n - 1);
		pow *= x;
		fac *= n;
		return result + pow / fac;
	}
}

// Talyor series recursion, x is power and n is count of iterations
// Time = O(n)
double TaylorSeriesRecursionHornersRule(int x, int n) {
	static double r;
	if (n == 0)
	{
		return r;
	}
	r = 1 + x *r / n;
	return TaylorSeriesRecursionHornersRule(x, n - 1);
}

// Taylor Series for Geometric series
// 1 + x + x^2 .... n is iterations count
double TaylorSeriesGeometricSeries(int x, int n) {

	static double r;
	if (n == 0)
	{
		return r;
	}
	r = 1 + x * r;
	return TaylorSeriesGeometricSeries(x,n-1);
}

// Taylor Series for Cos calculation. x is in radians &
// n must be even value! If n is odd, it will return -inf
double TaylorSeriesCosSeries(double x, int n) {
	static double r = 1;
	if (n > 0)
	{
		r = 1 - ((x * x * r) / (n * (n - 1.0)));
		return TaylorSeriesCosSeries(x, n - 2);
	}
	else return r;
}

// Taylor Series for Sin calculation. x is in deg &
// n must be odd value! If n is even, it will return -inf
double TaylorSeriesSinSeries(double x, int n) {
	double s = 1;
	x = x * 3.14159 / 180; // DEG --> RAD
	double t = x;
	s = x;
	for (int i = 1; i <= n; i++)
	{
		t = (t * (-1) * x * x) / ((double)2 * i * ((double)2 * i + (double)1));
		s = s + t;
	}
	return s;
}

// Fibonacci series. n is number of iterations 
int FibonacciRecursio(int n) {
	if (n <= 1)
	{
		return n;
	}
	return FibonacciRecursio(n - 2) + FibonacciRecursio(n - 1);
}
