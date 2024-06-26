#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT32_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }

            break;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main()
{
    vector<int> arr = {66, 67, 7, 10, 14, 19, 27, 33, 36, 40, 44, 54, 60};

    int ans = search(arr);

    cout << ans;

    return 0;
}