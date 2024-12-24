#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isValidChar(char c) {
    return (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ');
}

bool isValidInput(const string& s) {
    int n = s.length();
    
    // Input cannot be empty
    if (n == 0) return false;

    // Check if the string contains any invalid characters
    for (int i = 0; i < n; i++) {
        if (!isValidChar(s[i])) {
            return false;
        }
    }

    // Check if the string has proper operator placement
    for (int i = 0; i < n; i++) {
        if ((i == 0 || i == n - 1) && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) {
            return false; // Operators at the beginning or end are not allowed
        }
        if (i > 0 && (s[i] == s[i - 1]) && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) {
            return false; // Consecutive operators are not allowed
        }
    }

    return true;
}

int calculate(string s) {
    stack<int> stk;
    int num = 0;
    char op = '+'; // Start with a '+' as default operation
    int n = s.length();

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // Build the current number (multi-digit support)
        }

        // When we encounter an operator or reach the end of the string, process the number
        if ((!isdigit(ch) && ch != ' ') || i == n - 1) {
            if (op == '+') {
                stk.push(num);
            } else if (op == '-') {
                stk.push(-num);
            } else if (op == '*') {
                int top = stk.top();
                stk.pop();
                stk.push(top * num);
            } else if (op == '/') {
                int top = stk.top();
                stk.pop();
                stk.push(top / num);  // Integer division
            }

            // Update the operator and reset the number
            op = ch;
            num = 0;
        }
    }

    // Sum up all values in the stack
    int result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    return result;
}

int main() {
    string input = "   3+ 2 * 2";  // Try changing this to test invalid inputs

    if (!isValidInput(input)) {
        cout << "Invalid input!" << endl;
    } else {
        cout << "Result: " << calculate(input) << endl;
    }

    return 0;
}
