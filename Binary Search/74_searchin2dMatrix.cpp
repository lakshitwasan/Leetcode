#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix_Linear(vector<vector<int>> arr, int target)
{
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

    // TIME COMPLEXITY : O(N*M)

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
        if (arr[i][0] <= target && arr[i][m - 1] >= target)
        {
            return binarySearch(arr[i], target);
        }
    }

    return false;
}

bool searchMatrix_Better_BS(vector<vector<int>> arr, int target)
{

    // TIME COMPLEXITY : O(LOG(M*N))

    // USING A 2D ARRAY AS A 1D ARRAY

    int n = arr.size();
    int m = arr[0].size();

    int low = 0;
    int high = (n * m) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (arr[row][col] == target)
        {
            return true;
        }
        else if (arr[row][col] < target)
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

int main()
{

    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 13;

    // bool ans = searchMatrix_Linear(arr, target);
    // bool ans = searchMatrix_BS(arr, target);
    bool ans = searchMatrix_Better_BS(arr, target);

    cout << ans;

    return 0;
}