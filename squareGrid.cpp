#include <iostream>

using namespace std;

int checkBoundary(int array[3][3], int row, int col, int identifier)
{
    int m = 3;
    int n = 3;
    int exIdentifier = array[row][col];
}

int changeIndentifier(int array[][100], int row, int col, int indentifier, int m, int n, int exIdentifier)
{

    array[row][col] = indentifier;

    if (row - 1 >= 0 && row - 1 < m)
    {
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[3][3] = {
        {10, 10, 20},
        {20, 10, 10},
        {10, 10, 10}};

    int identifier;
    cin >> identifier;

    int row, col;
    cin >> row;
    cin >> col;

    return 0;
}
