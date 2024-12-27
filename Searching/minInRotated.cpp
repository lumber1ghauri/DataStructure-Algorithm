#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//time complexity O(nlogn) and space O(1)
// int minRotatedArray(vector <int> &arr)
// {
//     sort(arr.begin(), arr.end());
//     return arr[0];
// }


// time complexity O(logn) and space O(1)
int minRotatedArray(vector <int> &arr)
{
    int n = arr.size();
    int low = 0 ; int high = n -1;
    while (low < high)
    {
        if(arr[low]<arr[high])
        {
            arr[low];
        }
        int mid = low + (high - low)/2;
        if(arr[mid] > arr[high])
        {
            low = mid+1;
        }
        else 
        {
            high = mid;
        }
        
    }
    return arr[low];
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element in the give array : " << minRotatedArray(arr);
    return 0;
}