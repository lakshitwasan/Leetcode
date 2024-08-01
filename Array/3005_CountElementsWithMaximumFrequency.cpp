#include <bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int> &nums)
{
    map<int, int> mp;
    int maxi = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        maxi = max(maxi, mp[nums[i]]);
    }

    int cnt = 0;
    for (auto it : mp)
    {
        if (it.second == maxi)
        {
            cnt++;
        }
    }

    return cnt * maxi;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 3, 4, 2, 3, 1};
    int ans = maxFrequencyElements(arr);

    cout << ans;
    return 0;
}