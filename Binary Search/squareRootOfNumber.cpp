#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int sqRoot_Linear(int n)
{
    long long ans;

    for (long long i = 1; i <= n; i++)
    {
        if (i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }

    return ans;
}

int sqRoot_algo(int n)
{
    int ans = sqrt(n);
    return ans;
}

int sqRoot_BS(int n)
{
    long long low = 1;
    long long high = n;
    long long ans = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (mid * mid <= (long long)(n))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{

    int n = 9883934;

    // int ans = sqRoot_Linear(n);
    // int ans = sqRoot_algo(n);
    int ans = sqRoot_BS(n);

    cout << ans;

    return 0;
}