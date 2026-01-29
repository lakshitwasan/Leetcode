#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int iniColor, int newColor, vector<vector<int>> &ans, vector<vector<int>> &image, int delRow[], int delCol[])
{
    ans[row][col] = newColor;
    int n = ans.size();
    int m = ans[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != newColor && image[nrow][ncol] == iniColor)
        {
            dfs(nrow, ncol, iniColor, newColor, ans, image, delRow, delCol);
        }
    }
}

vector<vector<int>> FloodFill(vector<vector<int>> image, int sr, int sc, int newColor)
{

    // TIME COMPLEXITY= O(N×M) & SPACE COMPLEXITY: O(N×M)

    int iniColor = image[sr][sc];

    if (iniColor == newColor)
        return image;

    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, iniColor, newColor, ans, image, delRow, delCol);
    return ans;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = FloodFill(image, sr, sc, newColor);

    for (auto &row : result)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}