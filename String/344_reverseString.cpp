#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
int main()
{

    vector<char> st = {'h', 'e', 'l', 'l', 'o'};

    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i] << " ";
    }

    cout << endl;

    reverseString(st);

    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i] << " ";
    }

    return 0;
}