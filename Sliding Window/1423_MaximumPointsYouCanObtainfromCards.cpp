#include <bits/stdc++.h>
using namespace std;

int maxScore_SW_1(vector<int> &cardPoints, int k)
{
    // SLIDING WINDOW: O(N) & SPACE COMPLEXITY: O(1)

    int n = cardPoints.size();
    int total_pnts = 0;

    for (int i = 0; i < n; i++)
    {
        total_pnts += cardPoints[i];
    }

    if (k == n)
    {
        return total_pnts;
    }

    int left = 0;
    int right = 0;
    int sumCurrWindow = 0;
    int ans = 0;

    while (right < n)
    {
        sumCurrWindow += cardPoints[right];

        if (right >= n - k - 1)
        {
            ans = max(ans, total_pnts - sumCurrWindow);
            sumCurrWindow -= cardPoints[left];
            left++;
        }

        right++;
    }

    return ans;
}

int maxScore_SW_2(vector<int> &cardPoints, int k)
{
    // SLIDING WINDOW
    // TIME COMEPLITY: O(2K) & SPACE COMPLEXITY: 0(1)

    int n = cardPoints.size();
    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;
    int rightIndex = n - 1;

    for (int i = 0; i < k; i++)
    {
        leftSum += cardPoints[i];
    }

    maxSum = leftSum;

    for (int i = k - 1; i >= 0; i--)
    {
        leftSum -= cardPoints[i];
        rightSum += cardPoints[rightIndex];
        rightIndex--;

        maxSum = max(maxSum, (leftSum + rightSum));
    }

    return maxSum;
}

int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << "Max score using OG sliding window: " << maxScore_SW_1(cardPoints, k) << endl;
    cout << "Max score using sum sliding window: " << maxScore_SW_2(cardPoints, k) << endl;
    return 0;
}