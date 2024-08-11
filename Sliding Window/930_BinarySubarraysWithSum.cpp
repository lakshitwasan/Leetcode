#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum_BF(vector<int> arr, int goal)
{
    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(1)

    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == goal)
            {
                count++;
            }
            else if (sum > goal)
            {
                break;
            }
        }
    }

    return count;
}

int numSubarrayWithSum_SW_helper(vector<int> arr, int goal)
{
    // TIME COMPLEXITY: O(2N) [WORST]

    int n = arr.size();
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;

    if (goal < 0)
    {
        return 0;
    }

    while (right < n)
    {
        sum += arr[right];
        while (sum > goal)
        {
            sum -= arr[left];
            left++;
        }
        ans += (right - left + 1);
        right++;
    }

    return ans;
}

int numSubarrayWithSum_SW(vector<int> arr, int goal)
{
    // SLIDING WINDOPW
    // TIME COMPLEXITY: O(2 x 2N) & SPACE COMPLEXITY: O(1)

    return numSubarrayWithSum_SW_helper(arr, goal) - numSubarrayWithSum_SW_helper(arr, goal - 1);
}

int main()
{

    vector<int> arr = {1, 0, 1, 0, 1};
    int goal = 2;

    int ans1 = numSubarraysWithSum_BF(arr, goal);
    int ans2 = numSubarrayWithSum_SW(arr, goal);

    cout << "Ans1: " << ans1 << endl;
    cout << "Ans2: " << ans2 << endl;

    return 0;
}