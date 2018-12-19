#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void DispArr(int *arr, int length)
{
    for(int i=0; i<length; i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

void Swap(int *arr, int m, int n)
{
    int tmp = arr[m];
    arr[m] = arr[n];
    arr[n] = tmp;
}

int Partation(int *arr, int left, int right)
{
    int i = left, j = right-1;
    int pivot = 0;
    while(1)
    {
        while(pivot > arr[i++])
            ;
        while(pivot < arr[j++] && i <= j)
            ;
        if(i >= j)
            break;
        Swap(arr, i, j);
    }
    Swap(arr, i, right);
    return i;
}

void QuickSort(int *arr, int left, int right)
{
    if(left <= right)
    {
        int i = Partation(arr, left, right);
        QuickSort(arr, left, i-1);
        QuickSort(arr, i+1, right);
    }
}

int main(int argc, char const *argv[])
{
    int arr[N] = {0};
    srand((unsigned int)time(NULL));
    for(int i=0; i<N; i++)
    {
        arr[i] = rand()%100+1;
    }
    DispArr(arr, N);

    QuickSort(arr, 0, N-1);

    DispArr(arr, N);

    return 0;
}
