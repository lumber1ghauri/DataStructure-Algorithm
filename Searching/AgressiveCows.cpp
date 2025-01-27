#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool isPossible(vector<int> &arr , int k , int mid)
{
    int cows =1;
    int lastPos = arr[0];
    for(int i = 1 ; i<arr.size(); i++)
    {
        if(arr[i]-lastPos >= mid)
        {
            cows++;
            lastPos = arr[i];
        }

        if(cows == k)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin() , arr.end());//nlogn
    int st =1 , end = arr[arr.size()-1] - arr[0];
    int ans = -1;
    while(st <= end)
    {//0(log(range)*N)
        int mid = st + (end - st)/2;
        if(isPossible(arr , k , mid))
        {
            ans = mid;
            st = mid +1;
        }
        else 
        {
            end = mid -1;
        }
    }
    return ans;

}

int main()
{ 
    int C = 3;
    vector<int> arr= {1, 2, 8, 4, 9};
    cout << aggressiveCows(arr , C) << endl;

    return 0;
}