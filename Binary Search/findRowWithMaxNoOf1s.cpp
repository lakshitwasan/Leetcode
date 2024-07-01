#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1_Linear(vector<vector<int>> arr, int n, int m)
{

    // TIME COMPLEXITY: O(NxM)

    int countMax = -1;
    int maxIndex = -1;

    for (int i = 0; i < n; i++)
    {
        int countOne = 0;
        for (int j = 0; j < m; j++)
        {
            countOne += arr[i][j];
        }
        if (countOne > countMax)
        {
            countMax = countOne;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int firstOccurence(vector<int> arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int rowWithMax1_BS(vector<vector<int>> arr, int n, int m)
{

    // TIME COMPLEXITY: O(LOG(NxM))

    int countMax = 0;
    int maxIndex = -1;

    for (int i = 0; i < n; i++)
    {
        int firstOneIndex = firstOccurence(arr[i], 1);
        int countOne = m - firstOneIndex;

        if (countOne > countMax)
        {
            countMax = countOne;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main()
{
    vector<vector<int>> arr = {{0, 0, 1, 1, 1}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 1}};
    int n = 3;
    int m = 5;

    // int ans = rowWithMax1_Linear(arr, n, m);
    int ans = rowWithMax1_BS(arr, n, m);

    cout << ans;

    return 0;
}