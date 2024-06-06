#include <iostream>
using namespace std;

bool isPalindrome(string s)
{

    int i = 0;
    int j = s.size() - 1;

    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (isPalindrome(s))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}