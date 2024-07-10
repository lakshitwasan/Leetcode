#include <bits/stdc++.h>
using namespace std;

int majorityElement_bruteForce(vector<int> arr)
{

    // TIME COMPLEXITY: O(NLOGN) & SPACE COMPLEXITY: O(1)

    int n = arr.size();
    sort(arr.begin(), arr.end());
    return arr[n / 2];
}

int majorityElement_better(vector<int> arr)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    int n = arr.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int x = n / 2;

    for (auto element : mp)
    {
        if (element.second > x)
        {
            return element.first;
        }
    }

    return 0;
}

int majorityElement_best(vector<int> arr)
{

    // TIME COMPLEXITY: 0(N) & SPACE COMPLEXITY: O(1)

    // USING MORRE VOTING ALGORITHM

    int n = arr.size();
    int count = 0;
    int candidate = 0;

    for (auto num : arr)
    {
        if (count == 0)
        {
            candidate = num;
        }

        if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};

    int ans = majorityElement_bruteForce(arr);
    int ans2 = majorityElement_better(arr);
    int ans3 = majorityElement_best(arr);

    cout << ans << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;

    return 0;
}