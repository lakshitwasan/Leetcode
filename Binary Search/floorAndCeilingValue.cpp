#include <iostream>
#include <vector>
using namespace std;

int floorValue(vector<int> arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= target)
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

int ceilingValue(vector<int> arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 9};

    int target = 0;

    int ans1 = ceilingValue(arr, target);
    int ans2 = floorValue(arr, target);

    cout << ans2 << endl;
    cout << ans1 << endl;

    return 0;
}