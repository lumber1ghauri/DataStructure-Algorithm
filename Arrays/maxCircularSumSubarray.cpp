#include <iostream>
#include <vector>
using namespace std;
int circularSumSubarray(vector<int> &arr)
{
    int sum = 0;
    int new_sum = -50000000;
    int n = arr.size();
    int totalArraySum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > new_sum)
        {
            new_sum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    for(int i=0 ; i<n ; i++)
    {
         totalArraySum += arr[i];
    }
    int secondSum = 0;
    int newSecondSum = 500000000;
    for (int i = 0; i < n; i++)
    {
        secondSum += arr[i];
        if (secondSum<newSecondSum)
        {
            newSecondSum = secondSum;
        }
        if (secondSum > 0)
        {
            secondSum = 0;
        }
    }
   int circularSum = totalArraySum - newSecondSum;
    if(totalArraySum == newSecondSum)
    {
        return new_sum;
    }
    return max(circularSum, new_sum);
}
int main()
{
    vector<int> arr = {-1, 40, -14, 7, 6, 5, -4, -1};
    cout << circularSumSubarray(arr);
    return 0;
}