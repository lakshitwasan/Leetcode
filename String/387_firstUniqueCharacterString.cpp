#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    string s = "leetcode";

    int ans = firstUniqChar(s);

    cout << ans << endl;

    return 0;
}