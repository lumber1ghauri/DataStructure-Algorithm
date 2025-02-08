#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size()==0)
    return "";
    string prefix = strs[0];
    for(int i = 1; i < strs.size(); i++)
    {
        string s = strs[i];
        int j = 0;
        while(j < prefix.length() && j < s.length() && prefix[j] == s[j])
        {
            j++;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}
int main()
{
    vector<string> strs = {"dog","racecar","car"};
    string ans = longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}