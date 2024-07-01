#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix_Linear(vector<vector<int>> arr, int target)
{
    // TIME COMPLEXITY : O(N*M)

    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] = target)
            {
                return true;
            }
        }
    }

    return false;
}

bool binarySearch(vector<int> arr, int target)
{

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return true;
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

    return false;
}

bool searchMatrix_BS(vector<vector<int>> arr, int target)
{
    // TIME COMPLEXITY : O(N*LOGM)

    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        bool flag = binarySearch(arr[i], target);
        if (flag)
        {
            return true;
        }
    }

    return false;
}

bool searchMatrix_Best(vector<vector<int>> arr, int target)
{

    // TIME COMPLEXITY : O(N+M)

    int n = arr.size();
    int m = arr[0].size();

    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (arr[row][col] == target)
        {
            return target;
        }
        else if (arr[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 69;

    // bool ans = searchMatrix_Linear(arr, target);
    // bool ans = searchMatrix_BS(arr, target);
    bool ans = searchMatrix_Best(arr, target);

    cout << ans;

    return 0;
}