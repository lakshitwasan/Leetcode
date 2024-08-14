#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings_BF(string s)
{

    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(N)

    int n = s.size();
    int count = 0;
    unordered_map<char, int> ump;

    for (int i = 0; i < n; i++)
    {
        ump.clear();

        for (int j = i; j < n; j++)
        {
            ump[s[j]] = 1;
            if (ump.size() == 3)
            {
                count++;
            }
        }
    }

    return count;
}

int numberOfSubstrings_betterBF(string s)
{
    int n = s.size();
    int count = 0;
    unordered_map<char, int> ump;

    for (int i = 0; i < n; i++)
    {
        ump.clear();

        for (int j = i; j < n; j++)
        {
            ump[s[j]] = 1;
            if (ump.size() == 3)
            {
                count = count + n - j;
                break;
            }
        }
    }

    return count;
}

int numberOfSubstrings_SW(string s)
{

    // TIME COMPLEXITY: O(2N) & SPACE COMPLEXITY: O(N)

    int n = s.size();
    int count = 0;
    int left = 0;
    int right = 0;

    unordered_map<char, int> ump;

    while (right < n)
    {
        ump[s[right]]++;
        while (ump['a'] > 0 && ump['b'] > 0 && ump['c'] > 0)
        {
            count = count + n - right;
            ump[s[left]]--;
            left++;
        }
        right++;
    }

    return count;
}

int numberOfSubstrings_best(string s)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    vector<int> lastSeen(3, -1);
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        lastSeen[s[i] - 'a'] = i;

        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            count = count + (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
        }
    }

    return count;
}

int main()
{

    string s = "abcabc";

    int resultBF = numberOfSubstrings_BF(s);
    int resultBetterBF = numberOfSubstrings_betterBF(s);
    int resultSW = numberOfSubstrings_SW(s);
    int resultBest = numberOfSubstrings_best(s);

    cout << "Number of substrings (Brute Force): " << resultBF << endl;
    cout << "Number of substrings (Better Brute Force): " << resultBetterBF << endl;
    cout << "Number of substrings (Sliding Window): " << resultSW << endl;
    cout << "Number of substrings (Optimal): " << resultBest << endl;
    return 0;
}