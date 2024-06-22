#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int k)
{

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }
        else if (k > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int ans = binarySearch(arr, 9);

    if (ans == -1)
    {
        cout << "Element is not present" << endl;
    }
    else
    {
        cout << "Element is at: " << ans << endl;
    }

    return 0;
}