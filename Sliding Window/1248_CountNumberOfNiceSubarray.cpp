#include <bits/stdc++.h>
using namespace std;

int numOfNiceSubarray_BF(vector<int> arr, int k)
{

    // TIME COMPLEXITYl O(N^2) & SPACE COMPLEXITY: O(1)

    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int oddNum = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] % 2 != 0)
            {
                oddNum++;
            }

            if (oddNum == k)
            {
                count++;
            }
            else if (oddNum > k)
            {
                break;
            }
        }
    }

    return count;
}

int numOfNiceSubarray_SW_helper(vector<int> arr, int k)
{
    // TIME COMPELEXITY: O(2N) & SAPCE COMPLEXITY: O(1)

    int n = arr.size();
    int left = 0;
    int right = 0;
    int count = 0;
    int oddNum = 0;

    while (right < n)
    {

        if (arr[right] % 2 != 0)
        {
            oddNum++;
        }

        while (oddNum > k)
        {
            if (arr[left] % 2 != 0)
            {
                oddNum--;
            }
            left++;
        }
        count += (right - left + 1);
        right++;
    }

    return count;
}
int numOfNiceSubarray_SW(vector<int> arr, int k)
{
    return numOfNiceSubarray_SW_helper(arr, k) - numOfNiceSubarray_SW_helper(arr, k - 1);
}

int main()
{

    vector<int> arr = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;

    int ans1 = numOfNiceSubarray_BF(arr, k);
    int ans2 = numOfNiceSubarray_SW(arr, k);

    cout << "Ans1: " << ans1 << endl;
    cout << "Ans2: " << ans2 << endl;

    return 0;
}