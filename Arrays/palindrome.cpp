#include <bits/stdc++.h>
using namespace std ;
bool isPalindrom(int x)
{
    if(x<0)
    return false;
    int temp = x;
    int reverse = 0;

    while(temp!=0)
    {
        reverse = reverse*10 + temp%10;
        temp /= 10;
    }
    return x == reverse;
}
int main() {
    return 0;
}