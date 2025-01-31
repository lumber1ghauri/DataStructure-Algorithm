#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool matSearch(vector<vector<int>> &mat, int x)
{
    // your code here
    int n = mat.size();
    if (n == 0)
        return false;

    int m = mat[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (mat[row][col] == x)
        {
            return true;
        }
        else if (mat[row][col] > x)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}
int main()
{

    return 0;
}