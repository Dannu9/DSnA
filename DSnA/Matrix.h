#include <stdio.h>
#include <stdlib.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

void SetToMatrix(struct Matrix* m, int i, int j, int val, int mode);
int GetValFromMatrix(struct Matrix m, int i, int j, int mode);
void DisplayMatrix(struct Matrix m, int mode);
void DiagonalMatrixExample();
void LowerTriangularMatrixExample();
void UpperTriangularMatrixExample();

// Structure for matrix, A is size and n is used size 
struct Matrix {
	int *A;
	int n;
};

// Sets value to specific matrixes
// mode 0 == diagonal matrix
// mode 1 == lower triangular matrix (row)
// mode 2 == lower triangular matrix (column)
// mode 3 == upper triangular matrix (row)
// mode 4 == upper triangular matrix (colum)
void SetToMatrix(struct Matrix *m, int i, int j, int val, int mode) {

	if (mode == 0)
	{
		if (i == j)
		{
			m->A[i - 1] = val;
		}
	}
	else if (mode == 1)
	{
		if (i >= j)
		{
			m->A[i * (i - 1) / 2 + j - 1] = val;
		}
	}
	else if (mode == 2 )
	{
		if (i >= j)
		{
			m->A[m->n * (j - 1) +(j - 2) * (j - 1) / 2 + i - j] = val;
		}
	}
	else if (mode == 3)
	{
		if (i <= j)
		{
			m->A[m->n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i] = val;
		}
	}
	else if (mode == 4)
	{
		if (i <= j)
		{
			m->A[j * (j - 1) / 2 + i - 1] = val;
		}
	}
}

