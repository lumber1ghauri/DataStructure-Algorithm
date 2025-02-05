#include <bits/stdc++.h>
using namespace std;

int countTwoSumPairs(vector<int> &nums, int target) {
    int count = 0;
    unordered_map<int, int> hashTable;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if complement exists and is not double-counted
        if (hashTable.find(complement) != hashTable.end() && hashTable[complement] > 0) {
            count++;
            hashTable[complement]--;  // Decrease count to avoid double counting
        } else {
            hashTable[nums[i]]++;  // Store the current number in the map
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 5, 7, -1, 5};
    int target = 6;
    cout << countTwoSumPairs(nums, target) << endl;
    return 0;
}
