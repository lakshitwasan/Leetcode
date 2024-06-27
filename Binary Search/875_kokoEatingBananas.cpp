#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int biggestPile(vector<int> arr)
{
    int max = INT32_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

long long calculateTotalHours(vector<int> piles, int hour)
{
    long long totalHour = 0;
    int n = piles.size();

    for (int i = 0; i < n; i++)
    {
        totalHour += ceil((double)(piles[i]) / (double)(hour));
    }
    return totalHour;
}

int kokoEatingBananas_Linear(vector<int> piles, int h)
{

    // TIME COMPLEXITY: O(MAX(PILES) x N)

    int maxPile = biggestPile(piles);

    for (int i = 1; i <= maxPile; i++)
    {
        int reqTime = calculateTotalHours(piles, i);
        if (reqTime <= h)
        {
            return i;
        }
    }

    return -1;
}

int kokoEatingBananas_BS(vector<int> piles, int h)
{

    // TIME COMPLEXITY : O(N x LOG(MAX(PILES)))

    int maxPile = biggestPile(piles);

    int low = 1;
    int high = maxPile;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        long long reqTime = calculateTotalHours(piles, mid);
        if (reqTime <= h)
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

    vector<int> piles = {805306368, 805306368, 805306368};

    // int ans = kokoEatingBananas_Linear(piles, 1000000000);
    int ans = kokoEatingBananas_BS(piles, 1000000000);

    cout << ans;

    return 0;
}