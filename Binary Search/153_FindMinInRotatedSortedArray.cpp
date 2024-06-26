#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT32_MAX;

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

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (ans > arr[mid])
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
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};

    int ans = search(arr);

    cout << ans;

    return 0;
}