#include <bits/stdc++.h>
using namespace std;

int characterReplacement_BF(string s, int k)
{
    int n = s.size();
    int changingChar = 0;
    int maxLength = 0;

    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(26)

    for (int i = 0; i < n; i++)
    {
        vector<int> hash(26, 0);
        int maxFreq = 0;

        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            changingChar = (j - i + 1) - maxFreq;

            if (changingChar <= k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return maxLength;
}

int characterReplacement_Better(string s, int k)
{
    // SLIDING WINDOW
    // TIME COMPLEXITY: O(N + N) x 26 & SPACE COMEPLEXITY: O(26)

    int n = s.size();
    int left = 0;
    int right = 0;
    int maxLength = 0;
    int changingChar = 0;
    vector<int> hash(26, 0);

    while (right < n)
    {
        int maxFreq = 0;

        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);
        changingChar = (right - left + 1) - maxFreq;

        while (changingChar > k)
        {
            hash[s[left] - 'A']--;
            maxFreq = 0;
            for (int i = 0; i < 25; i++)
            {
                maxFreq = max(maxFreq, hash[i]);
            }
            left++;
        }

        if (changingChar <= k)
        {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }

    return maxLength;
}

int characterReplacement_Best(string s, int k)
{
    // SLIDING WINDOW
    // TIME COMPLEXITY: O(N) & SPACE COMEPLXITY: O(26)

    int n = s.size();
    int left = 0;
    int right = 0;
    int maxLength = 0;
    int changingChar = 0;
    vector<int> hash(26, 0);
    int maxFreq = 0;

    while (right < n)
    {

        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);
        changingChar = (right - left + 1) - maxFreq;

        if (changingChar > k)
        {
            hash[s[left] - 'A']--;
            left++;
        }
        else
        {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }

    return maxLength;
}

int main()
{

    return 0;
}