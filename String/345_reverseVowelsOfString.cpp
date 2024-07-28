#include <bits/stdc++.h>
using namespace std;

bool checkVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return true;
    }
    return false;
}

vector<char> reverseVowels(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        if (checkVowel(s[start]) && checkVowel(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if (!checkVowel(s[start]) && checkVowel(s[end]))
        {
            start++;
        }
        else if (checkVowel(s[start]) && !checkVowel(s[end]))
        {
            end--;
        }
        else
        {
            start++;
            end--;
        }
    }

    return s;
}

int main()
{

    vector<char> s = {'H', 'e', 'l', 'l', 'o'};

    vector<char> ans = reverseVowels(s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}