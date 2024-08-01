#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK_bruteForce(vector<int> arr, int K)
{
    // TIME COMPLEXITY: O(N^3) [ALMOST] & SPACE O(1)

    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == K)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;
}

int longestSubarrayWithSumK_betterBruteForce(vector<int> arr, int K)
{
    // TIME COMPLEXITY: O(N^2) [ALMOST] & SPACE O(1)

    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == K)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;
}

int longestSubarrayWithSumK_better(vector<int> arr, int k)
{
    // TIME COMPLEXITY: O(N^2) [ALMOST] & SPACE O(1)

    int n = arr.size();
    int len = 0;
    int prefSum = 0;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];
        mp[prefSum] = i;

        if (prefSum - k ==)
        {
            /* code */
        }

        if
    }
}

int main()
{

    return 0;
}