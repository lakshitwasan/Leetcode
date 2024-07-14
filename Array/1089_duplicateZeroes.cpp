#include <bits/stdc++.h>
using namespace std;

void duplicateZeroes(vector<int> &arr)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(1)

    int i = 0;
    int n = arr.size();
    while (i < n)
    {
        if (arr[i] == 0)
        {
            arr.insert(arr.begin() + i, 0);
            i = i + 2;
        }
        else
        {
            i++;
        }
    }
    arr.resize(n);
}

int main()
{

    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};

    duplicateZeroes(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}