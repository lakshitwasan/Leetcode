#include <iostream>
#include <vector>
using namespace std;

int kthMissingNumber_Linear(vector<int> arr, int k)
{
    // TIME COMPECITY: O(N)

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }

    return k;
}

int kthMissingNumber_BS(vector<int> arr, int k)
{

    // NO IDEA HOW BUT SOMEDAY

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low + k;
}

int main()
{

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    // int ans = kthMissingNumber_Linear(arr, k);
    int ans = kthMissingNumber_BS(arr, k);
    cout << ans;

    return 0;
}