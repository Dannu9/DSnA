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
struct MinMax MaxAndMinValuesInLinkedList(struct Node* p, struct MinMax* m);
struct Node* LinkListSearch(struct Node* p, int key);
void InsertNewNodeInLinkedList();
void InsertNewNodeInSortedLinkedList();
void AddNodeToLinkedList(struct Node* p, int val, int index);
void InsertInSortedLinkedList(struct Node* p, int val);

// Node structure pointer start
struct Node {
	int data;
	struct Node* next;
}*first = NULL,
*last = NULL;

// This struct is used to find min and max values in linked list
struct MinMax {
	int min;
	int max;
};

// Create link list from array 
void CreateLinkList(int arr[], int n) {
	int i; 
	// t = temp, last = last node
	struct Node* t;
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

// Calculates the sum of all values in link list
int SumOfAllElementsInLinkList(struct Node* p) {
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

// Search for min and max values in link list
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

// Search for specific value from list
struct Node* LinkListSearch(struct Node* p, int key){

	while (p != NULL)
	{
		if (key == p->data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// Add value to specific index in node
void AddNodeToLinkedList(struct Node* p, int val, int index) {
	int n = LengthOfLinkList(p);

	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));

	if (index > n || index < 0)
	{
		printf("Index value is out of array range");
	} // Inserting before first node 
	else if (index == 0)
	{
		t->data = val;
		t->next = first;
		first = t;
	}
	else {
		t->data = val;
		int i;
		for (i = 0; i < index-1 && index; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}

// Example of inserting value in sorted linked list
void InsertInSortedLinkedList(struct Node* p, int val) {

	struct Node *q = NULL, *d;

	d = (struct Node*)malloc(sizeof(struct Node));
	d->data = val;
	d->next = NULL;

	if (first == NULL)
	{
		first = d;
	}
	else
	{
		while (p && p->data < val)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			d->next = first;
			first = d;
		}
		else
		{
			d->next = q->next;
			q->next = d;
		}
	}
}

// Example of creating Link list from array and then displaying it in console
void CreateAndDisplayLinkListExample() {
	int A[] = { 1,2,3,4,5,6,7,8,9};

	struct MinMax *mm;
	mm = (struct MinMax*)malloc(sizeof(struct MinMax));

	CreateLinkList(A, 9); // Give array reference and count of variables in the array
	DisplayLinkListRecursive(first,1);
	printf("\nList length is: %d", LengthOfLinkList(first));
	printf("\nSum of all elements in list: %d", SumOfAllElementsInLinkList(first));
	MaxAndMinValuesInLinkedList(first, mm);
	printf("\nMin value is: %d\nMax Value is: %d", mm->min, mm->max);
	int key;
	printf("\nSearch for a key: ");
	scanf_s("%d", &key);
	printf("Key %d was found from addres: %d", key, *LinkListSearch(first, key));
};

// Example of inserting new node in linked list
void InsertNewNodeInLinkedList() {

	/* Where user can insert
	   Index   0   1   2    3   4   5
			   v   v   v    v   v   v		
		+------+---+---+----+---+---+
		| Node | 1 | 2 |  3 | 4 | 5 |
		| Data | 6 | 5 | 12 | 2 | 7 |
		+------+---+---+----+---+---+
	*/

	int A[] = {1,32,5,12,26,-23,-6,0,-6 };
	int val, index;
	CreateLinkList(A, 9);
	DisplayLinkListRecursive(first,0);
	printf("\nWhat value do you want to add?\n");
	scanf_s("%d", &val);
	printf("\nIndex? ");
	scanf_s("%d", &index);
	AddNodeToLinkedList(first, val, index);
	DisplayLinkListRecursive(first, 0);
}

// Example of insertin new node in sorted linked list
void InsertNewNodeInSortedLinkedList() {
	/* Where user can insert
   Index   0   1   2   3   4   5
		   v   v   v   v   v   v
	+------+---+---+---+---+---+
	| Node | 1 | 2 | 3 | 4 | 5 |
	| Data | 1 | 2 | 3 | 4 | 6 |
	+------+---+---+---+---+---+
*/

	int A[] = { 1,2,3,4,6};
	int val, index;
	CreateLinkList(A, 5);
	DisplayLinkListRecursive(first, 0);
	printf("\nWhat value do you want to add?\n");
	scanf_s("%d", &val);
	InsertInSortedLinkedList(first, val);
	DisplayLinkListRecursive(first, 0);
}



