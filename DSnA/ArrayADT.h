#include <stdio.h>
#include <stdlib.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

// Run TestArrayMain func! 

void TestArrayMain();
void DisplayArray(struct TestArray arr);
void AddToArray(struct TestArray* arr, int value);
void InsertToArray(struct TestArray* arr, int value, int index);
void DeleteFromArray(struct TestArray* arr, int index);
void LinearSearch(struct TestArray arr, int val);
void SimpleSelectionSort(struct TestArray* arr);
void BinarySearch(struct TestArray arr, int val);
void GetValueFromIndex(struct TestArray arr, int index);
void SetValue(struct TestArray* arr, int index, int val);
void PrintMaxVal(struct TestArray arr);
void PrintMinVal(struct TestArray arr);
void PrintSumVal(struct TestArray arr);


struct TestArray {
	int* A;
	int size; // Array size
	int length; // number of elements in array
};

// Prints array to console
void DisplayArray(struct TestArray arr) {
	int i;
	printf("\nElements:\n");
	for (i = 0; i < arr.length; i++)
	{
		printf("%d\n", arr.A[i]);
	}
}

// Adds a value end of the array, if it's possible. 
void AddToArray(struct TestArray *arr, int value) {
	// Adding is possible
	if (arr->length < arr->size)
	{
		arr->A[arr->length] = value;
		arr->length++;
		printf("Value was successfully added!\n");
	}
	else
	{
		printf("Array is full, maybe delete something?\n");
	}
}

// Adds value to a spesific index in the array.
void InsertToArray(struct TestArray* arr, int value, int index) {

	// Check if the index value is valid
	if (index>0 && index <=arr->length)
	{
		int i;
		for (i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = value;
		arr->length++;
		printf("Value was successfully added!\n");
	}
	else
	{
		printf("Index value was smaller than zero or too large. Check array length size!\n");
	}
}

// Delete value from specific index. Printf will return deleted value and index
void DeleteFromArray(struct TestArray* arr, int index) {

	if (index >= 0 && index < arr->length)
	{
		int x = 0, i;
		x = arr->A[index];
		for (i = index; i < arr->length-1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
		printf("Value %d was deleted from index %d\n",x,index);
	}
	else
	{
		printf("Value was not found, check index value!\n");
	}
}

// Linear Search. Search value from first index to last.
// Prints only first value, if there is multiple copies of same value in array! 
void LinearSearch(struct TestArray arr, int val) {
	int i;

	for (i = 0; i < arr.length; i++)
	{
		if (val == arr.A[i])
		{
			printf("Value %d was found from array index %d\n", val, i);
			return;
		}
	}
	printf("Value was not found!\n");
}

// Binary Search. Uses SelectionSort also, to sort the array in right form.
void BinarySearch(struct TestArray arr, int val) {
	int l = 0, mid, h = arr.length-1, res;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (val == arr.A[mid])
		{
			printf("Value %d was found from array index %d\n", val, mid);
			return;
		}
		else if (val < arr.A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("Value was not found from this array\n");
}

// Selection sort, which is used in ArrayADR.h to get test array sorted. 
void SimpleSelectionSort(struct TestArray* arr) {

	for (int i = 0; i < arr->length - 1; i++)
	{
		int Imin = i;
		for (int j = i + 1; j < arr->length; j++)
		{
			if (arr->A[j] < arr->A[Imin])
			{
				Imin = j;
			}
		}
		int temp = arr->A[Imin];
		arr->A[Imin] = arr->A[i];
		arr->A[i] = temp;
	}
}

// Print value from specific index of array 0...n
void GetValueFromIndex(struct TestArray arr, int index) {
	if (index < arr.length && index >= 0)
	{	
		int val = arr.A[index];
		printf("Value %d is in index %d\n", val, index);
	}
	else
	{
		printf("Index is out of boundaries\n");
	}
}

// Set value to specific index in array
void SetValue(struct TestArray* arr, int index, int val) {
	if (index < arr->length && index >= 0)
	{
		arr->A[index] = val;
		printf("Value %d was added in index %d succesfully\n", val, index);
	}
	else
	{
		printf("Index is out of boundaries\n");
	}
}

// Print max value in array
void PrintMaxVal(struct TestArray arr) {
	int p = arr.A[0], i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > p)
		{
			p = arr.A[i];
		}
	}
	printf("Max values is %d\n", p);
}

// Print min value in array
void PrintMinVal(struct TestArray arr) {
	int p = arr.A[0], i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < p)
		{
			p = arr.A[i];
		}
	}
	printf("Min values is %d\n", p);
}

// Gets sum of all values in array. 
void PrintSumVal(struct TestArray arr) {
	int i, sum = 0;
	for (i = 0; i < arr.length; i++)
	{
		sum += arr.A[i];
	}
	printf("Array's sum is %d", sum);
}

// Main function, where test array is created and user can configure it
void TestArrayMain() {

	int numberVal, i;
	struct TestArray arr;

	printf("Enter size of array you want to create\n");
	scanf_s("%d", &arr.size);
	arr.A = (int*)malloc(arr.size * sizeof(int));
	arr.length = 0;

	printf("How meny numbers do you want to add to the array?\n");
	scanf_s("%d", &numberVal);

	printf("\nWrite all elements: ");
	for (i = 0; i < numberVal; i++)
	{
		scanf_s("%d", &arr.A[i]);
		arr.length++;
	}

	PrintSumVal(arr);
	DisplayArray(arr);
}