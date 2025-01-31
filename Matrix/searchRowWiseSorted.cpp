#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool searchRowMatrix(vector<vector<int>> &mat, int x)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] <= x && mat[i][m - 1] >= x)
        {
            int l = 0, r = m - 1;
            while (l <= r)
            {
                int mid = r - (r - l) / 2;
                if(mat[i][mid] ==x)
                {
                    return true;
                }
                else if (mat[i][mid] <x)
                {
                    l = mid + 1;
                }
                else 
                {
                    r = mid -1;
                }
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};
    int x = 5;
    cout << searchRowMatrix(matrix, x) << endl;

    return 0;
}