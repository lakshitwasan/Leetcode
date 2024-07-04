#include <bits/stdc++.h>
using namespace std;

int precendence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (isalpha(c) || isdigit(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precendence(c) <= precendence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

string infixToPrefix(string s)
{
    int n = s.length();

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    string s2 = infixToPostfix(s);

    reverse(s2.begin(), s2.end());

    return s2;
}

int main()
{
    string exp = "(A+B)*C-D+F";
    cout << "Infix expression: " << exp << endl;
    cout << "Prefix expression: " << infixToPrefix(exp) << endl;

    return 0;
}