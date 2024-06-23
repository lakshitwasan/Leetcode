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

vector<int> searchRange(vector<int> arr, int target)
{
    vector<int> ans;
    int t1 = firstOccurence(arr, target);
    int t2 = lastOccurence(arr, target);
    ans.push_back(t1);
    ans.push_back(t2);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};

    vector<int> ans = searchRange(arr, 4);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}