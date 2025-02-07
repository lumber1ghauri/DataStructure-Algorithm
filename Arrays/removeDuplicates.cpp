#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    if (nums.empty()) return 0;

    int k = 1;  
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = removeDuplicates(nums);

    // Print the updated array with unique elements
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << "\nUnique count: " << n << endl;

    return 0;
}
