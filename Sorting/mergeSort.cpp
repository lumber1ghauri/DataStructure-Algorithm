#include <iostream>
#include <vector>
#include <string>
using namespace std;  
void merging(vector<int> &arr, int left, int mid, int right)
{
    vector<int> merged(right - left + 1);
    int idx1 = left;
    int idx2 = mid + 1;
    int x = 0;
    while (idx1 <= mid && idx2 <= right)
    {
        if (arr[idx1] <= arr[idx2])
        {
            merged[x++] = arr[idx1++];
        }
        else
        {
            merged[x++] = arr[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        merged[x++] = arr[idx1++];
    }
    while (idx2 <= right)
    {
        merged[x++] = arr[idx2++];
    }
    for (int i = 0; i < merged.size(); i++)
    {
        arr[left+i] = merged[i];
    }
}
void mergeSort(vector<int> &arr, int left, int right)
{
    int n = arr.size();
    int mid = left + (right - left) / 2;
    if (left >= right)
    {
        return;
    }
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merging(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {3, 1, 2, 4, 9, 56, 76, 788, 234, 236, 35, 31, 2, 7, 8, 9, 10};
    mergeSort(arr , 0 , arr.size() -1);
    for(int i = 0 ; i <arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}