#include <iostream>
#include <vector>
#include <string>
using namespace std;
string rotateString(string str)
{
    char lastChar = str.back();
    str.pop_back();
    str.insert(str.begin(), lastChar);
    return str;
}
bool areRotations(string &s1, string &s2)
{
    for (int i = 0; i < s1.length(); i++)
    {
        s2 = rotateString(s2);
        if (s1 == s2)
        {
            
            return true;
            break;
        }
    }
    return false;
}

//better approach from chatgpt

// bool areRotations(string &s1, string &s2)
// {
//     if (s1.length() != s2.length()) 
//         return false;
//     string concatenated = s1 + s1;
//     return concatenated.find(s2) != string::npos;
// }
int main()
{
    string s1 = "abcd";
    string s2 = "cdab";
    cout << areRotations(s1, s2) << endl;

    return 0;
}
