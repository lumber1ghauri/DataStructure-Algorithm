#include <iostream>
#include <string>
using namespace std;

bool validInteger(string s)
{
    if (s.empty())
    {
        return false;
    }
    int i = 0;
    // Skip leading spaces
    while (i < s.length() && s[i] == ' ')
        i++;

    // Check for optional sign
    if (i < s.length() && (s[i] == '+' || s[i] == '-')) 
    {
        i++;
    }

    // If after skipping spaces and handling the sign, we have nothing left (only spaces)
    if (i == s.length())
        return false;

    // Check if all remaining characters are digits
    for (int j = i; j < s.length(); j++)
    {
        if (s[j] < '0' || s[j] > '9')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string input = "     -12";

    if (validInteger(input))
    {
        cout << "Valid Integer" << endl;
    }
    else
    {
        cout << "Invalid Integer" << endl;
    }

// ye code saari test cases ko handle ni krta

    return 0;
}
