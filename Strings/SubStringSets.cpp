#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> subString(string s)
{
    vector<string> result={""};
    string currNumber = "";
    for(int i =0 ; i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            currNumber+=s[i];
        }
        else
        {
            result.push_back(currNumber);
            currNumber="";
        }
    }
    if(!currNumber.empty())
    {
        result.push_back(currNumber);
    }
    return result;
}

int main()
{
    string input = "===1234  +a1b2=0987hkj.,,c3245";
    vector<string> subStrings = subString(input);
    for(const string &num : subStrings)
    {
        cout<< num<< " " ;
    }

    return 0;
}