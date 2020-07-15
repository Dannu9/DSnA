#include <stdio.h>

// I want to thank Abdul Bari for his Udemy lessons
// This code tutorial/examples can be found from this course https://www.udemy.com/course/datastructurescncpp/

int LengthOfString(char input[]);
void PrintStringCase(char* s, int mode);
void PrintCountOfVowelsAndConsonantsAndWords(char* s);
int StringValidation(char* s);
char* ReverseString(char* s);

// Calculates the length of string. Returns integer value 
int LengthOfString(char input[]) 
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