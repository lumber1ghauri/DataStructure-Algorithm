#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArray(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    if (d <= 0)
    {
        d += n+1;
    }

    // time complexity O(n) and space O(n)
    // vector<int> temp(n);
    // int count =0 ;
    // for (int i = d ; i < n ; i++)
    // {
    //     temp[count++] = arr[i];
    // }
    // int count2 = 0 ;
    // for(int i = (n-d); i < n ; i++)
    // {
    //     temp[i] = arr[count2++];
    // }
    // for (int i = 0 ; i <n ; i++)
    // {
    //     arr[i] = temp[i];
    // }
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // int n = arr.size();

    // time complexity O(n*d) and space (1)
    // for (int i = 0; i < d; i++)
    // {
    //     int first = arr[0];
    //     for (int j = 0; j < n - 1; j++)
    //     {
    //         arr[j] = arr[j + 1];
    //     }
    //     arr[n - 1] = first;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // time complexity O(n) and O(1)

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    rotateArray(arr, -3);
    return 0;
}