// Gets value from spesific location in matrix
// mode 0 == diagonal matrix
// mode 1 == lower triangular matrix (row)
// mode 2 == lower triangular matrix (column)
// mode 3 == upper triangular matrix (row)
// mode 4 == upper triangular matrix (colum)
int GetValFromMatrix(struct Matrix m, int i, int j, int mode) {

	if (mode == 0)
	{
		if (i == j)
		{
			return m.A[i - 1];
		}
		else
		{
			return 0;
		}
	}
	else if (mode == 1)
	{
		if (i >= j)
		{
			return m.A[i * (i - 1) / 2 + j - 1];
		}
		else
		{
			return 0;
		}
	}
	else if (mode == 2)
	{
		if (i >= j)
		{
			return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
		}
		else
		{
			return 0;
		}
	}
	else if (mode == 3)
	{
		if (i <= j)
		{
			return m.A[m.n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i];
		}
		else
		{
			return 0;
		}
	}
	else if (mode == 4)
	{
		if (i <= j)
		{
			return m.A[j * (j - 1) / 2 + i - 1];
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

// Display Matrix in console
// mode 0 == diagonal matrix
// mode 1 == lower triangular matrix (row)
// mode 2 == lower triangular matrix (column)
// mode 3 == upper triangular matrix (row)
// mode 4 == upper triangular matrix (colum)
void DisplayMatrix(struct Matrix m, int mode) {

	if (mode == 0)
	{
		int i, j;
		for (i = 0; i < m.n; i++)
		{
			for (j = 0; j < m.n; j++)
			{
				if (i == j)
				{
					printf("%d ", m.A[i]);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	else if (mode == 1)
	{
		int i, j;
		for (i = 1; i <= m.n; i++)
		{
			for (j = 1; j <= m.n; j++)
			{
				if (i >= j)
				{
					printf("%d ", m.A[i * (i - 1) / 2 + j - 1]);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	else if (mode == 2)
	{
		int i, j;
		for (i = 1; i <= m.n; i++)
		{
			for (j = 1; j <= m.n; j++)
			{
				if (i >= j)
				{
					printf("%d ", m.A[m.n * (j - 1) +(j - 2) * (j - 1) / 2 + i - j]);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	else if (mode == 3)
	{
		int i, j;
		for (i = 1; i <= m.n; i++)
		{
			for (j = 1; j <= m.n; j++)
			{
				if (i <= j)
				{
					printf("%d ", m.A[m.n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i]);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	else if (mode == 4)
	{
		int i, j;
		for (i = 1; i <= m.n; i++)
		{
			for (j = 1; j <= m.n; j++)
			{
				if (i <= j)
				{
					printf("%d ", m.A[j * (j - 1) / 2 + i - 1]);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
}

// Example of Diagond Matrix
void DiagonalMatrixExample() {

	/* DiagondMatrix
	+---+---+---+---+---+
	| 9 | 0 | 0 | 0 | 0 |
	| 0 | 8 | 0 | 0 | 0 |
	| 0 | 0 | 7 | 0 | 0 |
	| 0 | 0 | 0 | 6 | 0 |
	| 0 | 0 | 0 | 0 | 5 |
	+---+---+---+---+---+ */

	struct Matrix m;
	m.n = 5;
	m.A = (int*)malloc(sizeof(int) * m.n);
	SetToMatrix(&m, 1, 1, 9, 0);
	SetToMatrix(&m, 2, 2, 8, 0);
	SetToMatrix(&m, 3, 3, 7, 0);
	SetToMatrix(&m, 4, 4, 6, 0);
	SetToMatrix(&m, 5, 5, 5, 0);

	printf("%d\n", GetValFromMatrix(m, 2, 2, 0));

	DisplayMatrix(m, 0);

}

// Example of lower triangular matrix, with row- and column-major mapping
void LowerTriangularMatrixExample() {

	/* lower triangular matrix
	 j >	+----+----+----+----+----+
	 i		| 11 |  0 |  0 |  0 |  0 |   
	 v		| 21 | 22 |  0 |  0 |  0 |	
	 		| 31 | 32 | 33 |  0 |  0 | 
			| 41 | 42 | 43 | 44 |  0 |
			| 51 | 52 | 53 | 54 | 55 |
			+----+----+----+----+----+

			row major mapping: 
			+-------+-------+-------+----------+-------------+-----------------+------------+
			|  row  | row 1 | row 2 |   row 3  |    row 4    |      row 5      | total size |
			+-------+-------+-------+----------+-------------+-----------------+------------+
			| value |    11 | 21 22 | 31 32 33 | 41 42 43 44 | 51 52 53 54 55  | (0..14) 15 |
			| A[i]  |     0 | 1   2 | 3  4  5  |  6  7  8  9 | 10 11 12 13 14  |            |
			+-------+-------+-------+----------+-------------+-----------------+------------+

			Finding value in one dimensional array (row):
			[i(i-1) / 2] + j - 1
			
			example: 
			{4,3} = 4*(4-1) / 2 = 6
			j-1 = 2
			6 + 2 = 8 
			{4,3} = A[8]

			column major mapping:
			+--------+----------------+-------------+------------+----------+----------+------------+
			| column |    column 1    |  column 2   |  column 3  | column 4 | column 5 | total size |
			+--------+----------------+-------------+------------+----------+----------+------------+
			| value  | 11 21 31 41 51 | 22 32 42 51 |  33 43 53  |    44 54 |     55   | (0..14) 15 |
			| A[i]   | 0  1  2  3  4  |  5  6  7  8 |   9 10 11  |    12 13 |     14   |            |
			+--------+----------------+-------------+------------+----------+----------+------------+

			Finding value in one dimensional array (column):
			[n(j-1) - (j-2)(j-1)/2 ] + (i-j)

			example:
			{5,3} and n = 5 (5x5 matrix)

			n(j-1) = 5*(3-1) = 10
			(j-2)(j-1)/2 = (1)(2)/2 = 1
			(i-j) = 2
			10-1+2=11

			{5,3} = A[11]
	*/
	struct Matrix mp;

	printf("Enter size of matrix: ");
	scanf_s("%d", &mp.n);

	mp.A = (int*)malloc(sizeof(int) * mp.n * (mp.n + 1 / 2));

	int i, j, val;

	printf("Enter all elements of matrix: \n");
	for (i = 1; i <= mp.n ; i++)
	{
		for ( j = 1; j <= mp.n; j++)
		{
			scanf_s("%d", &val);
			SetToMatrix(&mp, i, j, val, 2);
			// row
			// SetToMatrix(&mp, i, j, val, 1);
		}
	}
	printf("\n");
	DisplayMatrix(mp, 2);
	// row
	// DisplayMatrix(mp, 1);
}

// Example of upper triangular matrix, with row- and column-major mapping
void UpperTriangularMatrixExample() {

	/* lower triangular matrix
	 j >	+----+----+----+----+----+
	 i		| 11 | 12 | 13 | 14 | 15 |
	 v		|  0 | 22 | 23 | 24 | 25 |
			|  0 |  0 | 33 | 34 | 35 |
			|  0 |  0 |  0 | 44 | 45 |
			|  0 |  0 |  0 |  0 | 55 |
			+----+----+----+----+----+

			column major mapping:
			+--------+----------+----------+-------------+-----------------+-----------------+------------+
			| column | column 1 | column 2 |   column 3  |    column 4     |      column 5   | total size |
			+--------+----------+----------+-------------+-----------------+-----------------+------------+
			| value  |    11    |   12 22  |  13  23  33 |  14  24  34  44 | 15 25 35 45 55  | (0..14) 15 |
			| A[i]   |     0    |    1  2  |  3   4   5  |   6   7   8   9 | 10 11 12 13 14  |            |
			+--------+----------+----------+-------------+-----------------+-----------------+------------+

			Finding value in one dimensional array (column):
			[j(j - 1) / 2 + i - 1]

			example:
			{1,4} = 4*(4-1) / 2 = 6
			i-1 = 0
			6 + 0 = 6
			{1,4} = A[6]

			row major mapping:
			+--------+----------------+-------------+------------+----------+----------+------------+
			| row    |     row 1      |    row 2    |    row 3   |   row 4  |   row 5  | total size |
			+--------+----------------+-------------+------------+----------+----------+------------+
			| value  | 11 12 13 14 15 | 22 23 24 25 |  33 34 35  |    44 45 |     55   | (0..14) 15 |
			| A[i]   | 0  1  2  3  4  |  5  6  7  8 |   9 10 11  |    12 13 |     14   |            |
			+--------+----------------+-------------+------------+----------+----------+------------+

			Finding value in one dimensional array (row):
			[n(i-1) - (i-2)(i-1)/2 ] + (j-i)

			example:
			{2,4} and n = 5 (5x5 matrix)

			n(i-1) = 5*(2-1) = 5
			(i-2)(i-1)/2 = (0)(1)/2 = 0
			(j-i) = 2 
			5-0+2=7

			{2,4} = A[7]
	*/
	struct Matrix mp;

	printf("Enter size of matrix: ");
	scanf_s("%d", &mp.n);

	mp.A = (int*)malloc(sizeof(int) * mp.n * (mp.n + 1 / 2));

	int i, j, val;

	printf("Enter all elements of matrix: \n");
	for (i = 1; i <= mp.n; i++)
	{
		for (j = 1; j <= mp.n; j++)
		{
			scanf_s("%d", &val);
			SetToMatrix(&mp, i, j, val, 4);
			// row
			// SetToMatrix(&mp, i, j, val, 3);
		}
	}
	printf("\n");
	DisplayMatrix(mp, 4);
	// row
	// DisplayMatrix(mp, 3);
}