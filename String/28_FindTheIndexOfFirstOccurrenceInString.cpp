#include <bits/stdc++.h>
using namespace std;

int firstOccurence_bruteForce(string haystack, string needle)
{

    // TIME COMPLEXITY: O(N * M) & SPACE COMPLEXITY: O(1)

    int n = haystack.length();
    int m = needle.length();

    for (int i = 0; i <= n - m; i++)
    {
        if (haystack.substr(i, m) == needle)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    string haystack = "sadbutsad";
    string needle = "sad";

    int ans = firstOccurence_bruteForce(haystack, needle);

    cout << ans;

    return 0;
}