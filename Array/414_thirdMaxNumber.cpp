#include <bits/stdc++.h>
using namespace std;

//  THIS ISN'T COMPLETE AND IS WRONG

int thirdMax(vector<int> arr)
{
    int n = arr.size();

    if (arr.size() == 1)
    { // when size of Array is 1
        return arr[0];
    }
    if (arr.size() == 2)
    { // When size of array is 2
        return max(arr[0], arr[1]);
    }

    int firstMax = INT32_MIN;
    int secondMax = INT32_MIN;
    int thirdMax = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstMax)
        {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (secondMax < arr[i] && arr[i] != firstMax)
        {
            thirdMax = secondMax;
            secondMax = arr[i];
        }
        else if (thirdMax < arr[i] && arr[i] != secondMax && arr[i] != firstMax)
        {
            thirdMax = arr[i];
        }
    }

    return thirdMax;
}

int main()
{

    vector<int> arr = {1, 2};

    int ans = thirdMax(arr);

    cout << ans << endl;

    return 0;
}