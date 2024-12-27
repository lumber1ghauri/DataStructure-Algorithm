#include <iostream>
#include <vector>
using namespace std;
int searchInRotatedSortedArray(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = searchInRotatedSortedArray(nums, target);

    if (result != -1)
    {
    cout << "Element found at index " << result << std::endl;
    }
    else
    {
        cout << "Element not found" << std::endl;
    }

    return 0;
}