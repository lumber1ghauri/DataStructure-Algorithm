#include <iostream>
using namespace std;

class NQueen
{
private:
    int N;
    int *board;
    bool isSafe(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
            {
                return false;
            }
        }
        return true;
    }
    
    bool solve(int row)
    {
        if (row == N)
        {
            printSolution();
            return true;
        }

        bool foundSolution = false;
        for (int col = 0; col < N; col++)
        {
            if (isSafe(row, col))
            {
                board[row] = col;
                foundSolution = solve(row + 1) || foundSolution;
            }
        }
        return foundSolution;
    }

public:
    NQueen(int n)
    {
        N = n;
        board = new int[N];
    }

    ~NQueen()
    {
        delete[] board;
    }

    void solveNQueens()
    {
        if (!solve(0))
        {
            cout << "No solution exists for " << N << " queens." << endl;
        }
    }

    void printSolution()
    {
        static int solutionCount = 1;
        cout << "Solution " << solutionCount++ << ":" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i] == j)
                {
                    cout << " Q ";
                }
                else
                {
                    cout << " . ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Please enter a positive number : ";
        cin >> n;
    }
    NQueen queenSolver(n);
    queenSolver.solveNQueens();
    return 0;
}
