#include <bits/stdc++.h>
using namespace std ;
int removeElements(vector<int> &nums, int k )
{
    int n = nums.size();
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] != k)
        {
            nums[index++]=nums[i];
        } 
    }
    return index;
}
int main() 
{
    return 0;
}