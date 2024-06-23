#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int> arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > target)
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int ans = upperBound(arr, 3);

    cout << ans;

    return 0;
}