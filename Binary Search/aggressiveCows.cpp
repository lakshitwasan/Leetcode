#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> stalls, int distance, int angryCows)
{
    int n = stalls.size();
    int cntCows = 1;
    int pos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - pos >= distance)
        {
            cntCows++;
            pos = stalls[i];
        }

        if (cntCows >= angryCows)
        {
            return true;
        }
    }

    return false;
}

int aggressiveCows_Linear(vector<int> stalls, int angryCows)
{
    int n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int maxStall = *max_element(stalls.begin(), stalls.end());
    int minStall = *min_element(stalls.begin(), stalls.end());

    for (int i = 0; i <= maxStall - minStall; i++)
    {
        if (canWePlace(stalls, i, angryCows) == false)
        {
            return (i - 1);
        }
    }

    return maxStall - minStall;
}

int aggressiveCows_BS(vector<int> stalls, int angryCows)
{
    int n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int maxStall = *max_element(stalls.begin(), stalls.end());
    int minStall = *min_element(stalls.begin(), stalls.end());

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, angryCows) == false)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return high;
}

int main()
{

    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    // int ans = aggressiveCows_Linear(stalls, k);
    int ans = aggressiveCows_BS(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}