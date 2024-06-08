#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumMap(vector<int> nums, int n, int target)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int ans = target - num;

        if (mpp.find(ans) != mpp.end())
        {
            return {mpp[ans], i};
        }
        mpp[num] = i;
    }

    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int n, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

int main()
{
    vector<int> nums{2, 11, 7, 15};

    int target = 9;
    int n = nums.size();

    // vector<int> result = twoSum(nums, n, target);
    vector<int> result = twoSumMap(nums, n, target);

    for (auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}