#include <stdio.h>
#include <stdlib.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

// Run TestArrayMain() or StaticTestArrayMain()!
// TestArrayMain works for non static array and StaticTestArrayMain is for static version.

void TestArrayMain();
void StaticTestArrayMain();
void DisplayArray(struct TestArray arr);
void DisplayArrayMerge(struct TestArrayStaticSize arr);
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
void PrintAvgVal(struct TestArray arr);
void ReverseArray(struct TestArray* arr);
void LeftShiftArray(struct TestArray* arr, int rotate);
void RightShiftArray(struct TestArray* arr, int rotate);
void InsertToSortedArray(struct TestArray* arr, int value);
void PrintIsArraySorted(struct TestArray arr);
struct TestArrayStaticSize* MergeTwoTestArrays(struct TestArrayStaticSize* arrA, struct TestArrayStaticSize* arrB);
struct TestArrayStaticSize* UnionTwoTestArrays(struct TestArrayStaticSize* arrA, struct TestArrayStaticSize* arrB);
struct TestArrayStaticSize* IntersectTwoTestArrays(struct TestArrayStaticSize* arrA, struct TestArrayStaticSize* arrB);
struct TestArrayStaticSize* DifferenceTwoTestArrays(struct TestArrayStaticSize* arrA, struct TestArrayStaticSize* arrB);
void FindMissingElementSortedArrayStartingOne(struct TestArray arr);
void FindMissingElementSortedArrayStartingN(struct TestArray arr);
void FindMultipleElementsInSortedArray(struct TestArray arr);
void FindElementsUsingHashtable(struct TestArray* arr, int mode, int k);
void FindMultipleElementsInSortedArray(struct TestArray arr);


struct TestArray {
	int* A;
	int size; // Array size
	int length; // number of elements in array
};

