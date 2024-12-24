#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> fizzBuzz (int n )
{
    vector<string> result;
    for(int i = 1; i <=n ; i++)
    {
        if(i%3==0 && i%5==0)
        {
            result.push_back("FizzBuzz");
        }
        else if(i%3 ==0 )
        {
            result.push_back("Fizz");
        }
        else if(i%5 ==0)
        {
            result.push_back("Buzz");
        }
        else 
        {
            result.push_back(to_string(i));
        }
    }
    return result;
}
int main()
{
    vector <string> print;
    print = fizzBuzz(20);
    for(int i = 0 ; i<20 ; i++)
    {
        cout << print[i] << " " ; 
    }
    return 0;
}