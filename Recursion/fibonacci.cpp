#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    // TIME COMPLEXITY: O(2^N)

    if (n <= 1)
    {
        return n;
    }

    int last = fibonacci(n - 1);
    int secLast = fibonacci(n - 2);

    return last + secLast;
}

int main()
{

    cout << fibonacci(4) << endl;

    return 0;
}