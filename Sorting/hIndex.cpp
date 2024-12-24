#include <iostream>
#include <vector>
#include <string>
using namespace std;
// int hIndexes(vector<int> &arr)
// {
//     if (arr.size() == 0 || arr.empty())
//         return 0 ;
//     int hIndex = 0;
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         int checkVar = arr[i];
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] >= checkVar)
//             {
//                 count++;
//             }
//         }
//         if (count >= checkVar && checkVar > hIndex)
//         {
//             hIndex = checkVar;
//         }
//     }
//     return hIndex;
// }

int hIndex(vector<int> &citations) {

    int n = citations.size();
    vector<int> freq(n + 1);

    for (int i = 0; i < n; i++) {
        if (citations[i] >= n)
            freq[n] += 1;
        else
            freq[citations[i]] += 1;
    }
    int idx = n;
    
    int s = freq[n]; 
    while (s < idx) {
        idx--;
        s += freq[idx];
    }
    return idx;
}



int main()
{
    vector<int> arr = {0,0};
    cout << "H-Index: " << hIndex(arr) << endl;
    return 0; 
}