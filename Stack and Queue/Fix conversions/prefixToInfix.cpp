#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string s)
{
    stack<string> st;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        char c = s[i];

        if (isalpha(c))
        {
            string s2(1, c);
            st.push(s2);
        }
        else if (!st.empty())
        {
            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();
            string temp = '(' + left + c + right + ')';
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    string exp = "+-*ab/cde";
    cout << "Prefix expression: " << exp << endl;
    cout << "Infix expression: " << prefixToInfix(exp) << endl;
    return 0;
}