struct TestArrayStaticSize {
	int A[10];
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

// Print array to console TestArrayStaticSize-version
void DisplayArrayMerge(struct TestArrayStaticSize arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
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
	int l = 0, mid, h = arr.length-1;
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
	printf("Array is sorted!\n");
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

// Calculate average value of all values in array
void PrintAvgVal(struct TestArray arr) {
	
	int i, sum = 0;
	for (i = 0; i < arr.length; i++)
	{
		sum += arr.A[i];
	}
	float avg = (float)sum / (float)arr.length;
	printf("Average value of all values in array is %lf", avg);
}

// Reverse all values in array
void ReverseArray(struct TestArray* arr) {
	int i, j, temp;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		temp = arr->A[i];
		arr->A[i] = arr->A[j];
		arr->A[j] = temp;
	}
}

// Left shift array, will replace last value with 0 (rotate = 0)
// If rotate variable is 1, last value will be replaced with the first one.
void LeftShiftArray(struct TestArray* arr, int rotate) {
	if (rotate == 0)
	{
		int i;
		for (i = 0; i < arr->length-1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->A[arr->length - 1] = 0;
		printf("Shift Complete!\n");
	}
	else if (rotate == 1) {
		int i, temp = arr->A[0];
		for (i = 0; i < arr->length - 1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->A[arr->length - 1] = temp;
		printf("Rotate Complete\n");
	}
	else {
		printf("Rotate value was incorrect, please give either value 1 or 0!");
	}
}

// Right shift array, will replace first value with 0 (rotate = 0)
// If rotate variable is 1, first value will be replaced with the first one.
void RightShiftArray(struct TestArray* arr, int rotate) {
	if (rotate == 0)
	{
		int i;
		for (i = arr->length; i >= 0 ; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[0] = 0;
		printf("Shift complete\n");
	}
	else if (rotate == 1) {
		int i, temp = arr->A[arr->length-1];
		for (i = arr->length; i >= 0; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[0] = temp;
		printf("Rotate complete\n");
	}
	else {
		printf("Rotate value was incorrect, please give either value 1 or 0!");
	}
}

// Insert a value to sorted array. Inserting is faster when array is sorted.
// This is possible because shifting can be done while checking and comparing the current index value
void InsertToSortedArray(struct TestArray* arr, int value) {
	if (arr->length >= arr->size)
	{
		// No free space
		return;
	}
	int i = arr->length - 1;
	while (i>= 0 && arr->A[i] > value)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = value;
	printf("Insert complete!\n");
	arr->length++;
}

// Checks if the array is sorted or not. Result will be printed out.
void PrintIsArraySorted(struct TestArray arr) {
	int i;
	for (i = 0; i < arr.length-1; i++)
	{
		if (arr.A[i] > arr.A[i+1])
		{
			printf("Array is not sorted!\n");
			return;
		}
	}
	printf("Array is sorted!\n");
}

// Merge of two sorted arrays, does not work with basic TestArrayMain, use StaticTestArrayMain. 
struct TestArrayStaticSize* MergeTwoTestArrays(struct TestArrayStaticSize *arrA, struct TestArrayStaticSize *arrB) {
	struct TestArrayStaticSize*arrC = (struct TestArrayStaticSize*)malloc(sizeof(struct TestArrayStaticSize));
	int i = 0,
		j = 0,
		k = 0;

	// Inset sorted data into new array till one of arrays A or B pointer index is end of the array.
	while (i<arrA->length && j < arrB->length)
	{
		if (arrA->A[i]<arrB->A[j])
		{
			arrC->A[k++] = arrA->A[i++];
		}
		else
		{
			arrC->A[k++] = arrB->A[j++];
		}
	}

	// One of arrays is end, now we insert last data from other array
	for (; i < arrA->length; i++)
	{
		arrC->A[k++] = arrA->A[i];
	}
	for (; j < arrB->length; j++)
	{
		arrC->A[k++] = arrB->A[j];
	}

	arrC->length = arrA->length + arrB->length;
	arrC->size = 10;

	return arrC;
}

// Union of two sorted arrays. Use StaticTestArrayMain. Union differs from merge, by copying only one value.
// So in Union merge, there is only one copy of every value in array.
struct TestArrayStaticSize* UnionTwoTestArrays(struct TestArrayStaticSize* arrA, struct TestArrayStaticSize* arrB) {
	struct TestArrayStaticSize* arrC = (struct TestArrayStaticSize*)malloc(sizeof(struct TestArrayStaticSize));
	int i = 0,
		j = 0,
		k = 0;

	// Inset sorted data into new array till one of arrays A or B pointer index is end of the array.
	while (i < arrA->length && j < arrB->length)
	{
		if (arrA->A[i] < arrB->A[j])
		{
			arrC->A[k++] = arrA->A[i++];
		}
		else if (arrB->A[j] < arrA->A[i])
		{
			arrC->A[k++] = arrB->A[j++];
		}
		else
		{
			arrC->A[k++] = arrA->A[i++];
			j++;
		}
	}

	// One of arrays is end, now we insert last data from other array
	for (; i < arrA->length; i++)
	{
		arrC->A[k++] = arrA->A[i];
	}
	for (; j < arrB->length; j++)
	{
		arrC->A[k++] = arrB->A[j];
	}

	arrC->length = k;
	arrC->size = 10;

	return arrC;
}

// Intersection of two sorted arrays. Use StaticTestArrayMain. Intersection differs from merge, by copying only one value of duplicat values.
// So in Intersection merge, there is only one copy of every duplicate value in array.
struct TestArrayStaticSize* IntersectTwoTestArrays(struct TestArrayStaticSize* arrA, struct TestArrayStaticSize* arrB) {
	struct TestArrayStaticSize* arrC = (struct TestArrayStaticSize*)malloc(sizeof(struct TestArrayStaticSize));
	int i = 0,
		j = 0,
		k = 0;

	// Inset sorted data into new array till one of arrays A or B pointer index is end of the array.
	while (i < arrA->length && j < arrB->length)
	{
		// A is smaller
		if (arrA->A[i] < arrB->A[j])
		{
			i++;
		}
		else if (arrB->A[j] < arrA->A[i])
		{
			j++;
		}
		else if (arrA->A[i] == arrB->A[j])
		{
			arrC->A[k++] = arrA->A[i++];
			j++;
		}
	}

	arrC->length = k;
	arrC->size = 10;

	return arrC;
}

// Difference of two sorted arrays. Use StaticTestArrayMain. Difference differs from merge, by copying only values that are not in one of the array.
// Data will be only copied from the first array (arrA)
struct TestArrayStaticSize* DifferenceTwoTestArrays(struct TestArrayStaticSize* arrA, struct TestArrayStaticSize* arrB) {
	struct TestArrayStaticSize* arrC = (struct TestArrayStaticSize*)malloc(sizeof(struct TestArrayStaticSize));
	int i = 0,
		j = 0,
		k = 0;

	// Inset sorted data into new array till one of arrays A or B pointer index is end of the array.
	while (i < arrA->length && j < arrB->length)
	{
		// This value is not in A
		if (arrA->A[i] < arrB->A[j])
		{
			arrC->A[k++] = arrA->A[i++];
		}
		// This value is in A 
		else if (arrB->A[j] < arrA->A[i])
		{
			j++;
		}
		// Duplicate, no need to add value
		else
		{
			i++;
			j++;
		}
	}

	// Add last values
	for (; i < arrA->length; i++)
	{
		arrC->A[k++] = arrA->A[i];
	}

	arrC->length = k;
	arrC->size = 10;

	return arrC;
}

// Print missing element from sorted array starting from 1. Dont try if array is not sorted or there is duplicates 
// 1 2 4 5 --> 3 is missing
void FindMissingElementSortedArrayStartingOne(struct TestArray arr) {
	// Init
	int sum = 0,
		i = 0,
		s = 0;

	// Sum all values in array
	for (; i < arr.length; i++)
	{
		sum += arr.A[i];
	}

	// Sum of array length, which is last value in array(if no element is missing)
	s = (arr.A[arr.length-1] * (arr.A[arr.length-1] + 1)) / 2;

	// Print missing value 
	printf("Missing value is: %d\n", s-sum);

}

// Print missing element from sorted array starting from n value. Dont try if array is not sorted or there is duplicates 
// 3 4  6 --> 5 is missing
void FindMissingElementSortedArrayStartingN(struct TestArray arr) {
	int low = arr.A[0],
		high = arr.A[arr.length - 1],
		diff = low - 0,
		i = 1;
	for (; i < arr.length; i++)
	{
		if (arr.A[i]-i != diff)
		{
			printf("Missing value is: %d\n", i + diff);
			return;
		}
	}
}

// Print missing elements from sorted array starting from n value. Dont try if array is not sorted or there is duplicates 
void FindMultipleElementsInSortedArray(struct TestArray arr) {
	int i = 0, j, count = 1;
	for (;i < arr.length-1; i++)
	{
		if (arr.A[i] == arr.A[i+1])
		{
			j = i + 1;
			count = 1;
			while (arr.A[j] == arr.A[i])
			{
				j++;
				count++;
			}
			printf("Value %d is appearing %d times\n", arr.A[i], count);
			i = j - 1;
		}
	}
}

// Find duplicate values in sorted array. Counts and prints duplicate value
void FindDuplicateValuesInSortedArray(struct TestArray arr) {
	int low = arr.A[0],
		high = arr.A[arr.length - 1],
		diff = low - 0,
		i = 0;
	for (; i < arr.length; i++)
	{
		if (arr.A[i] - i != diff)
		{
			while (diff < arr.A[i] - i)
			{
				printf("Missing value is: %d\n", i + diff);
				diff++;
			}

		}
	}
}

// Print missing elements from array by using hash table.
// mode = 0, print missing values. mode = 1 print duplicate values
// mode = 2, find a paird with sum k (a+b=k)
void FindElementsUsingHashtable(struct TestArray* arr, int mode, int k) {

	int i;
	int n = arr->length;
	int max = arr->A[0];
	for (i = 1; i < arr->length; i++)
	{
		if (arr->A[i] > max)
		{
			max = arr->A[i];
		}
	}

	// The difference in malloc and calloc is that malloc does not set the memory to zero
	// where as calloc sets allocated memory to zero.
	int* htarr = (int*)calloc(max+1, sizeof(int));

	if (mode == 0)
	{
		for (i = 0; i < arr->length; i++)
		{
			htarr[arr->A[i]]++;
		}

		printf("Missing values in index: ");
		for (i = 0; i <= max; i++)
		{
			if (htarr[i] == 0)
			{
				printf("%d ",i);
			}
		}
	}
	else if (mode == 1)
	{
		for (i = 0; i < arr->length; i++)
		{
			htarr[arr->A[i]]++;
		}

		printf("Duplicate values are: ");
		for (i = 0; i <= max; i++)
		{
			if (htarr[i] > 1)
			{
				printf("%d ", i);
			}
		}
	}
	else if (mode == 2)
	{
		for (i = 0; i < arr->length; i++)
		{
			// Pair has been found
			if (htarr[k - arr->A[i]] != 0 && k - arr->A[i] > 0)
			{
				printf("Values %d and %d were found\n", arr->A[i], k - arr->A[i]);
			}
			htarr[arr->A[i]]++;
		}
	}


	free(htarr);
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
	printf("\n");

	FindElementsUsingHashtable(&arr,2,10);
	DisplayArray(arr);
}

// Main function, where static array can be tested
void StaticTestArrayMain() {

	struct TestArrayStaticSize arr1 = { {2,9,21,28,35},10,5 };
	struct TestArrayStaticSize arr2 = { {2,3,16,18,28},10,5 };
	struct TestArrayStaticSize* arr3;
	arr3 = DifferenceTwoTestArrays(&arr1, &arr2);
	DisplayArrayMerge(*arr3);

}