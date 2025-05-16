#include <bits/stdc++.h>
using namespace std;

int LastOccurence(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = low + 1;
        }
    }

    return ans;
}

int FirstOccurence(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = low + 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 5};

    int target = 3;

    int ans1 = LastOccurence(arr, target);
    int ans2 = FirstOccurence(arr, target);

    cout << "Last: " << ans1 << endl;
    cout << "First: " << ans2 << endl;

    cout << "Count of target: " << ans1 - ans2 + 1 << endl;

    return 0;
}