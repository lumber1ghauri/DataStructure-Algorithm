// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;
// vector<vector<int>> mergingOverlap(vector<vector <int>> &arr)
// {
//     vector<vector<int>> res;
//     if(arr.size() == 0)
//     {
//         return res;
//     }
//     int n = arr.size();
//     sort(arr.begin() , arr.end());
//     for(int i =0 ; i<n ; i++)
//     {
//         int start = arr[i][0];
//         int end = arr[i][1];
//         if(!res.empty() && res.back()[1]>=start)
//         {
//             continue;
//         }
//         for(int j = i+1 ; j <n ; j++)
//         {
//             if(end>=arr[j][0])
//             {
//               end=max(end , arr[j][1]);
//             }
//         }
//         res.push_back({start , end});
//     }
//     return res;
// }
// int main()
// {
//     vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
//     vector<vector<int>> res = mergingOverlap(arr);
//     for(auto x : res)
//     {
//         for(auto y : x)
//         {
//             cout << y << " " ;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// C++ Code to Merge Overlapping Intervals by checking
// overlapping intervals only

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
{

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    res.push_back(arr[0]);
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        vector<int> &last = res.back();
        vector<int> &curr = arr[i];

        // If current interval overlaps with the last merged
        // interval, merge them
        if (curr[0] <= last[1])
        {
            last[1] = max(last[1], curr[1]);
            count += 1;
        }
        else
            res.push_back(curr);
    }

    return res;
}

int main()
{
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> res = mergeOverlap(arr);

    for (vector<int> &interval : res)
        cout << interval[0] << " " << interval[1] << endl;

    return 0;
}
