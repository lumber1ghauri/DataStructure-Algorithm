#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool left = true;
        bool right = true;

        if (i > 0 && arr[i] <= arr[i - 1])
        {
            left = false;
        }

        if (i < n - 1 && arr[i] <= arr[i + 1])
        {
            right = false;
        }

        if (left && right)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    cout << peakElement(arr);
    return 0;
}