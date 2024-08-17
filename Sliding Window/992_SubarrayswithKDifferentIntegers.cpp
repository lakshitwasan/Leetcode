#include <bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct_BF(vector<int> &arr, int k)
{
    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY:O(N)

    int n = arr.size();
    int count = 0;
    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
    {
        ump.clear();
        for (int j = i; j < n; j++)
        {
            ump[arr[j]]++;
            if (ump.size() == k)
            {
                count++;
            }
            else if (ump.size() > k)
            {
                break;
            }
        }
    }

    return count;
}

int subarraysWithKDistinct_SW_helper(vector<int> &arr, int k)
{
    // SLIDING WINDOW
    // TIME COMPLEXITY: O(2N) & SPACE COMPLEXITY:O(N)

    int n = arr.size();
    unordered_map<int, int> ump;
    int left = 0;
    int right = 0;
    int count = 0;

    while (right < n)
    {
        ump[arr[right]]++;

        while (ump.size() > k)
        {
            ump[arr[left]]--;
            if (ump[arr[left]] == 0)
            {
                ump.erase(arr[left]);
            }

            left++;
        }

        count += (right - left + 1);

        right++;
    }

    return count;
}

int subarraysWithKDistinct_SW(vector<int> &arr, int k)
{
    return subarraysWithKDistinct_SW_helper(arr, k) - subarraysWithKDistinct_SW_helper(arr, k - 1);
}

int main()
{

    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    int ans = subarraysWithKDistinct_SW(arr, k);
    cout << ans;

    return 0;
}