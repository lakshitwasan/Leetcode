#include <iostream>
#include <vector>
using namespace std;

int missingNoXOR(vector<int> arr, int n)
{
    int xor1 = 0, xor2 = 0;

    for (int i = 1; i <= n; i++)
    {
        xor1 = (xor1 ^ i);
    }

    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ arr[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     xor2 = xor2 ^ arr[i];
    //     xor1 = xor1 ^ (i + 1);
    // }
    // xor1 = xor1 ^ n;

    return xor1 ^ xor2;
}

int missingNoSum(vector<int> arr, int n)
{

    int s2 = 0;
    int s1 = (n * (n + 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        s2 = s2 + arr[i];
    }

    return s1 - s2;
}

int missingNoHashing(vector<int> arr, int n)
{

    // USING HASH ARRAY

    int hash[n + 1] = {0};

    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

int missingNo(vector<int> arr, int N)
{

    // USING LINEAR SEARCH

    for (int i = 0; i <= N; i++)
    {
        int flag = 0;

        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int N = arr.size();

    // int ans = missingNo(arr, N);
    // int ans = missingNoHashing(arr, N);
    // int ans = missingNoSum(arr, N);
    int ans = missingNoXOR(arr, N);

    cout << ans;

    return 0;
}