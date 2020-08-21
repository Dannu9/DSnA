#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

#pragma region Functions
	void DisplayLinkList(struct Node* p);
	void DisplayLinkListRecursive(struct Node* p, int reverse);
	void DisplayCircularLinkedList(struct Node* head);
	void CreateLinkList(int arr[], int n);
	struct Node* CreateCircularLinkedListP(int arr[], int n);
	void CreateAndDisplayLinkListExample();
	int LengthOfLinkList(struct Node* p);
	int SumOfAllElementsInLinkList(struct Node* p);
	void MaxAndMinValuesInLinkedList(struct Node* p, struct MinMax* m);
	struct Node* CreateLinkListP(int arr[], int n);
	struct Node* LinkListSearch(struct Node* p, int key);
	void InsertNewNodeInLinkedList();
	void InsertNewNodeInSortedLinkedList();
	void DeleteNodeInLinkedListExample();
	void RemoveDuplicatesFromLinkedListexample();
	void ReverseLinkedListExample();
	void ConcatTwoLinkListExample();
	void MergeTwoLinkListsExample();
	void CheckIfLinkedListIsLoopExample();
	void CreateCircularLinkedListAndDisplayExample();
	void InsertNewNodeToCircularLinkedListExample();
	void RemoveDuplicatesLinkedList(struct Node* first);
	void AddNodeToLinkedList(struct Node* p, int val, int index);
	void DeleteNodeToLinkedList(struct Node* p, int index);
	void InsertInSortedLinkedList(struct Node* p, int val);
	void CheckIsLinkedListSorted(struct Node* p);
	void ReverseLinkedList(struct Node* first);
	void CheckIfLinkedListIsALoop(struct Node* p);
	struct Node* InsertNodeToCircularLinkedList(struct Node* p, int val, int index);
	struct Node* MergeTwoLinkLists(struct Node* aA, struct Node* bA);
#pragma endregion



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

// Create link list, and return pointer
struct Node* CreateLinkListP(int arr[], int n) {
	int i;
	// t = temp,
	struct Node* t, *ret,*last;
	ret = (struct Node*)malloc(sizeof(struct Node));

	// First node only
	ret->data = arr[0];
	ret->next = NULL;
	last = ret;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = arr[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}

	return ret;
}

// Create circular linked list, and return header pointer;
struct Node* CreateCircularLinkedListP(int arr[], int n) {
	int i;
	struct Node* t, *head, *last;

	head = (struct Node*)malloc(sizeof(struct Node));
	head->data = arr[0];
	head->next = head;

	last = head;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = arr[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}

	return head;
}

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
}

// Print link list to console.
void DisplayLinkList(struct Node *p) {
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
};

// Print circular linked list to console.
void DisplayCircularLinkedList(struct Node* head) {
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t = head;
	do
	{
		printf("%d ", t->data);
		t = t->next;
	} while (t != head);
	printf("\n");
}

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

