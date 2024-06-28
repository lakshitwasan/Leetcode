#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int smallestDivisor_linear(vector<int> arr, int threshold)
{

    // TIME COMPLEXITY : O (MAX[ARR] x N )

    int n = arr.size();

    int maxNo = 0;

    for (int i = 0; i < n; i++)
    {
        maxNo = max(arr[i], maxNo);
    }

    for (int i = 1; i < maxNo; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += ceil((double)arr[j] / (double)i);
        }

        if (sum <= threshold)
        {
            return i;
        }
    }

    return -1;
}

int smallestDivisor_BS(vector<int> arr, int threshold)
{

    // TIME COMPLEXITY : O (LOG(MAX[ARR]) x N )

    int n = arr.size();

    if (n > threshold)
    {
        return -1;
    }

    int maxNo = 0;

    for (int i = 0; i < n; i++)
    {
        maxNo = max(arr[i], maxNo);
    }

    int low = 1;
    int high = maxNo;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += ceil((double)arr[j] / (double)mid);
        }

        if (sum <= threshold)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int threshold = 8;

    // int ans = smallestDivisor_linear(arr, threshold);
    int ans = smallestDivisor_BS(arr, threshold);

    cout << ans;

    return 0;
}