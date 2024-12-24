#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nextPermutation(vector<int> &arr)
{
    // next_permutation(arr.begin(), arr.end());

    //     for (int i = arr.size()-1; i > 0; i--)
    //     {
    //         if (arr[i] > arr[i - 1])
    //         {
    //             swap(arr[i], arr[i - 1]);
    //             for (int i = 0; i < arr.size(); i++)
    //             {
    //                 cout << arr[i] << " ";
    //             }
    //             cout << endl;
    //        }
    //    }

    // int ind = -1;
    // int n = arr.size();
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     if (arr[i] < arr[i + 1])
    //     {
    //         ind = i;
    //         break;
    //     }
    // }
    // if (ind == -1)
    // {
    //     reverse(arr.begin(), arr.end());
    //     return arr;
    // }
    // for (int i = n - 1; i > ind; i--)
    // {
    //     if (arr[i] > arr[ind])
    //     {
    //         swap(arr[i], arr[ind]);
    //         break;
    //     }
    // }
    // reverse(arr.begin()+ind+1 , arr.end());

    int index= -1;
    int n = arr.size();
    for(int i= n-2; i>=0 ; i--)
    {
        if(arr[i] < arr[i+1])
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for(int i=n-1 ; i>index; i--)
    {
        if(arr[i]>arr[index])
        {
            swap(arr[i] , arr[index]);
            break;
        }
    }
    reverse(arr.begin()+index+1 , arr.end());
}
int main()
{
    vector<int> arr = {1,2,3};
    int n = arr.size() ; 
    cout << n << endl;
    for (int i = 0; i < 6; i++)
    {
        nextPermutation(arr);
        for (int j = 0; j < arr.size(); j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}