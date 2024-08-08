#include <bits/stdc++.h>
using namespace std;

char findTheDifference_HashMap(string s, string t)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    unordered_map<char, int> um;
    for (int i = 0; i < t.size(); i++)
    {
        um[t[i]]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        um[s[i]]--;
    }
    for (auto i : um)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
    return 'a';
}

int main()
{
    string s = "abcd";
    string t = "abcde";

    char ans = findTheDifference_HashMap(s, t);

    cout << ans << endl;

    return 0;
}