#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void sub(vector<int> &nums, int i, vector<int> temp)
{
    if (i == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    sub(nums, i + 1, temp);
    temp.push_back(nums[i]);
    sub(nums, i + 1, temp);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    ans.clear();
    vector<int> temp;
    sub(nums, 0, temp);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    // Print the subsets
    cout << "Subsets:" << endl;
    for (const auto &subset : result)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
