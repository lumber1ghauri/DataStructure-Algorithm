#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int stringCalculator(string s)
{
    stack<int> stk;
    int num = 0;
    char op = '+';
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - '0');
        }
        if ((ch < '0' || ch > '9' && ch != ' ') || i == n - 1)
        {
            if (op == '+')
            {
                stk.push(num);
            }
            else if (op == '-')
            {
                stk.push(-num);
            }
            else if (op == '*')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top * num);
            }
            else if (op == '/')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top / num);
            }
            op = ch;
            num = 0;
        }
    }
    int result = 0;
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    return result;
}
int main()
{
    string s = "3+2*2";
    cout << "Result: " << stringCalculator(s) << endl; // Output: 7
    return 0;
}