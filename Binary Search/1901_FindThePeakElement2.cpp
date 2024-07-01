#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findPeakGrid_Linear(vector<vector<int>> arr)
{
    // TIME COMPLEXITY: O(NxM)

    int largest = INT32_MIN;
    int row = -1;
    int col = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] > largest)
            {
                largest = arr[i][j];
                row = i;
                col = j;
            }
        }
    }

    return {row, col};
}

int findMaxIndex(vector<vector<int>> arr, int col)
{
    int maxValue = -1;
    int index = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][col] > maxValue)
        {
            maxValue = arr[i][col];
            index = i;
        }
    }

    return index;
}

vector<int> findPeakGrid_BS(vector<vector<int>> arr)
{

    // TIME COMPLEXITY : O( N x LOGM )

    int n = arr.size();
    int m = arr[0].size();

    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxInRow = findMaxIndex(arr, mid);
        int left = mid - 1 >= 0 ? arr[maxInRow][mid - 1] : -1;
        int right = mid + 1 < m ? arr[maxInRow][mid + 1] : -1;

        if (arr[maxInRow][mid] > left && arr[maxInRow][mid] > right)
        {
            return {maxInRow, mid};
        }
        else if (arr[maxInRow][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}

int main()
{

    // vector<vector<int>> arr = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<vector<int>> arr = {{41, 8, 2, 48, 18}, {16, 15, 9, 7, 44}, {48, 35, 6, 38, 28}, {3, 2, 14, 15, 33}, {39, 36, 13, 46, 42}};

    vector<int> ans = findPeakGrid_Linear(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}