// Check if link list is sorted, and print result
void CheckIsLinkedListSorted(struct Node* p) {
	int prevVal = INT_MIN;
	while (p != NULL)
	{
		if (p->data<prevVal)
		{
			printf("\nLinkList is not sorted\n");
			return;
		}
		prevVal = p->data;
		p = p->next;
	}
	printf("\nLinkList is sorted\n");
}

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
void MaxAndMinValuesInLinkedList(struct Node* p, struct MinMax* m) {
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
void AddNodeToLinkedList(struct Node* p,int val, int index) {
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
		for (i = 0; i < index - 1 && index; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}

// Delete value to specific index in node
void DeleteNodeToLinkedList(struct Node* p, int index) {
	int n = LengthOfLinkList(p);
	int val;
	struct Node* q, * del;
	q = (struct Node*)malloc(sizeof(struct Node));
	del = (struct Node*)malloc(sizeof(struct Node));
	if (index > n || index < 1)
	{
		printf("Index value is out of array range");
	} // Inserting before first node 
	else if (index == 1)
	{

		del = p;
		val = p->data;
		first = p->next;
		free(del);
		printf("Value %d was deleted from index %d", val, index);
	}
	else {
		int i;
		for (i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		val = p->data;
		free(p);
		printf("Value %d was deleted from index %d", val, index);
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

// Reverse linked list
void ReverseLinkedList(struct Node* p) {

	struct Node* q = NULL, *r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;

		q->next = r;
	}
	first = q;
}

// Remove duplicates from linked list
void RemoveDuplicatesLinkedList(struct Node* first) {
	struct Node* p = first;
	struct Node* q = first->next;

	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
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
	CheckIsLinkedListSorted(first);
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
	int val;
	CreateLinkList(A, 5);
	DisplayLinkListRecursive(first, 0);
	printf("\nWhat value do you want to add?\n");
	scanf_s("%d", &val);
	InsertInSortedLinkedList(first, val);
	DisplayLinkListRecursive(first, 0);
}

// Example of deleting a node in linked list
void DeleteNodeInLinkedListExample() {
	/* 
	+------+---+---+---+---+---+
	| Node | 1 | 2 | 3 | 4 | 5 |
	| Data | 2 | 3 | 4 | 5 | 6 |
	+------+---+---+---+---+---+
	*/

	int A[] = { 2,3,4,5,6};
	int index;
	CreateLinkList(A, 5);
	DisplayLinkListRecursive(first, 0);
	printf("\nWhat value do you want to delete? Index!\n");
	scanf_s("%d", &index);
	DeleteNodeToLinkedList(first, index);
	printf("\n");
	DisplayLinkListRecursive(first, 0);
}

// Example of removing duplicates from linked list
void RemoveDuplicatesFromLinkedListexample() {
	/*
	+------+---+---+---+---+---+
	| Node | 1 | 2 | 3 | 4 | 5 |
	| Data | 2 | 3 | 3 | 5 | 5 |
	+------+---+---+---+---+---+
	*/

	int A[] = { 2,3,3,5,5 };
	CreateLinkList(A, 5);
	DisplayLinkListRecursive(first, 0);
	RemoveDuplicatesLinkedList(first);
	printf("\n");
	DisplayLinkListRecursive(first, 0);
}

// Example how to reverse a linked list, by changing links and using slider (pointers)
void ReverseLinkedListExample() {

	/*
	+------+---+---+---+---+---+
	| Node | 1 | 2 | 3 | 4 | 5 |
	| Data | 3 | 4 | 5 | 6 | 7 |
	+------+---+---+---+---+---+
	*/
	int A[] = { 3,4,5,6,7 };
	CreateLinkList(A, 5);
	DisplayLinkListRecursive(first, 0);
	ReverseLinkedList(first);
	printf("\n");
	DisplayLinkListRecursive(first, 0);
}

// Concatenating two linked lists
void ConcatTwoLinkLists(struct Node* aA, struct Node* bA) {

	while (aA->next != NULL)
	{
		aA = aA->next;
	}
	aA->next = bA;
	bA = NULL;
}

// Example of concatenating two linked lists
void ConcatTwoLinkListExample() {
	/*
	A
	+------+---+---+---+
	| Node | 1 | 2 | 3 |
	| Data | 4 | 5 | 6 |
	+------+---+---+---+
	B
	+------+---+---+---+
	| Node | 1 | 2 | 3 |
	| Data | 1 | 2 | 3 |
	+------+---+---+---+
	*/

	struct Node* pA, * pB;

	int A[] = { 4,5,6 };
	int B[] = { 1,2,3 };
	pA = CreateLinkListP(A, 3);
	pB = CreateLinkListP(B, 3);

	ConcatTwoLinkLists(pA,pB);

	DisplayLinkList(pA);
}

// Merge two link lists, aA will be new main pointer
struct Node* MergeTwoLinkLists(struct Node* aA, struct Node* bA) {
	struct Node* start, *last;

	// Ini case
	if (aA->data < bA->data)
	{
		start = last = aA;
		aA = aA->next;
		start->next = NULL;
	}
	else
	{
		start = last = bA;
		bA = bA->next;
		start->next = NULL;
	}

	while (aA != NULL && bA != NULL)
	{
		if (aA->data < bA->data)
		{
			last->next = aA;
			last = aA;
			aA = aA->next;
			last->next = NULL;
		}
		else
		{
			last->next = bA;
			last = bA;
			bA = bA->next;
			last->next = NULL;
		}
	}

	if (aA != NULL)
	{
		last->next = aA;
	}
	else
	{
		last->next = bA;
	}

	return start;
}

// Example of merging two link lists
void MergeTwoLinkListsExample() {
	/*
	A
	+------+---+---+---+---+
	| Node | 1 | 2 | 3 | 4´|
	| Data | 2 | 4 | 6 | 8 |
	+------+---+---+---+---+
	B
	+------+---+---+---+---+
	| Node | 1 | 2 | 3 | 4 |
	| Data | 1 | 3 | 5 | 7 |
	+------+---+---+---+---+
	*/

	struct Node* pA, * pB, *res;

	int A[] = { 2,4,6,8 };
	int B[] = { 1,3,5,7 };
	pA = CreateLinkListP(A, 4);
	pB = CreateLinkListP(B, 4);

	res = MergeTwoLinkLists(pA, pB);

	DisplayLinkList(res);
}

// Example of checking if linked list is a loop (pointer is pointing into a previous node)
void CheckIfLinkedListIsLoopExample() {
	struct Node* p1, * p2, *nod1, *nod2;

	// Lets createa a looped linked list and a normal linked list
	int A[] = { 6,7,8,9,10,11,12,13,14 };
	int B[] = { 1,2,3,4,5,6,7,8,9 };

	nod1 = CreateLinkListP(A, 9);
	nod2 = CreateLinkListP(B, 9);
	p1 = nod1->next->next->next;
	p2 = nod1->next->next->next->next->next->next->next->next;
	p2->next = p1;

	// Check if linked list is a loop
	CheckIfLinkedListIsALoop(p1);
	CheckIfLinkedListIsALoop(nod2);

}

// Check if linked list is a loop. Prints out the result. 
void CheckIfLinkedListIsALoop(struct Node* p) {

	struct Node* q, * r;
	q = r = p; 

	do
	{
		q = q->next;
		r = r->next;
		if (r != NULL)
		{
			r = r->next;
		}
	} while (q && r && q != r);

	if (q == r)
	{
		printf("\nLinked list is looped\n");
	}
	else
	{
		printf("\nLinked list is not looped\n");
	}
}

// Example how to create circular linked list and display it
void CreateCircularLinkedListAndDisplayExample() {
	int A[] = { 1,2,3,4 };

	struct Node* headerNode;

	headerNode = CreateCircularLinkedListP(A,4);
	DisplayCircularLinkedList(headerNode);
}

// Example how to insert a new node to circular linked list and then displaying it;
void InsertNewNodeToCircularLinkedListExample() {

	int A[] = { 1,2,3,4,6};
	int val, index;

	struct Node* headerNode, * nHeader;

	headerNode = CreateCircularLinkedListP(A, 5);
	DisplayCircularLinkedList(headerNode);

	printf("\n");
	printf("\nWhat value do you want to add?\n");
	scanf_s("%d", &val);
	printf("\nIndex? ");
	scanf_s("%d", &index);

	nHeader = InsertNodeToCircularLinkedList(headerNode, val, index);
	DisplayCircularLinkedList(nHeader);
}

// Insert new node into ciruclar linked list.
struct Node* InsertNodeToCircularLinkedList(struct Node* head, int val, int index) {
	/* Where user can insert
	Index   0   1   2   3   4   5
			v   v   v   v   v   v
	 +------+---+---+---+---+---+
	 | Node | 1 | 2 | 3 | 4 | 5 |
	 | Data | 1 | 2 | 3 | 4 | 6 |
	 +------+---+---+---+---+---+
	 */

	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p = head;
	int i;

	t->data = val;

	// If val is not a new hear
	if (index > 0)
	{
		for (i = 0; i < index - 1; i++)
		{
			p = p->next;
		}

		t->next = p->next;
		p->next = t;
		return head;
	}
	else // index is a new header
	{
		while (p->next != head)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
		return t;
	}


	
}