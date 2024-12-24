#include <iostream>
#include <vector>
#include <string>
using namespace std;
// O(n^2) approach
//  int inversionCount(vector<int> &arr)
//  {
//      int n = arr.size();
//      int count = 0;
//      for (int i = 0; i < n - 1; i++)
//      {
//          for (int j = 0; j < n - 1 - i; j++)
//          {
//              if (arr[j] > arr[j + 1])
//              {
//                  swap(arr[j], arr[j + 1]);
//                  count++;
//              }
//          }
//      }
//      return count;
//  }
int mergeAndCount(vector<int> &arr, int left, int mid, int right)
{
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left, invCount = 0;

    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
            invCount += (mid + 1) - (left + i);
        }
    }

    while (i < leftArr.size())
    {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size())
    {
        arr[k++] = rightArr[j++];
    }

    return invCount;
}

int mergeSortAndCount(vector<int> &arr, int left, int right)
{
    int invCount = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int inversionCount(vector<int> &arr)
{
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    cout << "Inversion Count: " << inversionCount(arr) << endl;
    return 0;
}