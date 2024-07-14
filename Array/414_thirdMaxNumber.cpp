#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int> arr)
{
    int n = arr.size();

    long long firstMax = LONG_LONG_MIN;
    long long secondMax = LONG_LONG_MIN;
    long long thirdMax = LONG_LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstMax)
        {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (secondMax < arr[i] && arr[i] != firstMax)
        {
            thirdMax = secondMax;
            secondMax = arr[i];
        }
        else if (thirdMax < arr[i] && arr[i] != secondMax && arr[i] != firstMax)
        {
            thirdMax = arr[i];
        }
    }

    if (thirdMax == LONG_LONG_MIN)
    {
        return firstMax;
    }
    else if (secondMax == LONG_LONG_MIN)
    {
        return firstMax;
    }

    return thirdMax;
}

int main()
{

    vector<int> arr = {1, 2};

    int ans = thirdMax(arr);

    cout << ans << endl;

    return 0;
}