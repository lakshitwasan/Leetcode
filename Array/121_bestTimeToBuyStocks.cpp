#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> arr)
{
    int min_price = arr[0];
    int max_Profit = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        max_Profit = max(max_Profit, arr[i] - min_price);
        min_price = min(arr[i], min_price);
    }

    return max_Profit;
}

int main()
{

    vector<int> arr = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(arr);

    cout << ans << endl;
    return 0;
}