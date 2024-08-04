#include <bits/stdc++.h>
using namespace std;

int getCommon(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;

    int n1 = arr1.size();
    int n2 = arr2.size();

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            return arr1[i];
        }
    }

    return -1;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {2, 4};

    int ans = getCommon(arr1, arr2);

    cout << ans << endl;

    return 0;
}