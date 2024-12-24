#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
char firstNonRepeating(string s)
{
    int count[26]={0};
    int index[26];
    for (int i = 0; i < 26; i++) {
        index[i] = INT_MAX;
    }
    for(int i = 0 ; i<s.length() ; i++)
    {
        int charIndex = s[i]-'a' ;
        count[charIndex]+=1;
        if(index[charIndex]==INT_MAX)
        {
            index[charIndex] = i ;
        }
    }
    int minIndex = INT_MAX;
    char result = '$';
    for(int i =0 ; i<26; i++)
    {
        if(count[i]==1 && index[i]<minIndex)
        {
            minIndex = index[i];
            result = (i+'a');
        }
    }
    if (result == '$')
    {
        return '$';
    }
    else 
    return result;
}
int main()
{
    string s = "hello";
    cout << firstNonRepeating(s);

    return 0;
}