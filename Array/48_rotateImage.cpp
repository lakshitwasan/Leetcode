#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateImage_bruteForce(vector<vector<int>> &matrix)
{
    //  TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(N^2)

    int n = matrix.size();
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[j][(n - 1) - i] = matrix[i][j];
        }
    }

    return arr;
}

void rotateImage_best(vector<vector<int>> &matrix)
{
    //  TIME COMPLEXITY: O(N/2 * N/2) + O(N * N/2)  & SPACE COMPLEXITY: O(1)

    int n = matrix.size();

    // TRANSPOSE
    // TIME COMPLEXITY: O(N/2 * N/2)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // TIME COMPLEXITY: O(N * N/2)
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void print(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    print(matrix);

    // vector<vector<int>> arr = rotateImage_bruteForce(matrix);
    rotateImage_best(matrix);

    print(matrix);

    return 0;
}