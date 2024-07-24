#include <bits/stdc++.h>
using namespace std;

int climbingStairs_recursion(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return climbingStairs_recursion(n - 1) + climbingStairs_recursion(n - 2);
}

int climbingStairs_vector(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbingStairs_variable(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int prev = 1;
    int curr = 1;

    for (int i = 2; i <= n; i++)
    {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }

    return curr;
}

int main()
{

    int n = 3;

    int ans = climbingStairs_recursion(n);
    int ans2 = climbingStairs_vector(n);
    int ans3 = climbingStairs_variable(n);

    cout << ans << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;

    return 0;
}