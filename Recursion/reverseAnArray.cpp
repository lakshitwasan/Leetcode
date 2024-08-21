#include <bits/stdc++.h>
using namespace std;

void reverseArray_2pointer(int l, int r, vector<int> &arr)
{
    if (l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    reverseArray_2pointer(l + 1, r - 1, arr);
}

void reverseArray_1pointer(int i, vector<int> &arr)
{
    int n = arr.size();
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    reverseArray_1pointer(i + 1, arr);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int l = 0;
    int r = arr.size() - 1;

    // reverseArray_2pointer(l, r, arr);
    reverseArray_1pointer(l, arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
