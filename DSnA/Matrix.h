#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

void SetToMatrix(struct Matrix* m, int i, int j, int val, int mode);
int GetValFromMatrix(struct Matrix m, int i, int j, int mode);
void DisplayMatrix(struct Matrix m, int mode);
void DiagonalMatrixExample();
void LowerTriangularMatrixExample();
void UpperTriangularMatrixExample();
void SymmetricMatrixExample();
void TriDiagonalMatrixExample();
void ToeplitzMatrixExample();
// --------------------------- 
void CreateSparseMatrix(struct Sparse* s);
void DisplaySparseMatrix(struct Sparse s);
struct Sparse AddingSparseMatrix(struct Sparse* s1, struct Sparse* s2);
void CreateCompressedSparse(struct CompressedSparse* s);
void DisplayCompressedSparseMatrix(struct CompressedSparse s);
void SparseMatrixExampleOne();
void SparseMatrixExampleTwo();
void SumTwoSparseMatrixesExample();
void CreatePolynom(struct Poly* poly);
int CalcPolynom(struct Poly poly, int x);
void PolynomialRepresentationExample();
void DisplayPolynom(struct Poly p);
struct Poly AddTwoPolynomials(struct Poly* p1, struct Poly* p2);

// Structure for matrix, A is size and n is used size 
struct Matrix {
	int *A;
	int n;
};

// Structure for sprse matrix
struct Element {
	int i;
	int j;
	int v;
};

// Structure for Sparse matrix with three colum representation
struct Sparse {
	int y; // col
	int x; // row 
	int c; // count
	struct Element *e;
};

// Structure for Sparse matrix with comressed representation 
struct CompressedSparse {
	int* A; // value arr
	int An; // value arr size
	int* IA; // row
	int* JA; // column
	int m;	// matrix size row
	int n;  // matrix size column
};

// Structure that is used in Polyno structure
struct Term {
	int coef;
	int expo;
};

struct Poly
{
	int n;
	struct Term* term;
};

// Sets value to specific matrixes
// mode 0 == diagonal matrix
// mode 1 == lower triangular matrix (row)
// mode 2 == lower triangular matrix (column)
// mode 3 == upper triangular matrix (row)
// mode 4 == upper triangular matrix (colum)
// mode 5 == symetric matrix
// mode 6 == tri-diagonal matrix
// mode 7 == Toeplitz matrix
void SetToMatrix(struct Matrix *m, int i, int j, int val, int mode) {

	if (mode == 0)
	{
		if (i == j)
		{
			m->A[i - 1] = val;
		}
	}
	else if (mode == 1 || mode == 5)
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
	else if (mode == 6)
	{
		// lower
		if (i-j == 1)
		{
			m->A[i-2] = val;
		} // mid
		else if (i - j == 0)
		{
			m->A[m->n-2+i] = val;
		} // upper
		else if (i - j == -1)
		{
			m->A[m->n * 2 - 2 + i] = val;
		}
	}
	else if (mode == 7)
	{
		// upper
		if (i <= j)
		{
			m->A[j - i] = val;
		} // lower
		else if (i > j)
		{
			m->A[m->n + i - j - 1] = val;
		}
	}
}

// Gets value from spesific location in matrix
// mode 0 == diagonal matrix
// mode 1 == lower triangular matrix (row)
// mode 2 == lower triangular matrix (column)
// mode 3 == upper triangular matrix (row)
// mode 4 == upper triangular matrix (colum)
// mode 5 == symetric matrix
// mode 6 == tri-diagonal matrix
// mode 7 == Toeplitz matrix
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
	else if (mode == 5)
	{
		// lower
		if (i >= j)
		{
			return m.A[i * (i - 1) / 2 + j - 1];
		}// upper
		else
		{
			return m.A[j * (j - 1) / 2 + i - 1];
		}
	}
	else if (mode == 6)
	{
		// lower
		if (i - j == 1)
		{
			return m.A[i - 2];
		} // mid
		else if (i - j == 0)
		{
			return m.A[m.n - 2 + i];
		} // upper
		else if (i - j == -1)
		{
			return m.A[m.n * 2 - 2 + i];
		}
	}
	else if (mode == 7) 
	{
		// upper
		if (i <= j)
		{
			return m.A[j - i];
		} // lower
		else if (i > j)
		{
			return m.A[m.n + i - j - 1];
		}
	}
	else
	{
		return 0;
	}
	return 0;
}

