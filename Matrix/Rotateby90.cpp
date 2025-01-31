#include <iostream>
#include <vector>
#include <string>
using namespace std;
void rotateby90(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(mat[i][j], mat[n - i - 1][j]);
        }
    }
}
void printMatrix(const vector<vector<int>> &mat)
{
    for (const auto &row : mat)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 3;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    printMatrix(mat);
    rotateby90(mat);
    cout << "Rotated Matrix:\n";
    printMatrix(mat);

    return 0;
}