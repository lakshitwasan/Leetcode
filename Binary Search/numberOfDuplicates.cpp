#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOccurence(vector<int> arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int noOfDuplicates(vector<int> arr, int target)
{
    int ans;
    int t1 = firstOccurence(arr, target);

    cout << t1 << endl;

    int t2 = lastOccurence(arr, target);
    cout << t2 << endl;

    if (t1 == -1 || t2 == -1)
    {
        return 0;
    }
    ans = t2 - t1 + 1;

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};

    int ans = noOfDuplicates(arr, 9);

    cout << ans;

    return 0;
}