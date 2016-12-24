/* 
	This is a program to demonstrate running time of different sorting algorithms.
	To visualie it through GNU -
	plot "./insertion.txt" with linespoints 1 1,"./selection.txt" with linespoints 3 3, "./bubble.txt" with linespoints 5 5
*/
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int [],int,int,int);
int pivot (int [],int,int);
FILE *fp = NULL,*fp1 = NULL,*fp2 = NULL,*fp3 = NULL;
int a[200000000],b[200000000];
void ranGenerate(int n)
{
	int i = 0;
	fp = fopen("random.txt","w");
	if (fp == NULL) 
	{
         printf("couldn't open file for writing.\n");
         exit(0);
    }
	srand(time(NULL));
	for(i = 0;i < n;i++)
	{
		int r = rand(); 
		fprintf(fp,"%d\n",r);
	}
	fclose(fp);
	printf("Random file generated\n");
}
void arrayCreate(int a[])
{
	int i = 0,k = 0;
	fp = fopen("random.txt","r");	
	while (!feof (fp))
	{  	       
		fscanf (fp, "%d", &i);
		a[k++] = i;
	}
	fclose (fp);
}
void insertion(int n)
{
	int i = 0,j = 0,k = 0,temp = 0,key = 0,t = 0; 
	arrayCreate(a);
	for(i = 1;i < n;i++)
	{
		j = i;
		key = a[j];
		while(a[j] < a[j-1] && j > 0)
		{
			t = a[j];
			a[j] = a[j-1];
			a[j-1] = t;
			j--;
		}
	}
}
void mergeSort(int a[],int l,int h)
{
	int mid = 0;
	if(l < h)
	{
		mid = (l + h)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}
void merge(int a[],int l,int m,int h)
{
	int i = l,j = m+1,k = l;
	while(i <= m && j <= h)
	{
		if(a[i] <= a[j])
		{
			b[k++] = a[i++];
		}	
		else if(a[j] <= a[i])
		{
			b[k++] = a[j++];
		}
	}
	while(i <= m)
	{
		b[k++] = a[i++];
	}
	while(j <= h)
	{
		b[k++] = a[j++];
	}
	i = l;
	while(i <= h)
	{
		a[i] = b[i];
		i++;
	}
}
void quickSort(int a[],int l,int h)
{
	int pivot = 0;
	if(l < h)
	{
		pivot = partition(a,l,h);
		quickSort(a,l,pivot);
		quickSort(a,pivot+1,h);
	}
}
int partition(int a[],int l,int h)
{
	int i = l-1,j = h+1,p = a[l],t = 0;
	while(1)
	{
		do
		{
			i++;
		}while(a[i] < p);
		do
		{
			j--;
		}while(a[j] > p);
		if(i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		else
			return j;
	}
}
int main(void)
{
	int n = 0;
	printf("Enter the input size:");
	scanf("%d",&n);
	ranGenerate(n);
	clock_t t;
	t = clock();
	insertion(n);
	t = clock()-t;
	double time_taken_insertion = ((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for insertion sort is %f seconds.\n",time_taken_insertion);
	fp1 = fopen("time_taken.txt","a");
	fprintf(fp1,"%d\t%lf\n",n,time_taken_insertion);
	t = clock();
	arrayCreate(a);
	mergeSort(a,0,n);
	t = clock()-t;
	double time_taken_merge = ((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for merge sort is %f seconds.\n",time_taken_merge);
	fprintf(fp1,"%d\t%lf\n",n,time_taken_merge);
	fclose(fp1);
	t = clock();
	arrayCreate(a);
	quickSort(a,0,n);
	t = clock()-t;
	double time_taken_quick = ((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for selection sort is %f seconds.\n",time_taken_quick);
	fprintf(fp1,"%d\t%lf\n",n,time_taken_quick);
	fclose(fp1);
	return 0;
}