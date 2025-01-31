#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int x)
{
    // code here
    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = n * m - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int midElement = mat[mid / m][mid % m];
        if (midElement == x)
        {
            return true;
        }
        else if (midElement < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 137, 148},
        {232, 233, 239, 250}};
    int x = 137;
    cout << "Element found : " << searchMatrix(matrix, x);
    return 0;
}