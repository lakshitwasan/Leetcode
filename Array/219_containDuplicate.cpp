#include <bits/stdc++.h>
using namespace std;

bool containDuplicate2(vector<int> arr, int k)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N   )

    unordered_map<int, int> mp;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (mp.count(arr[i]))
        {
            if (abs(i - mp[arr[i]]))
            {
                return true;
            }
        }

        mp[arr[i]] = i;
    }

    return false;
}

int main()
{

    vector<int> arr = {1, 2, 3, 1};

    int k = 3;

    bool ans = containDuplicate2(arr, k);

    cout << ans;

    return 0;
}