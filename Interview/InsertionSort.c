
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to sort an array using insertion sort*/

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void insertionSort(int arr[], int n)
{
    int i, j = 0;
    for (i = 1; i < n; i++)
    {
        j =i;
        while( (j > 0) && ( arr[j-1] > arr[j] ) )
        {
            swap(&arr[j-1],&arr[j]);
            j--;
        }
    }
}

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
int i;
for (i=0; i < n; i++)
	printf("%d ", arr[i]);
printf("\n");
}



/* Driver program to test insertion sort */
int main()
{
	int arr[] = {1, 4, 3, 12, 11, 13, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
