#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minRemoval(vector<vector<int>> &arr)
{
    if (arr.empty())
        return 0;

    sort(arr.begin(), arr.end());

    int count = 0;
    int end = arr[0][1];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i][0] < end)
        {
            count++;
            end = min(end, arr[i][1]);
        }
        else
        {
            end = arr[i][1];
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> testCase1 = {{1, 2}, {5, 10}, {18, 35}, {40, 45}};
    vector<vector<int>> testCase2 = {{1, 3}, {1, 3}, {1, 3}};
    vector<vector<int>> testCase3 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << "Test Case 1 (No Overlap): " << minRemoval(testCase1) << " removals" << endl;
    cout << "Test Case 2 (All Overlapping): " << minRemoval(testCase2) << " removals" << endl;
    cout << "Test Case 3 (Some Overlapping): " << minRemoval(testCase3) << " removals" << endl;

    return 0;
}
