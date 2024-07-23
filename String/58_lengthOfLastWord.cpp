#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int count = 0;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            count++;
        }
        else
        {
            if (count > 0)
            {
                break;
            }
        }
    }

    return count;
}

int main()
{
    string s = "Hello          World       ";
    int ans = lengthOfLastWord(s);

    cout << ans;
    return 0;
}