#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isalpha(c))
        {
            string s2(1, c);
            st.push(s2);
        }
        else if (!st.empty())
        {
            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();
            // string temp = '(' + left + c + right + ')';
            // st.push(temp);
            st.push('(' + left + c + right + ')'); // THE ABOVE CODE IS GIVING TLE BECAUSE A NEW STRING IS BEING CREATED JUST TO PUSH
        }
    }
    return st.top();
}

int main()
{
    string exp = "ab+ef/*";
    cout << "Postfix expression: " << exp << endl;
    cout << "Infix expression: " << postfixToInfix(exp) << endl;
    return 0;
}