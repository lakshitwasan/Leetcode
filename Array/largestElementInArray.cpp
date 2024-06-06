#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findLargestInt(int arr[], int n)
{
    int maxVal = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;

    // TIME COMPLEXITY: N
}

int sortArray(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];

    // TIME COMPLEXITY: NLOGN
}

int main()
{

    int n = 5;
    int arr[n] = {1, 2, 3, 4, 25};

    int maxVal = findLargestInt(arr, n);

    cout << maxVal;

    // USING VECTOR

    vector<int> arr1 = {1, 2, 3, 4, 5};

    cout << "Largest Value in an array is:" << sortArray(arr1);

    return 0;
}