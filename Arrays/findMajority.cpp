#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// MOORE'S ALGORITHM
vector<int> findMajority(vector<int> &arr)
{
    int elem1 = -1, elem2 = -1, count1 = 0, count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (elem1 == arr[i])
        {
            count1++;
        }
        else if (elem2 == arr[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            elem1 = arr[i];
            count1++;
        }
        else if (count2 == 0)
        {
            elem2 = arr[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> res;
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (elem1 == arr[i])
        {
            count1++;
        }
        if (elem2 == arr[i])
        {
            count2++;
        }
    }

    if (count1 > arr.size() / 3)
    {
        res.push_back(elem1);
    }
    if (count2 > arr.size() / 3 && elem1 != elem2)
    {
        res.push_back(elem2);
    }
    if (res.size() == 2 && res[0] > res[1])
    {
        swap(res[1], res[0]);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5};

    vector<int> result = findMajority(arr);
    for (int element : result)
    {
        cout << element << " ";
    }
    return 0;
}
