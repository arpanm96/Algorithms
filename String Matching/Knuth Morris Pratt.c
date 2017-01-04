/*
The input sequence is given below(Text and Pattern respectively):
babacbababacabc
ababaca
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define MAX_STRING_SIZE 100

void displayTable(int arr[], int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// function to not backtrack to -1 when q is 0
int setPrefixTableBacktrack(int k, int prefixTable[])
{
	if(k != 0)
		k = prefixTable[k-1];
	return k;
}

void buildPrefixTable(char *pattern, int prefixTable[])
{
	int k = 0, q = 0;
	prefixTable[0] = 0;
	for(q = 1; pattern[q] != '\0'; q++)
	{
		while(k > 0 && pattern[k] != pattern[q])
		{
			k = setPrefixTableBacktrack(k,prefixTable);
		}
		if(pattern[k] == pattern[q])
		{
			k++;
		}
		prefixTable[q] = k;
	}
	printf("The prefix table is : \n");
	displayTable(prefixTable,strlen(pattern));
}

int kmpMatcher(char *text,char *pattern, int prefixTable[])
{
	int q = 0, i = 0, m = 0, flag = 0;
	buildPrefixTable(pattern,prefixTable);
	for(i = 0; text[i] != '\0'; i++)
	{
		while(q > 0 && text[i] != pattern[q])
		{
			q = prefixTable[q-1];
		}
		if(text[i] == pattern[q])
		{
			q++;
		}
		if(q == (m = strlen(pattern)-1))
		{
			flag = 1;
			printf("Pattern found at index %d!\n",i-m+1);
			q = prefixTable[q-1];
		}
	}
	return flag;
}


int main(void)
{
	char *text, *pattern;
	text = (char *)malloc(sizeof(char) * MAX_STRING_SIZE);
	pattern = (char *)malloc(sizeof(char) * MAX_STRING_SIZE);
	int prefixTable[ strlen(pattern)];

	printf("Enter the text and the pattern to be searched respectively: \n");
	if(fgets(text,MAX_STRING_SIZE,stdin) == NULL || fgets(pattern,MAX_STRING_SIZE,stdin) == NULL)
	{
		printf("Error occured in input.");
		return -1;
	}

	if(!kmpMatcher(text, pattern, prefixTable))
		printf("Pattern not found!\n");
	return 0;
}