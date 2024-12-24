#include <iostream>
#include <vector>
using namespace std;

int arrayReverse(vector<int> &arr)
{
    // time and space O(n)

    int n = arr.size();
    //     vector<int> arr2 (n);
    //     int count = 0;
    //     for(int i = n-1 ; i>=0 ; i--)
    //     {
    //         arr2[count++] = arr[i];
    //     }
    //    // cout << endl;
    //     for(int i =0; i < n ; i++ )
    //     {
    //         cout << arr2[i] << " " ;
    //     }

    // time and space O(N) , O(1)
    // int left =0 , right = arr.size()-1;
    // while  (left < right)
    // {
    //     swap(arr[left] , arr[right]);
    //     left++;
    //     right--;
    // }
    // for (int i = 0 ; i<arr.size() ; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // time and space only half of n  and O(1)

    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
    for (int i = 0 ; i<arr.size() ; i++)
     {
        cout << arr[i] << " ";
     }
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7};
    arrayReverse(arr);

    return 0;
}