#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<int> &arr)
{
    // not working 



    // int n = arr.size();
    // int maxi = 1;
    // int mini = 1;
    // int overallMax = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > 0)
    //     {
    //         maxi *= arr[i];
    //         mini *= arr[i];
    //         mini = min(mini, 1);
    //     }
    //     else if (arr[i] == 0)
    //     {
    //         maxi = 1;
    //         mini = 1;
    //     }
    //     else
    //     {
    //         maxi = max(mini * arr[i], 1);
    //         mini =  maxi * arr[i];
    //     }
    //     overallMax = max(overallMax, maxi);
    // }
    // return overallMax;

//time complexity O(n^2) space O(1);

    // int n = arr.size();
    // int overallMax=arr[0];
    // for(int i = 0 ; i<n ; i++)
    // {
    //     int product = 1;
    //     for(int j = i ; j<n; j++)
    //     {
    //         product*= arr[j];
    //         overallMax=max(overallMax , product);
    //     }
    // }
    // return overallMax;


    //optimized solution

    int n = arr.size();
    int maxi = 1 , mini = 1;
    int overall= arr[0];
    for(int i=0; i <n ; i++)
    {
        if(arr[i] < 0)
        swap(mini , maxi);

        maxi=max(arr[i]  , arr[i]*maxi);
        mini=min(arr[i] , arr[i]*mini);

        overall=max(overall, maxi);
    }
    return overall;
}
int main()
{
    vector<int> arr = {-1, -3, -10, 0, 60};
    cout << maxProduct(arr);

    return 0;
}