#include <bits/stdc++.h>
using namespace std;

int longestOnes_BF(vector<int> arr, int k)
{
    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(1)

    int n = arr.size();

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int countZeroes = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
            {
                countZeroes++;
            }
            else if (countZeroes <= k)
            {
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
            else
            {
                break;
            }
        }
    }

    return maxLen;
}

int longestOnes_Better(vector<int> arr, int k)
{
    // SLIDING WINDOW
    // TIME COMPLEXITY: O(2N) & SPACE COMPLEXITY: O(1)

    int n = arr.size();
    int left = 0;
    int right = 0;
    int countZeroes = 0;
    int maxLen = 0;

    while (right < n)
    {
        if (arr[right] == 0)
        {
            countZeroes++;
            while (countZeroes > k)
            {
                if (arr[left] == 0)
                {
                    countZeroes--;
                }
                left++;
            }
        }

        int len = right - left + 1;
        maxLen = max(maxLen, len);
        right++;
    }

    return maxLen;
}

int longestOnes_Best(vector<int> arr, int k)
{
    // SLIDING WINDOW
    // TIME COMPLEXITY: 0(N) & SPACE COMEPLXITY: O(1)

    int n = arr.size();
    int left = 0;
    int right = 0;
    int countZeroes = 0;
    int maxLen = 0;

    while (right < n)
    {
        if (arr[right] == 0)
        {
            countZeroes++;
        }

        if (countZeroes > k)
        {
            if (arr[left] == 0)
            {
                countZeroes--;
            }
            left++;
        }

        if (countZeroes <= k)
        {
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }

        right++;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

    int k = 2;

    int ans1 = longestOnes_BF(arr, k);
    int ans2 = longestOnes_Better(arr, k);
    int ans3 = longestOnes_Best(arr, k);

    cout << "Ans1 : " << ans1 << endl;
    cout << "Ans2 : " << ans2 << endl;
    cout << "Ans3 : " << ans3 << endl;

    return 0;
}