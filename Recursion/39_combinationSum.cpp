#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{

    // TIME COMPLEXITY: O(2^N) & SPACE COMPLEXITY: O(K x X)

    if (index == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        findCombination(index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }

    findCombination(index + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main()
{

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(candidates, target);

    cout << "Combinations that sum up to " << target << " are:" << endl;
    for (const auto &combination : ans)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}