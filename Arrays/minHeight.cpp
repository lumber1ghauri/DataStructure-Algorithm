#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumHeight(vector<int> &arr, int k)
{

    // ye logic flawed hai
    //     int n = arr.size();
    //    // sort(arr.begin() , arr.end());
    //     vector<int> resultant ;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] > 0)
    //         {
    //             if (i < n / 2)
    //             {
    //                 arr[i] += k;
    //                 resultant.push_back(arr[i]);
    //             }
    //             else
    //             {
    //                 arr[i] -= k;
    //                 resultant.push_back(arr[i]);
    //             }
    //         }
    //     }
    //     cout <<"resultant : " ;
    //     for(int i = 0 ; i<resultant.size(); i++)
    //     {
    //         cout << resultant[i] << " "  ;
    //     }cout << endl;
    //     int biggest = arr[0];
    //     int smallest = arr[0];
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] > 0)
    //         {
    //             if (arr[i] > biggest)
    //             {
    //                 biggest = arr[i];
    //             }
    //             else if (arr[i] < smallest)
    //             {
    //                 smallest = arr[i];
    //             }
    //         }
    //     }
    //     int res = biggest - smallest;
    //     return res;


    // smj hi ni ai

    // int n = arr.size();
    // sort(arr.begin(), arr.end());
    // int ans = arr[n - 1] - arr[0];
    // int smallest = arr[0] + k;

    // int largest = arr[n - 1] - k;
    // int max = 0, minimum = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (smallest < arr[i + 1] - k)
    //     {
    //         minimum = smallest;
    //     }
    //     else
    //     {
    //         minimum = arr[i + 1] - k;
    //     }

    //     if (largest > arr[i + 1] + k)
    //     {
    //         max = largest;
    //     }
    //     else
    //     {
    //         max = arr[i + 1] + k;
    //     }

    //     if (minimum < 0)
    //         continue;
    //     int result = max - minimum;
    //     ans = min(ans, result);

        
    // }
    // return ans;



    int n =arr.size();
    sort(arr.begin() , arr.end());
    int result= arr[n-1] - arr[0];
    for(int i = 1 ; i< n ; i++)
    {
    if(arr[i]-k<0)
    {
        continue;
    }

    int minH=min(arr[0]+k , arr[i]-k);
    int maxH=max(arr[i-1]+k , arr[n-1]-k);
    result = min (result , maxH-minH);
    }
    return result;
}

int main()
{
    vector<int> arr = {4, -10, -2, -8, 2, 3};
    int result = minimumHeight(arr, 3);
    cout << result;
    return 0;
}