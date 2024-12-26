
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mergeArrays(vector<int> &a, vector<int> &b)
{
    int i = a.size()-1; 
    int j = 0 ;
    while (i>=0 && j < b.size() && a[i] > b[j])
    {
        swap(a[i] , b[j]);
        j++;
        i--;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}   

int main()
{
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele : a)
        cout << ele << " ";
    cout << "\n";
    for (int ele : b)
        cout << ele << " ";
    return 0;
}