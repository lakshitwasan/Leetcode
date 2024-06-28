#include <iostream>
#include <vector>
using namespace std;

bool bouquetsPossible(vector<int> arr, int day, int m, int k)
{
    int n = arr.size();
    int count = 0;
    int NoOfBouquets = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {
            NoOfBouquets = NoOfBouquets + (count / k);
            count = 0;
        }
    }

    NoOfBouquets = NoOfBouquets + (count / k);

    if (NoOfBouquets >= m)
    {
        return true;
    }
    return false;
}

int bouquets_Linear(vector<int> arr, int m, int k)
{
    int n = arr.size();

    long long val = m * k;

    if (val > n)
    {
        return -1;
    }

    int minRose = INT32_MAX;
    int maxRose = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        minRose = min(arr[i], minRose);
        maxRose = max(arr[i], maxRose);
    }

    for (int i = minRose; i < maxRose; i++)
    {
        if (bouquetsPossible(arr, i, m, k))
        {
            return i;
        }
    }

    return -1;
}

int bouquets_BS(vector<int> arr, int m, int k)
{
    int n = arr.size();

    long long val = m * k;

    if (val > n)
    {
        return -1;
    }

    int minRose = INT32_MAX;
    int maxRose = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        minRose = min(minRose, arr[i]);
        maxRose = max(maxRose, arr[i]);
    }

    int low = minRose;
    int high = maxRose;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (bouquetsPossible(arr, mid, m, k))
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
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2;
    int k = 3;

    // int ans = bouquets_Linear(arr, m, k);
    int ans = bouquets_BS(arr, m, k);

    if (ans == -1)
    {
        cout << "The bouquet can't be made";
    }
    else
    {
        cout << "Bouquet will be done in " << ans << " days.";
    }

    return 0;
}