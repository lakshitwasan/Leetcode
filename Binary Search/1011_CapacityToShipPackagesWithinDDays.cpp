#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int findDays(vector<int> weights, int capacity)
{
    int days = 1;
    int load = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > capacity)
        {
            days = days + 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }

    return days;
}

int leastWeigthCapacity_Linear(vector<int> weights, int days)
{
    int maxWeight = *max_element(weights.begin(), weights.end());
    int sumWeight = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxWeight; i <= sumWeight; i++)
    {
        if (findDays(weights, i) <= days)
        {
            return i;
        }
    }

    return -1;
}

int leastWeigthCapacity_BS(vector<int> weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (findDays(weights, mid) <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{

    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;

    // int ans = leastWeigthCapacity_Linear(weights, days);
    int ans = leastWeigthCapacity_BS(weights, days);

    cout << ans;

    return 0;
}