#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getSecondLargest(vector<int> &arr)
{
    //Time complexity is o(nlogn)

    // int n = arr.size();
    // cout << n << endl;
    // sort(arr.begin() , arr.end());
    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " " ;
    // }
    // cout << endl;
    // for(int i = n-2 ; i>=0 ; i--)
    // {
    //     if(arr[i] != arr[n-1])
    //     {
    //         return arr[i];
    //     }
    //     else
    //     {
    //         return -1;
    //     }
    // }


    //time complexity O(n)


    // int n = arr.size();
    // int largest = 0;
    // for(int i =0 ; i<n ; i++)
    // {
    //     if(arr[i]> largest)
    //     {
    //         largest = arr[i];
    //     }
    // }
    // int secondLargest = -1;
    // for(int j=0 ; j<n ; j++)
    // {
    //     if(arr[j]>secondLargest && arr[j] !=largest)
    //     {
    //         secondLargest = arr[j];
    //     }
    // }
    // return secondLargest;

    // one pass approach time complexity
int n = arr.size();
int largest = -1; 
int secondLargest = -1;
    for (int i = 0 ; i <  n ; i++ )
    {
        if(arr[i]>largest )
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i]>secondLargest && arr[i] < largest )
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
int main()
{
    vector<int> arr = { 12, 35, 1, 10, 34, 1 };
    cout << getSecondLargest(arr) ;

    return 0;
}