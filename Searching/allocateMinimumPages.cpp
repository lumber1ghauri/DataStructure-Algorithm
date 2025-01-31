#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isValid(vector<int> &arr, int n, int k, int mid)
{
    int stu = 1;
    int pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (pages + arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            stu++;
            pages = arr[i];
        }
    }
    return stu > k ? false : true;
}
int allocateMinimumPages(vector<int> &arr, int k)
{

    int n = arr.size();
    if (k > n)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int ans = -1;
    int st = 0;
    int end = sum;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k =2; 
    cout << allocateMinimumPages(arr, k);

    return 0;
}