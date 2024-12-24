#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int stockBuyAndSell(vector<int> arr)
{
    int buy_price = arr[0];
    int profit=0;
    for(int i=1 ; i <arr.size() ; i++)
    {
        if(arr[i] < buy_price)
        {
            buy_price = arr[i];
        }
        else{
            int current_profit = arr[i] - buy_price;
            profit = max(current_profit , profit);
        }
    }
    return profit;
}
int main()
{
    vector<int> arr = {7, 10, 1, 3, 6, 9, 2};
    int profit = stockBuyAndSell(arr);
    cout << profit << endl;
}