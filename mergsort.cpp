#include<iostream>
using namespace std;


void Merge(int A[], int start, int mid, int end)
{

    int i = start, j = mid + 1, k = start;
    int B[100];
    while (i <= mid && j <= end)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else 
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= end; j++)
        B[k++] = A[j];
    for (i = start; i <= end; i++)
        A[i] = B[i];
}

void MergeSort(int A[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        MergeSort(A, start, mid);
        MergeSort(A, mid + 1, end);
        Merge(A, start, mid, end);
    }
     
}

int main()
{
    cout<<"UTSAV POUDEL 21BDS0384 || enter the size of the array = ";
    int size;
    cin>>size;
    int arr[size];
    int start = 0 ;
    int end = size-1;
    for(int i=0;i<size;i++){
        cout<<"UTSAV POUDEL 21BDS0384 || Enter the element = ";
        cin>>arr[i];
    }
    
    MergeSort(arr,start,end);
    cout<<"UTSAV POUDEL 21BDS0384 ||  the sorted array is : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    return 0; 
}
