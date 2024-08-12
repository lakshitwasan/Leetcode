#include <bits/stdc++.h>
using namespace std;

int subarraySum_BF(vector<int> &arr, int k)
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
            if (sum == k)
            {
                count++;
            }
            else if (sum > k)
            {
                break;
            }
        }
    }

    return count;
}

int subarraySum_SW(vector<int> &arr, int k)
{

    // SLIDIG WINDOW
    // TIME COMPLEXITY: O(2N) & SPACE COMPLEXITY: O(1)
    // DOES NOT WORK FOR ALL THE CASES LEAVE THE ONES WITH -VE INTEGERS

    int n = arr.size();
    int count = 0;
    int left = 0;
    int right = 0;
    int sum = 0;

    while (right < n)
    {
        sum += arr[right];
        while (sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            count++;
        }

        right++;
    }

    return count;
}

int subarraySum_hashMap(vector<int> &arr, int k)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    unordered_map<int, int> ump;
    ump[0] = 1;
    int sum = 0;
    int count = 0;

    for (int it : arr)
    {
        sum += it;
        if (ump.find(sum - k) != ump.end())
        {
            count += ump[sum - k];
        }
        ump[sum]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 1, 1};
    int k = 2;

    int ans1 = subarraySum_BF(arr, k);
    int ans2 = subarraySum_SW(arr, k);

    cout << "Ans1: " << ans1 << endl;
    cout << "Ans2: " << ans2 << endl;

    return 0;
}