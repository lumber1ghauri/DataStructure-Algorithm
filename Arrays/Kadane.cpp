#include <iostream>
#include <vector>
using namespace std;
int kadane(vector <int> &arr)
{
    int sum=0;
    int new_sum = -50000000;
    int n = arr.size();
    int totalArraySum = 0;
    for(int i = 0 ; i<n; i++)
    {
        totalArraySum+=arr[i];
        sum+=arr[i];
        if(sum>new_sum)
        {
            new_sum=sum;
        }
        if(sum<0)
        {
            
            sum=0;
        }
    }
    cout << "total Array sum : " << totalArraySum << endl;
     return new_sum;
}
int main()
{
    vector <int> arr={10, -3, -4, 7, 6, 5, -4, -1};
    cout << kadane(arr);
    return 0;
}