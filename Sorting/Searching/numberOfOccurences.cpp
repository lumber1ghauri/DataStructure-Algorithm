#include <iostream>
#include <vector>

using namespace std;

int firstOccurrenceElement(const vector<int> &arr, int left, int right, int target)
{
    if (left > right) 
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        int firstLeft = firstOccurrenceElement(arr, left, mid - 1, target);
        return (firstLeft == -1) ? mid : firstLeft;
    }
    else if (arr[mid] > target)
    {
        return firstOccurrenceElement(arr, left, mid - 1, target);
    }
    else
    {
        return firstOccurrenceElement(arr, mid + 1, right, target);
    }
}
int lastOccurenceElement(const vector<int> &arr, int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        int firstRight = lastOccurenceElement(arr, mid + 1, right, target);
        return (firstRight == -1) ? mid : firstRight;
    }
    else if (arr[mid] > target)
    {
        return lastOccurenceElement(arr, left, mid - 1, target);
    }
    else
    {
        return lastOccurenceElement(arr, mid + 1, right, target);
    }
}
int freq(const vector<int> &arr, int target)
{
    int first = firstOccurrenceElement(arr, 0, arr.size() - 1, target);
    int last = lastOccurenceElement(arr, 0, arr.size() - 1, target);

    if (first == -1 || last == -1)
        return 0;

    return last - first + 1;
}
int main()
{
    vector<int> arr = {0, 1, 2, 2, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int result = firstOccurrenceElement(arr, 0, arr.size() - 1, target);
    cout << "Result: " << result << endl;

    return 0;
}
