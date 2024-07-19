#include <bits/stdc++.h>
using namespace std;

int reverseInteger(int x)
{
    long ans = 0;

    while (x != 0)
    {
        ans = ans * 10 + x % 10;
        x = x / 10;
    }

    if (ans > INT_MAX || ans < INT_MIN)
    {
        return 0;
    }

    return int(ans);
}

int main()
{

    int x = 123456789;

    int y = reverseInteger(x);

    cout << y << endl;
    return 0;
}