#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                char top = st.top();
                if ((s[i] == ')' && top == '(') || (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{'))
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return st.empty();
}

int main()
{
    string s = "({({[[]]})})";

    cout << (isValid(s) ? "True" : "False");

    return 0;
}