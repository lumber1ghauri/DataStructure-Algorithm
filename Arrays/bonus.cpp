#include <iostream>
#include <vector>
#include <string>
using namespace std;
int singleDigit(int n)
{
    // code here
    while (n >= 10)
    {
        int sum = 0;
        while(n>0)
        {
        sum += n % 10;
        n /= 10;
        }
        n =sum;
    }
    return n;
}
int main()
{
   cout << singleDigit(1234);

    return 0;
}