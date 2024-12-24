#include <iostream>
#include <vector>
using namespace std;
int zeroAtEnd(vector<int> &arr)
{
    // time complexity O(n) space O(n)


    int n = arr.size();
    // vector<int> temp(n);
    // int j = 0;
    // for(int i = 0; i < n; i++)
    // {
    //     if(arr[i] != 0)
    //     {
    //         temp[j++] = arr[i];
    //     }
    // }
    // while (j<n)
    // {
    //     temp[j++] = 0;
    // }
    // for(int i=0 ; i<n; i++)
    // {
    //     arr[i] = temp[i];
    //     cout << arr[i] << " ";
    // }

    //time complexity O(n) space o(1)
    // int count = 0 ;
    // for (int i=0 ; i<n ; i++)
    // {
    //     if(arr[i] != 0)
    //     {
    //         arr[count++] = arr[i];
    //     }
    // }
    //  while (count < n )
    //     {
    //         arr[count++] = 0;
    //     }
    // for (int i=0 ; i<n ; i++)
    // {
    //     cout << arr[i] << " " ;
    // }


    // third approach time complexity O(n) space o(1)

    int count = 0 ;
    for ( int i = 0 ; i <n ; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[count++]);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr [ i ] << " " ;
    }
}
int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    zeroAtEnd(arr);

    return 0;
}