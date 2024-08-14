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

int numberOfSubstrings_betterBF(string s)
{
    int n = s.size();
    int count = 0;
    int left = 0;
    int right = 0;

    set<char> st;

    while (right < n)
    {
        // st.clear();

        // abcabc

        st.insert(s[right]);
        while (st.size() == 3)
        {
            count = count + n - right;
            st.erase(left);
            left++;
        }
        right++;
    }

    return count;
}

int main()
{

    return 0;
}