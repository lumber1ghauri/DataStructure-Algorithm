#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool anagram(string &s1 , string &s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1==s2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int main()
{
    string s1 = "uasha";
    string s2 = "ashauk";
    cout << anagram(s1 , s2);

    return 0;
}