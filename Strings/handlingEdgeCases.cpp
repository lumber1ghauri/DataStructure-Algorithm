#include <iostream>
#include <string>
#include <climits>
using namespace std;

int stringToInt(string s)
{
    int num = 0;
    int sign = 1;
    int i = 0;

    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    while (i < s.length() && s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;
        i++;
    }

    return sign * num;
}

int main()
{
    string s1 = "-123";
    string s2 = "  -";
    string s3 = "1231231231311133";
    string s4 = "-999999999999";

    cout << stringToInt(s1) << endl;
    cout << stringToInt(s2) << endl;
    cout << stringToInt(s3) << endl;
    cout << stringToInt(s4) << endl;

    return 0;
}
