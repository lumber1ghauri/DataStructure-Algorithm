#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>> &arr , vector<int> &newInterval)
{

    arr.push_back(newInterval);
    // Sort intervals based on start values
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        vector<int> &last = res.back();
        vector<int> &curr = arr[i];

        // If current interval overlaps with the last merged
        // interval, merge them
        if (curr[0] <= last[1])
            last[1] = max(last[1], curr[1]);
        else
            res.push_back(curr);
    }

    return res;
}

int main()
{
    vector<vector<int>> arr = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,9};
    vector<vector<int>> res = insertInterval(arr, newInterval);
    for(auto x : res)
    {
        for(auto y : x)
        {
            cout << y << " " ;
        }
        cout << endl;
    }

    return 0;
}
