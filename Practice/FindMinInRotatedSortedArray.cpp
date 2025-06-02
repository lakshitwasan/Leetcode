#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int ans;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
            }
            break;
        }
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 2, 3};

    int ans = search(arr);

    cout << ans;

    return 0;
}