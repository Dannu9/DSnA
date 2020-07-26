#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

void DisplayLinkList(struct Node *p);
void DisplayLinkListRecursive(struct Node* p, int reverse);
void CreateLinkList(int arr[], int n);
void CreateAndDisplayLinkListExample();
int LengthOfLinkList(struct Node* p);
int SumOfAllElementsInLinkList(struct Node* p);
struct MinMax MaxAndMinValuesInLinkedList(struct Node* p);

// Node structure pointer
struct Node {
	int data;
	struct Node* next;
}*first = NULL;

// This struct is used to find min and max values in linked list
struct MinMax {
	int min;
	int max;
};

// Create link list from array 
void CreateLinkList(int arr[], int n) {
	int i; 
	// t = temp, last = last node
	struct Node* t, *last;
	first = (struct Node*)malloc(sizeof(struct Node));

	// First node only
	first->data = arr[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = arr[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
};

// Print link list to console.
void DisplayLinkList(struct Node *p) {
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
};

// Print link list using recursion. Int reverse == 0, no reverse
// reverse == 1, will reverse list
void DisplayLinkListRecursive(struct Node* p, int reverse) {
	if (reverse == 0)
	{
		if (p != NULL)
		{
			printf("%d ", p->data);
			DisplayLinkListRecursive(p->next, 0);
		}
	}
	else if (reverse == 1)
	{
		if (p != NULL)
		{		
			DisplayLinkListRecursive(p->next, 1);
			printf("%d ", p->data);
		}
	}
	else
	{
		printf("Reverse value was incorrect!");
	}

};

// Calculates how many nodes are in link list. 
int LengthOfLinkList(struct Node* p) {
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int SumOfAllElementsInLinkList(struct Node* p) {
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

struct MinMax MaxAndMinValuesInLinkedList(struct Node* p, struct MinMax* m) {
	int first = 1;
	while (p != NULL)
	{
		if (first)
		{
			m->min = m->max = p->data;
			first--;
		}
		else
		{
			if (m->min > p->data)
			{
				m->min = p->data;
			}
			if (m->max < p->data)
			{
				m->max = p->data;
			}
		}
		p = p->next;
	}
}

// Example of creating Link list from array and then displaying it in console
void CreateAndDisplayLinkListExample() {
	int A[] = { 1,2,3,4,5,6,7,8,9};

	struct MinMax *mm;
	mm = (struct MinMax*)malloc(sizeof(struct MinMax));

	CreateLinkList(A, 9); // Give array reference and count of variables in the array
	DisplayLinkListRecursive(first,0);
	printf("\nList length is: %d", LengthOfLinkList(first));
	printf("\nSum of all elements in list: %d", SumOfAllElementsInLinkList(first));
	MaxAndMinValuesInLinkedList(first, mm);
	printf("\nMin value is: %d\nMax Value is: %d", mm->min, mm->max);
};

