#include <iostream>
#include <vector>
using namespace std;

int leftShift(vector<int> &arr, int n, int k)
{

    k = k % n;

    int tempArr[k];

    for (int i = 0; i < k; i++)
    {
        tempArr[i] = arr[i];
    }

    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    for (int i = n - k; i < n; i++)
    {
        arr[i] = tempArr[i - n + k];
    }
}

int rightShift(vector<int> &arr, int n, int k)
{

    k = k % n;

    int tempArr[k];

    for (int i = n - k; i < n; i++)
    {
        tempArr[i - n + k] = arr[i];
    }

    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = tempArr[i];
    }
}

void Reverse(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void RotateLeft(vector<int> &arr, int n, int k)
{
    Reverse(arr, n - k - 1, n);
    Reverse(arr, 0, k);
    Reverse(arr, 0, n);
}

void RotateRight(vector<int> &arr, int n, int k)
{
    Reverse(arr, 0, n - 1);
    Reverse(arr, 0, k - 1);
    Reverse(arr, k, n - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int n = arr.size();

    cout << arr.size() << endl;

    // rightShift(arr,n, k);
    // leftShift(arr, n, k);

    RotateRight(arr, n, k);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}