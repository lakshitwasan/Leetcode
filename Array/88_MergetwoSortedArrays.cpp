#include <bits/stdc++.h>
using namespace std;

void mergeTwoArray(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size();
    int n = arr2.size();

    arr1.resize(m + n);

    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[index] = arr1[i];
            i--;
            index--;
        }
        else
        {
            arr1[index] = arr2[j];
            j--;
            index--;
        }
    }

    while (j >= 0)
    {
        arr1[index] = arr2[j];
        j--;
        index--;
    }
}

int main()
{

    vector<int> arr1 = {1, 3, 4};
    vector<int> arr2 = {1, 5, 7};

    mergeTwoArray(arr1, arr2);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " " << endl;
    }

    return 0;
}