#include <bits/stdc++.h>
using namespace std;

vector<int> onePlus(vector<int> arr)
{
    int n = arr.size() - 1;

    while (n >= 0)
    {
        if (arr[n] == 9)
        {
            arr[n] = 0;
        }
        else
        {
            arr[n]++;
            return arr;
        }
        n--;
    }
    arr.insert(arr.begin(), 1);
    return arr;
}

int main()
{
    vector<int> arr = {1, 2, 9, 9};
    vector<int> arr2 = onePlus(arr);

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}