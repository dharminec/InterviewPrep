// C/C++ program for reversal algorithm of array rotation
#include<stdio.h>

/*Utility function to print an array */
void printArray(int *arr, int size);

/* Utility function to reverse arr[] from start to end */
void rvereseArray(int *arr, int start, int end);
void swap(int *a, int *b);
/* Function to left rotate arr[] of size n by d */
void leftRotate(int *arr, int d, int n)
{
	int p = n-d;
	int i =0;
	while(p>1){
	    for(i = 0; i < d; i++)
	        swap(&arr[i],&arr[p+i]);
	    p = p - d;

	    printArray(arr, n);
	    printf(",  P= %d \n",p);
	}
	if(p == 1)
	{
	    rvereseArray(arr, 0, 5);
	}
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a  =*b;
    *b = temp;
}
/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

/*Function to reverse arr[] from index start to end*/
void rvereseArray(int *arr, int start, int end)
{
	while (start < end)
	{
		swap(&arr[start],&arr[end]);
		start++;
		end--;
	}
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int d = 2;
	leftRotate(arr, d, n);
	printArray(arr, n);
	return 0;
}
