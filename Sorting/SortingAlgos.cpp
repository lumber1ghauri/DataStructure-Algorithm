#include <iostream>
#include <vector>
#include <string>
using namespace std;
void bubbleSort(int arr[], int size)
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        // bool isSwap = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                //   isSwap = true;
            }
            // if(!isSwap)
            // {
            //     return;
            // }
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
int main()
{
    int arr[] = {0, 1, 0, 2, 0, 1, 1, 1, 1, 2, 1, 2, 0, 0, 2};
    insertionSort(arr, 15);
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}