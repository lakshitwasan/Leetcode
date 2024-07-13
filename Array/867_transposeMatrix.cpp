#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[j][i] = arr[i][j];
        }
    }

    return result;
}

int main()
{

    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<vector<int>> result = transposeMatrix(arr);

    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}