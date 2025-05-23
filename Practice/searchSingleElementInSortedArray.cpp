#include <bits/stdc++.h>
using namespace std;

int searchSingleElement_BF(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] != arr[i + 1])
            {
                return arr[i];
            }
        }
        else if (i == n - 1)
        {
            if (arr[i] != arr[i - 1])
            {
                return arr[i];
            }
        }
        else
        {
            if ((arr[i] != arr[i - 1]) && (arr[i] != arr[i + 1]))
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int searchSingleElement_XOR(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = arr[i] ^ ans;
    }
    return ans;
}

int searchSingleElement_BS(vector<int> &arr)
{
    int n = arr.size();
    int low = 1;
    int high = n - 2;

    if (n == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6};

    int ans1 = searchSingleElement_BF(arr);
    int ans2 = searchSingleElement_XOR(arr);
    int ans3 = searchSingleElement_BS(arr);

    cout << "BF: " << ans1 << endl;
    cout << "XOR: " << ans2 << endl;
    cout << "BS: " << ans3 << endl;

    return 0;
}