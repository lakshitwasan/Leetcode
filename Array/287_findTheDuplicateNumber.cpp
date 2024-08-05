#include <bits/stdc++.h>
using namespace std;

int findDuplicate_map(vector<int> arr)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)
    unordered_map<int, int> mp;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] != 1)
        {
            mp[arr[i]]++;
        }
        else
        {
            return arr[i];
        }
    }
}

int main()
{

    vector<int> arr = {1, 3, 4, 2, 2};

    int ans = findDuplicate_map(arr);

    cout << ans << endl;

    return 0;
}