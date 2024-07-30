#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring_bruteForce(string s)
{

    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(N)

    int n = s.size();

    if (n == 0)
    {
        return 0;
    }

    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> set;

        for (int j = i; j < n; j++)
        {
            if (set.find(s[j]) != set.end())
            {
                break;
            }
            int len = j - i + 1;
            maxLength = max(maxLength, len);
            set.insert(s[j]);
        }
    }
    return maxLength;
}

int lengthOfLongestSubstring_slidingWindow(string s)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    int n = s.size();

    if (n == 0)
    {
        return 0;
    }

    vector<int> hash(128, -1);

    int left = 0;
    int right = 0;
    int maxlength = 0;

    while (right < n)
    {
        if (hash[s[right]] != -1)
        {
            if (hash[s[right]] >= left)
            {
                left = hash[s[right]] + 1;
            }
        }
        int len = right - left + 1;
        maxlength = max(len, maxlength);
        hash[s[right]] = right;
        right++;
    }

    return maxlength;
}

int main()
{
    string s = "lakshitwasan";

    int ans1 = lengthOfLongestSubstring_bruteForce(s);
    int ans2 = lengthOfLongestSubstring_slidingWindow(s);

    cout << "Ans1: " << ans1 << endl;
    cout << "Ans2: " << ans2 << endl;

    return 0;
}