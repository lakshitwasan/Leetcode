#include <bits/stdc++.h>
using namespace std;

int maxReqDays(vector<int> arr)
{
    int max = INT32_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int minReqDays(vector<int> arr)
{
    int min = INT32_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

bool bouquetPossible(vector<int> flowers, int day, int noOfBouquets, int noOfFlowers)
{
    int count = 0;
    int noOfB = 0;

    for (int i = 0; i < flowers.size(); i++)
    {
        if (flowers[i] <= day)
        {
            count++;
        }
        else
        {
            noOfB += count / noOfFlowers;
            count = 0;
        }
    }

    noOfB += count / noOfFlowers;

    if (noOfB >= noOfBouquets)
    {
        return true;
    }
    return false;
}

int bouquets_BS(vector<int> flowers, int noOfBouquets, int noOfFlowers)
{
    int maxDays = maxReqDays(flowers);
    int minDays = minReqDays(flowers);

    long long n = flowers.size();
    long long val = 1LL * noOfBouquets * noOfFlowers;

    if (val > n)
    {
        return -1;
    }

    int low = minDays;
    int high = maxDays;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (bouquetPossible(flowers, mid, noOfBouquets, noOfFlowers))
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
    vector<int> flowers = {7, 7, 7, 7, 13, 11, 12, 7};

    int noOfBouquets = 2;

    int noOfFlowers = 3;

    int ans = bouquets_BS(flowers, noOfBouquets, noOfFlowers);

    cout << ans;

    return -1;
}