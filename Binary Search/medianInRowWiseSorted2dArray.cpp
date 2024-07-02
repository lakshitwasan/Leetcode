#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int medianInRowWiseSortedArray_Linear(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();

    vector<int> lst;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            lst.push_back(arr[i][j]);
        }
    }

    sort(lst.begin(), lst.end());

    return lst[(m * n) / 2];
}

int main()
{

    return 0;
}