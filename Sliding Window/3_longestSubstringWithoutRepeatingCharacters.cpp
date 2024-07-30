#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.size();

    int maxLength = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     unordered_set<int> set;

    //     for (int j = 0; j < n; j++)
    //     {
    //         if (set.find(s[j]) != set.end())
    //         {
    //             break;
    //         }
    //         int len = j - i + 1;
    //         maxLength = max(maxLength, len);
    //         set.insert(s[j]);
    //     }
    // }
    // return maxLength;

    for (int i = 0; i < s.length(); i++)
    {
        unordered_set<int> set;
        for (int j = i; j < s.length(); j++)
        {
            if (set.find(s[j]) != set.end())
            {
                maxLength = max(maxLength, j - i);
                break;
            }
            set.insert(s[j]);
        }
    }
    return maxLength;
}

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charSet.count(s[right]) == 0)
            {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            }
            else
            {
                while (charSet.count(s[right]))
                {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLength;
    }
};

int main()
{

    return 0;
}