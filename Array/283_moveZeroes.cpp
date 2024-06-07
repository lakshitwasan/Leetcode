#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &arr)
{
    int n = arr.size();
    int j = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return;
    }

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 0, 0, 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0};

    moveZeroes(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}