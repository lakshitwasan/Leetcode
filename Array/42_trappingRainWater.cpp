#include <bits/stdc++.h>
using namespace std;

int trapRainWater_BruteForce(vector<int> arr)
{

    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(1)

    int n = arr.size();
    int waterTrapped = 0;

    for (int i = 0; i < n; i++)
    {
        int leftMax = 0;
        int rightMax = 0;

        for (int j = i; j < n; j++)
        {
            rightMax = max(rightMax, arr[j]);
        }
        for (int j = i; j >= 0; j--)
        {
            leftMax = max(leftMax, arr[j]);
        }

        waterTrapped += min(rightMax, leftMax) - arr[i];
    }

    return waterTrapped;
}

int trapRainWater_better(vector<int> arr)
{
    // TIME COMPLEXITY: O(3N) & SPACE COMPLEXITY: O(2N)

    int n = arr.size();
    vector<int> leftMax(n);
    vector<int> rightMax(n);

    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    rightMax[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    int waterTrapped = 0;

    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(leftMax[i], rightMax[i]) - arr[i];
    }

    return waterTrapped;
}

int trapRainWater_best(vector<int> arr)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(1)

    int n = arr.size();

    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int waterTrapped = 0;

    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= leftMax)
            {
                leftMax = arr[left];
            }
            else
            {
                waterTrapped += leftMax - arr[left];
            }
            left++;
        }
        else
        {
            if (arr[right] >= rightMax)
            {
                rightMax = arr[right];
            }
            else
            {
                waterTrapped += rightMax - arr[right];
            }
            right--;
        }
    }

    return waterTrapped;
}

int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is (Brute Force) " << trapRainWater_BruteForce(arr) << endl;
    cout << "The water that can be trapped is (Better Approach) " << trapRainWater_better(arr) << endl;
    cout << "The water that can be trapped is (Best Approach)" << trapRainWater_best(arr) << endl;
    return 0;
}