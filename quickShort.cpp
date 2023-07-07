#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int piviot = arr[start];
    int pindex = start;

    for (int i = start; i < end - 1; i++)
    {
        if (arr[i] <= piviot)
        {
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pindex], arr[end]);
    return pindex;
}

void quickShort(int arr[], int start, int end)
{

    if(start<end)
    {
        int pindex = partition(arr, start, end);
        quickShort(arr, start, pindex - 1);
        quickShort(arr, pindex + 1, end);
    }
}
int main()
{

    cout << "Enter the size of the array = ";
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element = ";
        cin >> arr[i];
    }
    int start = 0;
    int end = size - 1;


    quickShort(arr, start, end);

    cout << "the sorted array is : ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<"\t";
    }
}
