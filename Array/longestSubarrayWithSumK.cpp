#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK_bruteForce(vector<int> arr, int k)
{
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                if (sum == k)
                {
                    len = max(len, j - i + 1);
                }
            }
        }
    }

    return len;
}

int main()
{

    return 0;
}