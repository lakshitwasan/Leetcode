#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &candidates, vector<int> &ds, set<vector<int>> &ans)
{
    if (index == candidates.size())
    {
        if (target == 0)
        {
            ans.insert(ds);
        }
        return;
    }

    if (candidates[index] <= target)
    {
        ds.push_back(candidates[index]);
        findCombination(index + 1, target - candidates[index], candidates, ds, ans);
        ds.pop_back();
    }
    findCombination(index + 1, target, candidates, ds, ans);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> ds;
    set<vector<int>> ans;
    findCombination(0, target, candidates, ds, ans);

    return vector<vector<int>>(ans.begin(), ans.end());
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum2(candidates, target);

    for (const auto &combination : result)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