// Display Matrix in console
// mode 0 == diagonal matrix
// mode 1 == lower triangular matrix (row)
// mode 2 == lower triangular matrix (column)
// mode 3 == upper triangular matrix (row)
// mode 4 == upper triangular matrix (colum)
// mode 5 == symetric matrix
// mode 6 == tri-diagonal matrix
// mode 7 == toeplitz matrix
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
	else if (mode == 5)
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
					printf("%d ", m.A[j * (j - 1) / 2 + i - 1]);
				}
			}
			printf("\n");
		}
	}
	else if (mode == 6)
	{
		int i, j;
		for (i = 1; i <= m.n; i++)
		{
			for (j = 1; j <= m.n; j++)
			{
				// lower
				if (i - j == 1)
				{
					printf("%d ", m.A[i - 2]);
				} // mid
				else if (i - j == 0)
				{
					printf("%d ", m.A[m.n - 2 + i]);
				} // upper
				else if (i - j == -1)
				{
					printf("%d ", m.A[m.n * 2 - 2 + i]);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	else if (mode == 7) {
		int i, j;
		for (i = 1; i <= m.n; i++)
		{
			for (j = 1; j <= m.n; j++)
			{
				// upper
				if (i <= j)
				{
					printf("%d ", m.A[j - i]);
				} // lower
				else if (i > j)
				{
					printf("%d ", m.A[m.n + i - j - 1]);
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

// Example of symetric matrix
void SymmetricMatrixExample()
{
	/* Symetric matrix
	+---+---+---+---+---+
	| 1 | 1 | 1 | 1 | 1 |
	| 1 | 2 | 2 | 2 | 2 |
	| 1 | 2 | 3 | 3 | 3 |
	| 1 | 2 | 3 | 4 | 4 |
	| 1 | 2 | 3 | 4 | 5 |
	+---+---+---+---+---+ 
	
	Can be stored either in lower or upper triangular matrix and then converted to other side
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
			// we use in this example lower row 
			SetToMatrix(&mp, i, j, val, 5);
		}
	}

	printf("\n");
	DisplayMatrix(mp, 5);
}

// Example of tri-diagonal matrix
void TriDiagonalMatrixExample() {


	/* Tri-diagonal matrix example
	+----+----+----+----+----+
	| 11 | 12 |  0 |  0 |  0 |
	| 21 | 22 | 23 |  0 |  0 |
	|  0 | 32 | 33 | 34 |  0 |
	|  0 |  0 | 43 | 44 | 45 |
	|  0 |  0 |  0 | 45 | 56 |
	+----+----+----+----+----+

		main diagonal = i-j = 0
		lower diagonal = i-j = 1
		upper diagonal = i-j = -1
		other = 0

		|i-j| <= 1

		tri-diagonal mapping:

		+----------+-------------+----------------+--------------+------------+
		| diagonal |    lower    |      main      |     upper    | total size |
		+----------+-------------+----------------+--------------+------------+
		|   value  | 21 32 43 54 | 11 22 33 44 55 |  12 23 34 45 | (0..12) 13 |
		|   A[i]   |  0  1  2  3 |  4  5  6  7  8 |  9  10 11 12 |            |
		+----------+-------------+----------------+--------------+------------+

		Finding value in one dimensional array (lower):
		i-j = 1 --> [i-2] || [j-1]

		Finding value in one dimensional array (main):
		i-j = 0 --> [n-2+i] || [n-2+j]

		Finding value in one dimensional array (upper):
		i-j = -1 --> [2n-1+i-1] 

	*/


	struct Matrix mp;

	printf("Enter size of matrix: ");
	scanf_s("%d", &mp.n);

	mp.A = (int*)malloc(sizeof(int) * mp.n * 3 - 2);

	int i, j, val;

	printf("Enter all elements of matrix: \n");
	for (i = 1; i <= mp.n; i++)
	{
		for (j = 1; j <= mp.n; j++)
		{
			scanf_s("%d", &val);
			SetToMatrix(&mp, i, j, val, 6);
		}
	}

	printf("\n");
	DisplayMatrix(mp, 6);
}

// Example of toeplitz matrix
void ToeplitzMatrixExample() {
	/* Toeplitz matrix example
	+----+----+----+----+----+
	| 1 | 2 | 5 | 7 | 8 |
	| 3 | 1 | 2 | 5 | 7 |
	| 9 | 3 | 1 | 2 | 5 |
	| 4 | 9 | 3 | 1 | 2 |
	| 6 | 4 | 9 | 3 | 1 |
	+----+----+----+----+----+

		upper triangle = i <= j --> j-i 
		lower triangle = i > j --> n+i-j-1


		toeplitz mapping:
		+----------+-----------+----------+------------+
		| toeplitz |    row    |  column  | total size |
		+----------+-----------+----------+------------+
		|   value  | 1 2 5 7 8 |  3 9 4 6 | (0..8) 9   |
		|   A[i]   | 0 1 2 3 4 |  5 6 7 8 |            |
		+----------+-----------+----------+------------+

	*/


	struct Matrix mp;

	printf("Enter size of matrix: ");
	scanf_s("%d", &mp.n);

	mp.A = (int*)malloc(sizeof(int) * (mp.n * 2 - 1));

	int i, j, val;

	printf("Enter all elements of matrix: \n");
	for (i = 1; i <= mp.n; i++)
	{
		for (j = 1; j <= mp.n; j++)
		{
			scanf_s("%d", &val);
			SetToMatrix(&mp, i, j, val, 7);
		}
	}

	printf("\n");
	DisplayMatrix(mp, 7);
}

// Create sparse matrix (3 column representation)
void CreateSparseMatrix(struct Sparse* s) {
	int i;
	printf("Remember, row and column starts from 0!\n");
	printf("Write array dimensions (row, column): ");
	scanf_s("%d%d", &s->y, &s->x);
	printf("Write count of non-zero values (count): ");
	scanf_s("%d", &s->c);
	s->e = (struct Element*)malloc(sizeof(struct Element) * s->c);

	for (i = 0; i < s->c; i++)
	{
		printf("Write %d element (row, column, value): ", i+1);
		scanf_s("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].v);
	}
}

// Create compressed sparse matrix
void CreateCompressedSparse(struct CompressedSparse* s) {
	printf("Write array dimensions (y,x): ");
	scanf_s("%d%d", &s->m, &s->n);
	printf("How many values does this sparse matrix have: ");
	scanf_s("%d",&s->An);
	s->A = (int*)calloc(s->An, sizeof(int));
	s->IA = (int*)calloc(s->An+1, sizeof(int));
	s->JA = (int*)calloc(s->An, sizeof(int));
	int i, val;
	for (i = 0; i < s->An; i++)
	{
		printf("Value %d: ", i+1);
		scanf_s("%d", &s->A[i]);
	}
	for (i = 0; i < s->An; i++)
	{
		printf("Value number %d is %d, what is the column: ", i + 1, s->A[i]);
		scanf_s("%d", &s->JA[i]);
	}
	for (i = 1; i <= s->An; i++)
	{
		printf("How many values are there in row number %d: ", i);
		scanf_s("%d", &val);
		int res = s->IA[i - 1] + val;
		s->IA[i] = res;
	}
}

// Function, that prints sparse matrix to console (3 column representation)
void DisplaySparseMatrix(struct Sparse s) {
	int i, j, k = 0;
	printf("\n");
	for (i = 0; i < s.y; i++)
	{
		for (j = 0; j < s.x; j++)
		{
			if (i == s.e[k].i && j == s.e[k].j)
			{
				printf("%d ", s.e[k++].v);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

// Function, that adds two sparse matrix to and prints result to console (3 column representation)
struct Sparse AddingSparseMatrix(struct Sparse *s1, struct Sparse *s2) {
	if (s1->y != s2->y || s1->x != s2->x)
	{
		printf("Matrixes are not same size!");
	}
	else
	{
		struct Sparse *sp;
		int i=0, j=0, k=0;
		sp = (struct Sparse*)malloc(sizeof(struct Sparse));

		sp->e = (struct Element*)malloc((s1->c + s2->c) * sizeof(struct Element));
		
		while (i < s1->c && j < s2->c)
		{
			if (s1->e[i].i < s2->e[j].i)
			{
				sp->e[k++] = s1->e[i++];
			}
			else if (s1->e[i].i > s2->e[j].i)
			{
				sp->e[k++] = s2->e[j++];
			}
			else
			{
				if (s1->e[i].j < s2->e[j].j)
				{
					sp->e[k++] = s1->e[i++];
				}
				else if (s1->e[i].j > s2->e[j].j)
				{
					sp->e[k++] = s2->e[j++];
				}
				else
				{
					sp->e[k] = s1->e[i++];
					sp->e[k++].v += s2->e[j++].v;
				}
			}
		}
		for (; i < s1->c; i++)
		{
			sp->e[k++] = s1->e[i];
		}
		for (; j < s2->c; j++)
		{
			sp->e[k++] = s2->e[j];
		}
		sp->c = k;
		sp->y = s1->y;
		sp->x = s1->x;
	}
}

// Function, that prints sparse matrix to console (Compressed sparse)
void DisplayCompressedSparseMatrix(struct CompressedSparse s) {
	int i, j, rowCal, ja=0, added = 0;
	printf("\n");
	for (i = 1; i <= s.m; i++)
	{
		added = rowCal = 0;
		rowCal = s.IA[i] - s.IA[i-1];
		for (j = 1; j <= s.n; j++)
		{
			if (s.JA[ja] == j && rowCal > added)
			{
				printf("%d ", s.A[ja]);
				ja++;
				added++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

// Example of sparse matrix, using three column representation
void SparseMatrixExampleOne() {
	/*

	      1   2   3   4   5   6   7   8  
	    +---+---+---+---+---+---+---+---+
	  1 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
	  2 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 7 |
	  3 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
	  4 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
	  5 | 0 | 6 | 0 | 0 | 9 | 0 | 0 | 0 |
	  6 | 0 | 0 | 0 | 0 | 0 | 0 | 4 | 0 |
		+---+---+---+---+---+---+---+---+

		three column representation
		+-----+--------+-------+
		| row | column | value |
		+-----+--------+-------+
		|	6 |      8 |     8 | - first row for column data [row size x colum size x total amount of values]
		|   1 |      3 |     1 |
		|   2 |      1 |     3 |
		|   2 |      8 |     7 |
		|   3 |      6 |     1 |
		|   4 |      1 |     2 |
		|   5 |      2 |     6 |
		|   5 |      5 |     9 |
		|   6 |      7 |     4 |
		+-----+--------+-------+

	*/

	struct Sparse sp;
	CreateSparseMatrix(&sp);
	DisplaySparseMatrix(sp);
}

// Example of sparse matrix, using compressed sparse row
void SparseMatrixExampleTwo() {
	/*
		  1   2   3   4   5   6   7   8
		+---+---+---+---+---+---+---+---+
	  1 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
	  2 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 7 |
	  3 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
	  4 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
	  5 | 0 | 6 | 0 | 0 | 9 | 0 | 0 | 0 |
	  6 | 0 | 0 | 0 | 0 | 0 | 0 | 4 | 0 |
		+---+---+---+---+---+---+---+---+

		compressed sparse rows

		A = [1,3,7,1,2,6,9,4]
		row = [0,1,3,4,5,7,8]
		column = [3,1,8,6,1,2,5,7]

		TESTED WITH NEXT VALUES

		Write array dimensions (y,x): 8 9
		How many values does this sparse matrix have: 8
		Value 1: 3
		Value 2: 8
		Value 3: 10
		Value 4: 4
		Value 5: 2
		Value 6: 6
		Value 7: 9
		Value 8: 5
		Value number 1 is 3, what is the column: 8
		Value number 2 is 8, what is the column: 3
		Value number 3 is 10, what is the column: 6
		Value number 4 is 4, what is the column: 1
		Value number 5 is 2, what is the column: 3
		Value number 6 is 6, what is the column: 4
		Value number 7 is 9, what is the column: 2
		Value number 8 is 5, what is the column: 5
		How many values are there in row number 1: 1
		How many values are there in row number 2: 2
		How many values are there in row number 3: 0
		How many values are there in row number 4: 1
		How many values are there in row number 5: 0
		How many values are there in row number 6: 1
		How many values are there in row number 7: 1
		How many values are there in row number 8: 2

		0 0 0 0 0 0 0 3 0
		0 0 8 0 0 10 0 0 0
		0 0 0 0 0 0 0 0 0
		4 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 2 0 0 0 0 0 0
		0 0 0 6 0 0 0 0 0
		0 9 0 0 5 0 0 0 0
	*/

	struct CompressedSparse cs;
	CreateCompressedSparse(&cs);
	DisplayCompressedSparseMatrix(cs);
}

// Sum where two sparse matrix are added together
void SumTwoSparseMatrixesExample() {
	struct Sparse m1, m2, res;

	CreateSparseMatrix(&m1);
	DisplaySparseMatrix(m1);
	printf("\n");
	CreateSparseMatrix(&m2);
	DisplaySparseMatrix(m2);
	res = AddingSparseMatrix(&m1, &m2);
	DisplaySparseMatrix(res);
}

// Create compressed verison on polynomial function
void CreatePolynom(struct Poly *poly) {
	printf("Number of non-zero terms: ");
	scanf_s("%d", &poly->n);
	poly->term = (struct Term*)malloc(poly->n * sizeof(struct Term));
	int i;
	printf("Enter polynomial terms (coef, expo): \n");
	for (i = 0; i < poly->n; i++)
	{
		printf("Term nuber %d: ", i + 1);
		scanf_s("%d%d", &poly->term[i].coef, &poly->term[i].expo);
	}
}

// Display polynomial function to console
void DisplayPolynom(struct Poly p) {
	int i = 0;
	for (; i < p.n; i++)
	{
		if (i == p.n-1)
		{
			printf("%dx%d", p.term[i].coef, p.term[i].expo);
		}
		else
		{
			printf("%dx%d+", p.term[i].coef, p.term[i].expo);
		}
	}
	printf("\n");
};

// Return calculated value of polynomial, need to insert x value
int CalcPolynom(struct Poly poly, int x) {
	int i, sum = 0;
	for (i = 0; i < poly.n; i++)
	{
		sum += (int)(poly.term[i].coef * pow(x, poly.term[i].expo));
	}
	return sum;
}

// Polynomial Representation 
void PolynomialRepresentationExample() {
	struct Poly pol;
	CreatePolynom(&pol);
	int res = CalcPolynom(pol, 5);
	printf("%d", res);
}

// Ads two polynomial together
struct Poly AddTwoPolynomials(struct Poly *p1, struct Poly *p2) {
	struct Poly rp;
	rp.term = (struct Term*)malloc((p1->n + p2->n) * sizeof(struct Term));

	int i, j, k;
	i = j = k = 0;
	while (i < p1->n && j < p2->n)
	{
		if (p1->term[i].expo > p2->term[j].expo)
		{
			rp.term[k++] = p1->term[i++];
		}
		else if (p1->term[i].expo < p2->term[j].expo)
		{
			rp.term[k++] = p2->term[j++];
		}
		else
		{
			rp.term[k].expo = p1->term[i].expo;
			rp.term[k++].coef = p1->term[i++].coef + p2->term[j++].coef;
		}
		
	}
	for (; i < p1->n; i++)
	{
		rp.term[k++] = p1->term[i];
	}
	for (; j < p2->n; j++)
	{
		rp.term[k++] = p2->term[j];
	}
	rp.n = k;
	return rp;
}

// Example how to add two polynomial together
void AddTwoPolynomialsTogether() {
	struct Poly pol1, pol2, res;
	CreatePolynom(&pol1);
	DisplayPolynom(pol1);
	printf("\n");
	CreatePolynom(&pol2);
	DisplayPolynom(pol2);
	res = AddTwoPolynomials(&pol1, &pol2);
	DisplayPolynom(res);
}