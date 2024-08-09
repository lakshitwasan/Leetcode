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

int longestSubarrayWithSumK_optimal1(vector<int> arr, int k)
{
    // ORDERED MAP: TIME COMPLEXITY: O(N x LOGN)& SPACE O(N)
    // UNORDERED MAP: TIME COMPLEXITY: [BEST] O(N x 1) [WORST] O(N x N) & SPACE O(N)

    // THIS IS BEST FOR +VE AND -VE BUT NOT FOR POSITIVE AND ZEROES

    int n = arr.size();
    int maxLen = 0;
    int sum = 0;

    // BOTH CAN BE USED BUT TIME COMPLEXITY WILL DIFFER ON THE BASIS OF DIFFERENT CASES AS MENTIONED ABOVE

    unordered_map<int, int> prefSumMap;
    // map<int, int> prefSumMap;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - k;

        if (prefSumMap.find(rem) != prefSumMap.end())
        {
            int len = i - prefSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (prefSumMap.find(sum) == prefSumMap.end())
        {
            prefSumMap[sum] = i;
        }
    }

    return maxLen;
}

int longestSubarrayWithSumK_optimal2(vector<int> arr, int k)
{
    //  TIME COMPLEXITY: O(N + N) & SPACER COMPLEXITY : O(1)

    // THIS SOLUTION IS BEST FOR POSITIVES AND ZEROES BUT NOT FOR POSITIVES AND NEGATIVES

    int n = arr.size();
    int len = 0;
    int sum = arr[0];

    int left = 0;
    int right = 0;

    while (right <= n - 1)
    {

        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            len = max(len, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }

    return len;
}

int main()
{

    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int ans = longestSubarrayWithSumK_optimal1(arr, k);

    cout << ans << endl;

    return 0;
}