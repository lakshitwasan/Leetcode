#include <bits/stdc++.h>
using namespace std;

int LCS(vector<char> x, vector<char> y, int n, int m)
{

    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (x[n - 1] == y[m - 1])
    {
        return 1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
    }
}

int main()
{
    vector<char> x = {'A', 'B', 'C', 'D', 'G', 'H'};
    vector<char> y = {'A', 'E', 'D', 'F', 'H', 'R'};

    int n = x.size();
    int m = y.size();

    int lengthLCS = LCS(x, y, n, m);

    cout << "Length of Longest Common Subsequence: " << lengthLCS << endl;

    return 0;
    return 0;
}