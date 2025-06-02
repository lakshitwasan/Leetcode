#include <bits/stdc++.h>
using namespace std;

int findPeak_BF(vector<int> arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (((i == 0) || (arr[i] > arr[i - 1])) && ((i == n - 1) || (arr[i] > arr[i + 1])))
        {
            return i;
        }
    }

    return -1;
}

int findPeak_BS(vector<int> arr)
{
    int n = arr.size();

    if (n==1)
    {
        return arr[0];
    }
    
    if (arr[0] > arr[1])
    {
        return arr[0];
    }

    if (arr[n-2] < arr[n-1])
    {
        return arr[n-1];
    }
    

    int low = 1;
    int high = n-2;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
        {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid])
        {
            low = mid +1;
        }
        else
        {
            high = mid -1;
        }
    }

    return -1;

}

int main()
{
    vector<int> arr = {1, 3, 4, 3, 2, 1, 0};

    int ans1 = findPeak_BF(arr);
    int ans2 = findPeak_BS(arr);

    cout << "Peak index (Brute Force): " << ans1 << endl;
    cout << "Peak index (Binary Search): " << ans2 << endl;

    return 0;
}