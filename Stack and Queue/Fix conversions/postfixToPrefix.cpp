#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s)
{
    stack<string> st;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (isalpha(c))
        {
            st.push(string(1, c));
        }
        else if (!st.empty())
        {
            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();
            st.push(c + left + right);
        }
    }
    return st.top();
}

int main()
{

    string exp = "ab+ef/*";
    cout << "Prefix expression: " << exp << endl;
    cout << "Postfix expression: " << postfixToPrefix(exp) << endl;
    return 0;
}