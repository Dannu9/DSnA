#include <stdio.h>
void DrawPascalsTriangleToConsole(int n);

// Draws Pascal's triangle to console.
// n is number of rows to print
void DrawPascalsTriangleToConsole(int n) {
	int  mul = 1, space, i, j;
	for (i = 0; i < n; i++)
	{
		for (space = 1; space <= n-i; space++)
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == 0)
			{
				mul = 1;
			}
			else
			{
				mul = mul * (i - j + 1) / j;				
			}	
			printf("%4d", mul);
		}
		printf("\n");
	}
}
