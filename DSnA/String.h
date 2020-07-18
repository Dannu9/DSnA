#include <stdio.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

int LengthOfString(char input[]);
void PrintStringCase(char* s, int mode);
void PrintCountOfVowelsAndConsonantsAndWords(char* s);
int StringValidation(char* s);
char* ReverseString(char* s);
void CheckIfStringsAreIdentic(char* s1, char* s2, int mode);
void CheckIfStringIsPalindrome(char* s);
void PrintCharCount(char* s);
void PrintDuplicateCharsByUsingBitwise(char* s);
void PrintIsTwoStringsAnagram(char* a, char* b);

// Calculates the length of string. Returns integer value 
int LengthOfString(char* input) 
{
	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	return i;

	/* TEST 
		char* s = "TestString";
		int i = 0;
		i = LengthOfString(s);
		printf("String length is :%d", i);
	*/
}

// Print string in uppercase, lowercase or changed case 
// mode = 1 upper
// mode = 2 lower
// mode = 3 switch case
void PrintStringCase(char* s, int mode) {

	if (mode == 0)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] >= 'a' && s[i] <= 'z') {
				printf("%c", s[i] - 32);
			}
			else
			{
				printf("%c", s[i]);
			}
			++i;
		}
	}
	else if (mode == 1)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] >= 'A' && s[i] <= 'Z') {
				printf("%c", s[i] + 32);
			}
			else
			{
				printf("%c", s[i]);
			}
			++i;
		}
	}
	else if (mode == 2)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] >= 'A' && s[i] <= 'Z') {
				printf("%c", s[i] + 32);
			}
			else
			{
				printf("%c", s[i] - 32);
			}
			++i;
		}
	}

}

// Counts all vowels, consonants and words/spaces in the string
void PrintCountOfVowelsAndConsonantsAndWords(char* s) 
{
	int vow = 0, conso = 0, spaces = 0, i = 0;

	for (i = 0; i < s[i] != '\0'; i++)
	{
		// Letter
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U' || s[i] == 'y' || s[i] == 'Y')
			{
				vow++;
			}
			else
			{
				conso++;
			}
		}
		else if (s[i] == ' ' && s[i-1] != ' ')
		{
			spaces++;
		}
	}
	printf("Vowels: %d\nConsonants: %d\nWords: %d", vow, conso, spaces + 1);

	/* TEST
		char* s = "TestString And AAA";
		PrintCountOfVowelsAndConsonantsAndWords(s);
	*/
}

// String validation check. This function checks if string is contains only letters and numbers
// returns int value. 1 = string is OK, 0 = string is not valid
int StringValidation(char *s){
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9'))
		{
			return 0;
		}
	}

	return 1;

	/* TEST
		char* s = "TestStringAn dAAA";
		int i = StringValidation(s);
		printf("%d", i);
	*/
}

// Reverse string, return pointer of a new reversed string
char* ReverseString(char* s) {

	int i = 0, j = 0, tempVal;
	// index to last "null" char
	while (s[i] != '\0')
	{
		i++;
	}
	// Create new array dynamically and save last indez location
	char* ret = (char*)malloc(i * sizeof(char));
	tempVal = i;

	// Index to last letter
	i--;

	for (; i >= 0; j++, i--)
	{
		ret[j] = s[i];
	}

	ret[tempVal] = '\0';
	return ret;
}

// This function takes two strings and comapres them. Result will be printed.
// Use mode = 0, It is default. Mode = 1 is used in CheckIfStringIsPalindrome
void CheckIfStringsAreIdentic(char* s1, char* s2, int mode) {

	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (mode == 0)
			{
				printf("Strings are not identical, %d index is different\n", i);
				return;
			}
			else if (mode == 1)
			{
				printf("Strings is not a palindrome\n");
				return;
			}

		}
		i++;
	}

	if (mode == 0)
	{
		printf("Strings are identical");
	}
	else if (mode == 1)
	{
		printf("String is a palindrome");
	}


	/* TEST
		char* s = "TestStringAn dAAA";
		char* ss = "TestStringAn dAAsA";
		CheckIfStringsAreIdentic(s, ss, 0);
	*/
}

// This function checks if string is palindrome. Result will be printed out
// This function uses ReverseString and CheckIfStringsAreIdentic
void CheckIfStringIsPalindrome(char* s) {

	char* reversed = ReverseString(s);
	CheckIfStringsAreIdentic(s, reversed, 1);

	/* TEST
		char* s = "LilliL";
		CheckIfStringIsPalindrome(s);
	*/
}

// Calculate and print all count of all chars in string.
void PrintCharCount(char* s) {
	
	int i = 0, j = 0;
	int* hashTableUpper = (int*)calloc(25, sizeof(int));
	int* hashTableLower = (int*)calloc(25, sizeof(int));
	while (s[i] != '\0')
	{
		// Uppercase letter
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			hashTableUpper[s[i] - 65]++;
		}// Lowercase letter
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			hashTableLower[s[i] - 97]++;
		}
		i++;
	}

	for (j = 0; j <= 25; j++)
	{
		if (hashTableUpper[j] > 0)
		{
			printf("%c - %d\n", j + 65, hashTableUpper[j]);
		}
	}
	for (j = 0; j <= 25; j++)
	{
		if (hashTableLower[j] > 0)
		{
			printf("%c - %d\n", j + 97, hashTableLower[j]);
		}
	}

	/*
		char* s = "DOES this WORK ss";
		PrintCharCount(s);	
	*/
}

// Print all duplicate chars in string to console, by using bitwise operations.
void PrintDuplicateCharsByUsingBitwise(char* s) {

	// Create variable, that uses 4 bytes.
	// Because we have 25 letters (a-z) we need 25 bits. 4 Bytes = 32 bits, thats enought for this use
	int B = 0; // Main bitwise area
	int x = 0; // Used for masking

	int i = 0;
	for (; i < s[i] != '\0'; i++)
	{
		// a-z / 97-122 -> a-z / 0-25
		x = 1; // Set least significant bit to 1
		x = x << (s[i] - 97); // Shift bit to right postinion, so masking is possible

		// Check if there is duplicate
		if ((x&B) > 0)
		{
			printf("%c value is duplicate\n", s[i]);
		}
		else // Merge x to B, so we know that there is atleast one value of specific char
		{
			B = x | B;
		}

		/* TEST
			char* s = "abcdefgabsc";
			PrintDuplicateCharsByUsingBitwise(s);
		*/
	}
}

// Prints result if strings are anagram or not. Use only with lowercases!! 
void PrintIsTwoStringsAnagram(char* a, char* b) {
	int aL = LengthOfString(a);
	int bL = LengthOfString(b);
	int i = 0;

	if (aL != bL)
	{
		printf("String lengths are not equal\n");
	}
	else
	{
		int* hashTable = (int*)calloc(25, sizeof(int));

		for (; a[i] != '\0'; i++)
		{
			hashTable[a[i] - 97] += 1;
		}

		for (i = 0; b[i] != '\0'; i++)
		{
			hashTable[b[i] - 97] -= 1;
			if (hashTable[b[i] - 97] < 0)
			{
				printf("Strings are not anagram to each other!\n");
				break;
			}
		}

		if (b[i] == '\0')
		{
			printf("Strings are anagram to each other! \n");
		}
	}

	/* TEST
	 	char* s1 = "abcvaw";
		char* s2 = "vbacaw";
		PrintIsTwoStringsAnagram(s1, s2);
	*/
}