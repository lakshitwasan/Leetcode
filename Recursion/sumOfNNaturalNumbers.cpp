#include <bits/stdc++.h>
using namespace std;

void printR(int n)
{
    if (n == 0)
    {
        cout << 0;
        return;
    }

    cout << n;
    printR(n - 1);
}

int main()
{

    int n = 3;

    printR(n);

    return 0;
}