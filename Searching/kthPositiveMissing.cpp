#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findKthMissingPositive(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int missing_count = arr[mid] - (mid + 1);

        if (missing_count < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return k + left;
}

int main()
{
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << findKthMissingPositive(arr1, k1);

    return 0;
}