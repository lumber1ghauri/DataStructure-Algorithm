#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int smallestMissing(vector <int> &arr)
{
    sort(arr.begin() , arr.end());
    int n = arr.size();
    int res = 1;
    for(int i =0 ; i<n ; i++)
    {
        if(arr[i]==res)
        {
            res+=1;
        }
        if (arr[i] > res)
        {
            break;
        }
    }
    return res;
}
int main()
{
    vector<int> arr={-8, 0, -1, -4, -3};
    cout << smallestMissing(arr);
    return 0;
}