#include <iostream>
#include <vector>
using namespace std;

int findPeak_linear(vector<int> arr)
{

    // TIME COMPLEXITY : O(N)

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i] > arr[i - 1]) && ((i == n - 1) || arr[i] > arr[i + 1]))
        {
            return i;
        }
    }
}

int findPeak_BS(vector<int> arr)
{

    //  TIME COMPLEXITY : O (LOGN)

    int n = arr.size();

    if (n == 1)
    {
        return 0;
    }
    if (arr[0] > arr[1])
    {
        return 0;
    }
    if (arr[n - 1] > arr[n - 2])
    {
        return n - 1;
    }

    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
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

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

    // int ans = findPeak_linear(arr);
    int ans = findPeak_BS(arr);

    cout << ans;

    return 0;
}