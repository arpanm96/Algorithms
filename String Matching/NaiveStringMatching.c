/*
The input sequence is given below(Text and Pattern respectively):
abcbacaabcbca
acaabc
*/

#include<stdio.h>
#include<malloc.h>

#define MAX_STRING_SIZE 100


int naiveStringMatcher(char *text,char *pattern)
{
	int i = 0,j = 0,flag = 0,found = 0;
	for(i = 0;text[i] != '\0'; i++)
	{
		for(j = 0;j < pattern[j] != '\0' ; j++)
		{
			if(text[i+j] == pattern[j])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1)
		{
			printf("Pattern found at index %d!\n",i);
			found = 1;
		}
	}
	return found;
}
int main(void)
{
	char *text, *pattern;
	text = (char *)malloc(sizeof(char) * MAX_STRING_SIZE);
	pattern = (char *)malloc(sizeof(char) * MAX_STRING_SIZE);

	printf("Enter the text and pattern respectively:\n");
	gets(text);
	gets(pattern);

	//printf("Text:%s\nPattern:%s\n",text,pattern);

	if(!naiveStringMatcher(text,pattern))
		printf("Pattern not found!\n");
	return 0;
}