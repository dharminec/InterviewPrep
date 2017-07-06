#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int l, int r)
{
    int p = A[r];
    int i = 0;
    for(int j = l;j<p;j++)
    {
        if(A[j] < p)

    }

}

void QuickSort(int A[],int l, int m, int r)
{
    if(l < r)
    {
        int pivot =
    }
}
void merge(int A[],int l, int m, int r)
{
        int n1, n2;
        n1 = m - l + 1;
        n2 = r - m ;

        //int *l1 = (int *)malloc(sizeof(int)*n1);
        //int *r1 = (int *)malloc(sizeof(int)*n2);

        int l1[n1];
        int r1[n2];
        int i;
        for(i = 0; i< n1; i++){
            l1[i] = A[i+l];
        }

        for(i = 0; i< n2; i++)
            r1[i] = A[i + m +1];

        i=0;
        int j = 0;
        int k = l;

        while(i < n1 && j < n2)
        {
            if(l1[i] <= r1[j])
                A[k++] = l1[i++];
            else
                A[k++] = r1[j++];
        }

        while(i < n1)
        {
            A[k++] = l1[i++];
        }

        while(j < n2)
        {
            A[k++] = r1[j++];
        }
}
void mergesort(int A[],int l, int r)
{
    if(l<r)
    {
        int mid = l+ (r-l)/2;
        mergesort(A,l,mid);
        mergesort(A,mid+1,r);
        merge(A,l,mid,r);
    }
    return;
}

int main()
{
    int A[] = {12, 11, 13, 5, 6, 7,2,5,7,6,81,25,1,4,8,9,10};

    int sizeofA = sizeof(A)/sizeof(A[0]);

    mergesort(A, 0, sizeofA - 1);
    int i;
    for(i = 0; i< sizeofA ; i++)
       printf("%d ",A[i]);
    return 0;
}
