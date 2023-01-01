#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void List(int A[],int capacity)
{
	int i;
	for(i=0;i<capacity;i++)
		printf("%d,",A[i]);
	printf("\n");
}

void InsertionSort(int A[],int capacity)
{
	int i,j;
	int tmp;
	for(i=1;i<capacity;i++)
	{
		tmp=A[i];
		for(j=i;j>0&&A[j-1]>tmp;j--)
			A[j]=A[j-1];
		A[j]=tmp;
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int Median3(int A[],int left,int right)
{
	int center=(left+right)/2;
	if(A[left]>A[center])
		swap(&A[left],&A[center]);
	if(A[left]>A[right])
		swap(&A[left],&A[right]);
	if(A[center]>A[right])
		swap(&A[center],&A[right]);
	swap(&A[center],&A[right-1]);
	return A[right-1];
}

void Qsort(int A[],int left,int right)
{
	
	int i,j;
	int pivot;
	if(left+3<=right)
	{
		printf("Qsort(%d,%d):",left,right);
		pivot=Median3(A,left,right);
		i=left;
		j=right-1;
		for(;;)
		{
			while(A[++i]<pivot)
			{
				
			}
			while(A[--j]>pivot)
			{
				
			}
			if(i<j)
				swap(&A[i],&A[j]);
			else
				break;	
		}
		swap(&A[i],&A[right-1]);
		List(A,10);
		Qsort(A,left,i-1);
		Qsort(A,i+1,right);
	}
	else
	{
		printf("insert(%d,%d):",left,right-left+1);
		InsertionSort(A+left,right-left+1);
		List(A,10);
	}
}

void Quicksort(int arr[],int size,int pivot_number)
{	
	printf("Qsort(%d,%d):",0,9);
	int pivot=arr[pivot_number];
	swap(&arr[pivot_number],&arr[9]);
	int i,j;
	i=-1;
	j=9;
	while(1)
	{
		while(arr[++i]<pivot)
		{
			
		}
		while(arr[--j]>pivot)
		{
			
		}
		if(i<j)
			swap(&arr[i],&arr[j]);
		else
			break;
	}
	swap(&arr[i],&arr[9]);
	List(arr,10);
	Qsort(arr,0,i-1);
	Qsort(arr,i+1,9);
}





int main()
{
	int input[10]={49,38,65,97,76,13,27,50,2,8};
	int num;
	scanf("%d",&num);
	Quicksort(input,10,num);
	return 0;
}