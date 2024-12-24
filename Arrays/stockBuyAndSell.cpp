#include <iostream>
#include <vector>
using namespace std;

int stockBuyAndSell(vector<int> arr)
{
    int buy = 0;
    int sell = 0;
    int profit = 0;
    for(int i =0 ; i<arr.size()-1; i++)
    {

        if(arr[i+1] > arr[i])
        {
            buy = arr[i];
            sell = arr[i+1];
            profit+=sell - buy;
        }
    }
    return profit;
}
int main ()
{
    vector<int> arr= {4, 2, 2, 2, 4};
    int profit = stockBuyAndSell(arr);
    cout << profit;
}