#include <bits/stdc++.h>
using namespace std;

double myPow_BF(double x, int n)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (n == 0)
        return 1;
    else if (n > 0)
        return x * myPow_BF(x, n - 1);
    else
        return (1 / x) * myPow_BF(x, n + 1);
}

double myPow_better(double x, int n)
{
    // TIME COMPLEXITY: O(LOG N) & SPACE COMPLEXITY: O(LOG N)

    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return myPow_better(x * x, n / 2);
    else if (n > 0)
        return x * myPow_better(x * x, (n - 1) / 2);
    else
        return (1 / x) * myPow_better(x * x, (n + 1) / 2);
}

int main()
{
    double x = 2.0;
    int n = -3;
    cout << "Result1: " << myPow_BF(x, n) << endl;
    cout << "Result2: " << myPow_better(x, n) << endl;
    return 0;
}