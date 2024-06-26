#include <iostream>
#include <vector>
using namespace std;

long long exponent(int x, int n, int m)
{
    long long ans = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * x;
            n = n - 1;
        }
        else
        {
            n = n / 2;
            x = x * x;

            // If x squared exceeds m, return a large number to indicate overflow
            if (x > m)
            {
                return m + 1;
            }
        }
    }
    return ans;
}

int nthRootOfNumber_Linear(int n, int m)
{
    for (int i = 0; i <= m; i++)
    {
        long long val = exponent(i, n, m);
        if (val == m)
        {
            return i;
        }
        else if (val > m)
        {
            break;
        }
    }

    return -1;
}

int nthRootOfNumber_BS(int n, int m)
{

    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long val = exponent(mid, n, m);

        if (val == m)
        {
            return mid;
        }
        else if (val < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n = 6;
    int m = 4096;

    // int ans = nthRootOfNumber_Linear(n, m);
    int ans = nthRootOfNumber_BS(n, m);
    cout << ans;

    return 0;
}
