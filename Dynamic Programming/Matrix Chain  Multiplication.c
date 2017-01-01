/*
The input sequence is : 

6
30 35 15 5 10 20 25
*/

#include<stdio.h>
#include<limits.h>

long int m[10][10], s[10][10];

void initialize(long int arr[10][10],int n)
{
	int i = 0,j = 0;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			arr[i][j] = INT_MIN;
		}
	}
}

void display(long int arr[10][10],int n)
{
	int i = 0,j = 0,l = 0,k = 0,space_count = n;
	for(l = n; l >= 2; l--)
	{
		for(k = space_count;k > 0;k--)
		{
			printf(" ");
		}
		for(i = 1; i <= n-l+1; i++)
		{
			j = i+l-1;
			printf("%ld ",arr[i][j]);
		}
		space_count--;
		printf("\n");
	}
}

void printOptimalParantheses(int start, int end)
{
	if(start == end)
	{
		printf("A%d", start);
	}
	else
	{
		printf("(");
		printOptimalParantheses(start, s[start][end]);
		printOptimalParantheses(s[start][end]+1, end);
		printf(")");
	}
}

void matrixChainOrder(int p[], int n)
{
	int i = 0, j = 0, l = 0, k = 0, q = 0;
	for(i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for(l = 2; l <= n; l++)
	{
		for(i = 1; i <= n-l+1; i++)
		{
			j = i+l-1;
			m[i][j] = INT_MAX;
			for(k = i; k <= j-1; k++)
			{
				q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

int main(void)
{
	int i = 0, n = 0,p[10];
	printf("Enter the no. of matrices: ");
	scanf("%d",&n);
	initialize(m,n);
	initialize(s,n);

	printf("Enter the dimension sizes of the %d matrices:\n",n);
	for(i = 0; i <= n; i++)			// p.length = n + 1
	{
		scanf("%d",&p[i]);
	}

	matrixChainOrder(p, n);
	printf("\nThe table for array m :\n");
	display(m,n);
	printf("\nThe table for array s :\n");
	display(s,n);
	printf("\n\nThe correct order for multiplying the matrices is:\n");
	printOptimalParantheses(1,n);
	return 0;
}