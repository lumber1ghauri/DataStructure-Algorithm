#include <iostream>
#include <string>
using namespace std;

int main()
{
    //    string s = "12345";
    //    int num =0 ;
    //    for(int i= 0 ; i<s.length() ; i++)
    //    {
    //      num = s[i]-'0';
    //      sum+=num;
    //    }
    //    cout << sum;

    // string s2 = "hello world";
    // s2+=" How are u ? ";
    // string s3 = "Hi! ";
    // s3+=s2;
    // string sub = s2.substr(2, 2);
    // cout << s2;

    // string s4 = "a1b2c3d4f5";
    // string res = "";
    // for (char c : s4)
    // {
    //     if(c>='0' && c<='9')
    //     {
    //         res+=c;
    //     }
    // }
    // cout << res;

    //atoi function 

    // string s = " ===1234  +a7hkj245";
    // int result = 0;
    // int i = 0;
    // int sign = 1;
    // while (s[i] == ' ')
    // {
    //     i++;
    // }
    // if (s[i] == '-')
    // {
    //     sign = -1;
    //     i++;
    // }
    // else if (s[i] == '+')
    // {
    //     i++;
    // }
    // for (int j = i; j < s.length(); j++)
    // {
    //     if (s[j] >= '0' && s[j] <= '9')
    //     {
    //         result = result * 10 + (s[j] - '0');
    //     }
    // }
    // result *= sign;
    // cout << result;


    string s= "abcd1234";
    string reversed="";
    for(int i = s.length() ; i>=0; i--)
    {
        reversed+=s[i];
    }
    cout << reversed;
    return 0;
}