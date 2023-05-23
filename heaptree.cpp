// C program for building Heap from Array
 
#include <stdio.h>
 
void swap(int *a, int *b)
{
    int tmp = *a;
      *a = *b;
      *b = tmp;
}

void insert(int arr[], int N, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
  
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    
    if (r < N && arr[r] > arr[largest])
        largest = r;
 

    if (largest != i) {

        swap(&arr[i], &arr[largest]);
 
        
        insert(arr, N, largest);
    }
}

void buildHeap(int arr[], int N)
{
    
    int start = (N / 2) - 1;
 

    for (int i = start; i >= 0; i--) {
        //heapify(arr, N, i);
    }
}

void displayHeap(int arr[], int N)
{
    printf("Array representation of Heap is:\n");
 
    for (int i = 0; i < N; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}

void deleteRoot(int arr[], int& n)
{
    
    int lastElement = arr[n - 1];
 
   
    arr[0] = lastElement;
 
    
    n = n - 1;
 
    insert(arr, n, 0);
}

int main()
{

    int arr[] = {5, 7, 9, 15, 3, 10, 0, 2, 8, 45, 18};
 
    int N = sizeof(arr) / sizeof(arr[0]);
 
   
    buildHeap(arr, N);
    displayHeap(arr, N);

    deleteRoot(arr,N);
   
    return 0;
} 


