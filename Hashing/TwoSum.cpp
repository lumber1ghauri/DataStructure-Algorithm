#include <bits/stdc++.h>
using namespace std;
bool twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hashTable;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (hashTable.find(complement) != hashTable.end())
        {
            return true;
        }
        hashTable[nums[i]] = i;
    }
    return false;
}
int main()
{
    vector<int> nums = {10, 22, 30, 44, 55, 70, 90, 100, 110, 120, 130};
    int target = 500;
    cout << twoSum(nums, target) << endl;
    return 0;
}