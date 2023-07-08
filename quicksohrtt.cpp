#include <iostream>
using namespace std;
  
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}
  
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
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
    quickSort(arr,start,end);

    cout<<"UTSAV POUDEL 21BDS0384 ||  the sorted array is : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    return 0; 
}
