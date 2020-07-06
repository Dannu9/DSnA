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

	//InsertToArray(&arr, 12, 1);
	DeleteFromArray(&arr, 2);
	//AddToArray(&arr, 12);
	DisplayArray(arr);
}