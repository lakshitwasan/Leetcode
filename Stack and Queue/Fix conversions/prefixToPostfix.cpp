#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s)
{
    stack<string> st;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        char c = s[i];

        if (isalpha(c))
        {
            st.push(string(1, c));
        }
        else if (!st.empty())
        {
            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();
            st.push(left + right + c);
        }
    }
    return st.top();
}

int main()
{

    string exp = "*+AB-CD";
    cout << "Prefix expression: " << exp << endl;
    cout << "Postfix expression: " << prefixToPostfix(exp) << endl;
    return 0;
}