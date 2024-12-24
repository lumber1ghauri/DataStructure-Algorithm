#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {

        // If characters at the ends are not equal, it's not a palindrome
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minChar(string &s)
{
    int cnt = 0;
    int i = s.size() - 1;
    while (i >= 0 && !isPalindrome(s, 0, i))
    {

        i--;
        cnt++;
    }
    return cnt;
}
int main()
{
    // string str;
    // cout << "Enter a string: ";
    // cin >> str;

    // int result = minCharToAdd(str);
    // cout << "Minimum characters to add: " << result << endl;

    // return 0;
    string s = "aaceaaaa";
    cout << minChar(s) << endl;
}

// int minCharToAdd(string s) {
//     // Function implementation goes here
//    string reversed = s;
//    reverse(reversed.begin() , reversed.end());
//    int n = s.length();
//    for(int i = n ; i>=0 ; i--)
//    {
//     if(s.substr(i) == reversed.substr(n-i , 0))
//     {
//         return i ;
//     }
//    }

//     return n-1;
// }